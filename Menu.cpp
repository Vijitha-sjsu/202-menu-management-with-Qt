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

bool Menu::updateItem(const MenuItem& updatedItem) {
    auto it = std::find_if(items.begin(), items.end(), [&](const MenuItem& item) {
        return item.getName() == updatedItem.getName();
    });
    if (it != items.end()) {
        *it = updatedItem;
        return true;
    }
    return false;
}

const std::vector<MenuItem>& Menu::getMenuItems() {
    return items;
}

std::vector<MenuItem>::iterator Menu::findItemByName(const std::string& name) {
    return std::find_if(items.begin(), items.end(), [&](const MenuItem& item) {
        return item.getName() == name;
    });
}
