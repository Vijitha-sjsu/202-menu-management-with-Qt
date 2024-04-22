#ifndef MENUITEM_H
#define MENUITEM_H

#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>
#include "Enums.h"
#include <string>
#include <vector>

class MenuItem {
public:
    MenuItem(const std::string& name, double price, const std::string& imagePath,
             const std::string& description, Category category,
             const std::vector<DietaryRestriction>& dietaryRestrictions, Availability availability,
             const boost::uuids::uuid& id = boost::uuids::random_generator()());

    std::string getName() const;
    double getPrice() const;
    std::string getImagePath() const;
    std::string getDescription() const;
    Category getCategory() const;
    std::vector<DietaryRestriction> getDietaryRestrictions() const;
    Availability getAvailability() const;
    boost::uuids::uuid getId() const;

private:
    boost::uuids::uuid id;
    std::string name;
    double price;
    std::string imagePath;
    std::string description;
    Category category;
    std::vector<DietaryRestriction> dietaryRestrictions;
    Availability availability;
};

#endif // MENUITEM_H
