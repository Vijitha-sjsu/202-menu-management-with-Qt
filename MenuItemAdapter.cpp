#include "MenuItemAdapter.h"
#include "Enums.h"
#include <sstream>
#include <iterator>
#include <vector>
#include <stdexcept>
#include <iostream>
#include <fstream>
#include <boost/uuid/uuid_io.hpp>
#include <boost/uuid/string_generator.hpp>

std::string MenuItemAdapter::serialize(const MenuItem& item) {
    std::ostringstream oss;
    oss << boost::uuids::to_string(item.getId()) << ","
        << item.getName() << "," << item.getPrice() << ","
        << item.getImagePath() << "," << item.getDescription() << ","
        << categoryToString(item.getCategory()) << ",\"";

    // Joining dietary restrictions with a semicolon
    auto restrictions = item.getDietaryRestrictions();
    for (auto it = restrictions.begin(); it != restrictions.end(); ++it) {
        oss << dietaryRestrictionToString(*it);
        if (std::next(it) != restrictions.end())
            oss << ";";
    }

    oss << "\"," << availabilityToString(item.getAvailability());
    return oss.str();
}

MenuItem MenuItemAdapter::deserialize(const std::string& csvLine) {
    std::istringstream ss(csvLine);
    std::string segment;
    std::vector<std::string> seglist;

    while (std::getline(ss, segment, ',')) {
        seglist.push_back(segment);
    }

    if (seglist.size() != 8) throw std::runtime_error("CSV format error");

    boost::uuids::string_generator gen;
    boost::uuids::uuid uuid = gen(seglist[0]);
    std::string name = seglist[1];
    double price = std::stod(seglist[2]);
    std::string imagePath = seglist[3];
    std::string description = seglist[4];
    Category category = stringToCategory(seglist[5]);
    std::vector<DietaryRestriction> dietaryRestrictions = parseDietaryRestrictions(seglist[6].substr(1, seglist[6].length() - 2));
    Availability availability = stringToAvailability(seglist[7]);

    return MenuItem(name, price, imagePath, description, category, dietaryRestrictions, availability, uuid);
}

std::vector<DietaryRestriction> MenuItemAdapter::parseDietaryRestrictions(const std::string& restrictionsStr) {
    std::vector<DietaryRestriction> restrictions;
    std::istringstream iss(restrictionsStr);
    std::string restriction;

    while (getline(iss, restriction, ';')) {
        try {
            restrictions.push_back(stringToDietaryRestriction(restriction));
        } catch (const std::runtime_error& e) {
            // Log the error and continue parsing the next restriction
            std::cerr << "Failed to parse dietary restriction: " << e.what() << ". Input was: " << restriction << std::endl;
        }
    }

    return restrictions;
}

void MenuItemAdapter::saveMenuItemsToCSV(const std::vector<MenuItem>& items, const std::string& filename) {
    std::ofstream outFile(filename, std::ios::out);
    if (!outFile.is_open()) {
        throw std::runtime_error("Failed to open file for writing: " + filename);
    }

    for (const auto& item : items) {
        outFile << MenuItemAdapter::serialize(item) << std::endl;
    }
    outFile.close();
}

std::vector<MenuItem> MenuItemAdapter::loadMenuItemsFromCSV(const std::string& filename) {
    std::vector<MenuItem> items;
    std::ifstream inFile(filename);
    std::string line;

    if (!inFile.is_open()) {
        throw std::runtime_error("Failed to open file for reading: " + filename);
    }

    while (getline(inFile, line)) {
        try {
            MenuItem item = MenuItemAdapter::deserialize(line);
            items.push_back(item);
        } catch (const std::runtime_error& e) {
            std::cerr << "Failed to parse menu item from line: " << e.what() << ". Line was: " << line << std::endl;
        }
    }
    inFile.close();
    return items;
}
