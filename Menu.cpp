#include "Menu.h"

void Menu::addItem(const MenuItem& item) {
    items.push_back(item);
}

bool Menu::removeItem(const boost::uuids::uuid& id) {
    auto it = std::find_if(items.begin(), items.end(), [&](const MenuItem& item) {
        return item.getId() == id;
    });
    if (it != items.end()) {
        items.erase(it);
        return true;
    }
    return false;
}

bool Menu::updateItem(const MenuItem& updatedItem) {
    auto it = findItemById(updatedItem.getId());
    if (it != items.end()) {
        *it = updatedItem;
        return true;
    }
    return false;
}

const std::vector<MenuItem>& Menu::getMenuItems() const {
    return items;
}

std::vector<MenuItem>::iterator Menu::findItemById(const boost::uuids::uuid& id) {
    return std::find_if(items.begin(), items.end(), [&](const MenuItem& item) {
        return item.getId() == id;
    });
}
