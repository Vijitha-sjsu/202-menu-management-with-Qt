// Menu.cpp
#include "Menu.h"

void Menu::addItem(const MenuItem& item) {
    items.push_back(item);
}

bool Menu::removeItem(const std::string& name) {
    auto it = std::find_if(items.begin(), items.end(), [&](const MenuItem& item) {
        return item.getName() == name;
    });
    if (it != items.end()) {
        items.erase(it);
        return true;
    }
    return false;
}

const std::vector<MenuItem>& Menu::getMenuItems() const {
    return items;
}

std::vector<MenuItem>::const_iterator Menu::findItem(const std::string& name) const {
    return std::find_if(items.begin(), items.end(), [&](const MenuItem& item) {
        return item.getName() == name;
    });
}
