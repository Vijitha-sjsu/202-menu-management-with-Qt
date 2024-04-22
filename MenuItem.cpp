#include "MenuItem.h"

MenuItem::MenuItem(const std::string& name, double price, const std::string& imagePath,
                   const std::string& description, Category category,
                   const std::vector<DietaryRestriction>& dietaryRestrictions, Availability availability,
                   const boost::uuids::uuid& id)
    : id(id), name(name), price(price), imagePath(imagePath), description(description),
    category(category), dietaryRestrictions(dietaryRestrictions), availability(availability) {}

std::string MenuItem::getName() const {
    return name;
}

double MenuItem::getPrice() const {
    return price;
}

std::string MenuItem::getImagePath() const {
    return imagePath;
}

std::string MenuItem::getDescription() const {
    return description;
}

Category MenuItem::getCategory() const {
    return category;
}

std::vector<DietaryRestriction> MenuItem::getDietaryRestrictions() const {
    return dietaryRestrictions;
}

Availability MenuItem::getAvailability() const {
    return availability;
}

boost::uuids::uuid MenuItem::getId() const {
    return id;
}
