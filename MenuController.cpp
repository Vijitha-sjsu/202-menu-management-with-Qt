// MenuController.cpp

#include "MenuController.h"

MenuController::MenuController(QObject *parent) : QObject(parent), menuModel(nullptr), menuView(nullptr) {}

void MenuController::setMenuModel(Menu* menu) {
    menuModel = menu;
}

void MenuController::setView(MenuListView* view) {
    menuView = view;
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
