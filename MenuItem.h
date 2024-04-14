#pragma once
#include "Enums.h"
#include <string>
#include <vector>

class MenuItem {
private:
    std::string name;
    double price;
    std::string imagePath;
    std::string description;
    Category category;
    std::vector<DietaryRestriction> dietaryRestrictions;
    Availability availability;

public:
    MenuItem(const std::string& name, double price, const std::string& imagePath,
             const std::string& description, Category category,
             const std::vector<DietaryRestriction>& dietaryRestrictions, Availability availability);

    std::string getName() const;
    double getPrice() const;
    std::string getImagePath() const;
    std::string getDescription() const;
    Category getCategory() const;
    std::vector<DietaryRestriction> getDietaryRestrictions() const;
    Availability getAvailability() const;
};
