#ifndef MENU_H
#define MENU_H

#include <vector>
#include <boost/uuid/uuid.hpp>
#include "MenuItem.h"

class Menu {
public:
    void addItem(const MenuItem& item);
    bool removeItem(const boost::uuids::uuid& id);
    bool updateItem(const MenuItem& updatedItem);
    const std::vector<MenuItem>& getMenuItems() const;
    std::vector<MenuItem>::iterator findItemById(const boost::uuids::uuid& id);

private:
    std::vector<MenuItem> items;
};

#endif // MENU_H
