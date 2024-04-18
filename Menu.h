#ifndef MENU_H
#define MENU_H

#include <vector>
#include <string>
#include "MenuItem.h"

class Menu {
private:
    std::vector<MenuItem> items;

public:
    void addItem(const MenuItem& item);
    bool removeItem(const std::string& name);
    bool updateItem(const MenuItem& updatedItem);
    const std::vector<MenuItem>& getMenuItems();
    std::vector<MenuItem>::iterator findItemByName(const std::string& name);
};

#endif
