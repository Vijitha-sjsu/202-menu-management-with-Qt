#pragma once

#include <string>

enum class Category {
    Appetizer,
    MainCourse,
    Dessert,
    Drink,
    SideDish
};

std::string categoryToString(Category category);

enum class DietaryRestriction {
    Vegan,
    GlutenFree,
    NutFree,
    DairyFree,
    Vegetarian
};

std::string dietaryRestrictionToString(DietaryRestriction restriction);

enum class Availability {
    Available,
    OutOfStock,
    Seasonal,
    Limited
};

std::string availabilityToString(Availability availability);

Category stringToCategory(const std::string& str);

DietaryRestriction stringToDietaryRestriction(const std::string& str);

Availability stringToAvailability(const std::string& str);
