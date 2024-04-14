// Menu.h
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
    const std::vector<MenuItem>& getMenuItems() const;
    std::vector<MenuItem>::const_iterator findItem(const std::string& name) const;
};

#endif // MENU_H
