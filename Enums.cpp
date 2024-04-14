#include "Enums.h"
#include <stdexcept>

std::string categoryToString(Category category) {
    switch (category) {
    case Category::Appetizer:  return "Appetizer";
    case Category::MainCourse: return "MainCourse";
    case Category::Dessert:    return "Dessert";
    case Category::Drink:      return "Drink";
    case Category::SideDish:   return "SideDish";
    default:                   return "Unknown";
    }
}

std::string dietaryRestrictionToString(DietaryRestriction restriction) {
    switch (restriction) {
    case DietaryRestriction::Vegan:      return "Vegan";
    case DietaryRestriction::GlutenFree: return "GlutenFree";
    case DietaryRestriction::NutFree:    return "NutFree";
    case DietaryRestriction::DairyFree:  return "DairyFree";
    case DietaryRestriction::Vegetarian: return "Vegetarian";
    default:                             return "Unknown";
    }
}

std::string availabilityToString(Availability availability) {
    switch (availability) {
    case Availability::Available:   return "Available";
    case Availability::OutOfStock:  return "OutOfStock";
    case Availability::Seasonal:    return "Seasonal";
    case Availability::Limited:     return "Limited";
    default:                        return "Unknown";
    }
}

Category stringToCategory(const std::string& str) {
    if (str == "Appetizer") return Category::Appetizer;
    if (str == "MainCourse") return Category::MainCourse;
    if (str == "Dessert") return Category::Dessert;
    if (str == "Drink") return Category::Drink;
    if (str == "SideDish") return Category::SideDish;
    throw std::runtime_error("Invalid category string");
}

DietaryRestriction stringToDietaryRestriction(const std::string& str) {
    if (str == "Vegan") return DietaryRestriction::Vegan;
    if (str == "GlutenFree") return DietaryRestriction::GlutenFree;
    if (str == "NutFree") return DietaryRestriction::NutFree;
    if (str == "DairyFree") return DietaryRestriction::DairyFree;
    if (str == "Vegetarian") return DietaryRestriction::Vegetarian;
    throw std::runtime_error("Invalid dietary restriction string");
}

Availability stringToAvailability(const std::string& str) {
    if (str == "Available") return Availability::Available;
    if (str == "OutOfStock") return Availability::OutOfStock;
    if (str == "Seasonal") return Availability::Seasonal;
    if (str == "Limited") return Availability::Limited;
    throw std::runtime_error("Invalid availability string");
}
