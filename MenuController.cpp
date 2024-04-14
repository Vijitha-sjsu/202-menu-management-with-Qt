// MenuController.cpp

#include "MenuController.h"

MenuController::MenuController(QObject *parent) : QObject(parent), menuModel(nullptr), menuView(nullptr) {}

void MenuController::setMenuModel(Menu* menu) {
    menuModel = menu;
}

void MenuController::setView(MenuListView* view) {
    menuView = view;
    connect(menuView, &MenuListView::itemDeleted, this, &MenuController::handleItemDeletion);
}

void MenuController::loadMenuItemsFromFile(const QString& filename) {
    if (menuModel != nullptr) {
        auto items = adapter.loadMenuItemsFromCSV(filename.toStdString());
        for (auto& item : items) {
            menuModel->addItem(item);
        }
        menuView->setMenu(menuModel);
    }
}

void MenuController::saveMenuItemsToFile(const QString &filename) {
    if (menuModel != nullptr) {
        adapter.saveMenuItemsToCSV(menuModel->getMenuItems(), filename.toStdString());
    }
}

void MenuController::handleItemDeletion(const QString &itemName) {
    if (menuModel) {
        menuModel->removeItem(itemName.toStdString());
        // Update the CSV file
        saveMenuItemsToFile("/Users/vijithagunta/menu-management/menuitems.csv");
    }
}
