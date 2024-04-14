#pragma once
#include "MenuItem.h"
#include <string>

class MenuItemAdapter {
public:
    static std::string serialize(const MenuItem& item);
    static MenuItem deserialize(const std::string& csvLine);
    static std::vector<DietaryRestriction> parseDietaryRestrictions(const std::string& restrictionsStr);
    static void saveMenuItemsToCSV(const std::vector<MenuItem>& items, const std::string& filename);
    static std::vector<MenuItem> loadMenuItemsFromCSV(const std::string& filename);
};
