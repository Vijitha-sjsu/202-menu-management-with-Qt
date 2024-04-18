#include "MenuController.h"
#include "MenuItemDialog.h"

MenuController::MenuController(QObject *parent) : QObject(parent), menuModel(nullptr), menuView(nullptr) {}

void MenuController::setMenuModel(Menu* menu) {
    menuModel = menu;
}

void MenuController::setView(MenuListView* view) {
    menuView = view;
    connect(menuView, &MenuListView::itemDeleted, this, &MenuController::handleItemDeletion);
    connect(menuView, &MenuListView::addItemRequested, this, &MenuController::addItem);
    connect(menuView, &MenuListView::editItemRequested, this, &MenuController::editItem);
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

void MenuController::addItem() {
    MenuItemDialog dialog(menuView);
    if (dialog.exec() == QDialog::Accepted) {
        MenuItem newItem = dialog.getItem();
        menuModel->addItem(newItem);
        saveMenuItemsToFile("/Users/vijithagunta/menu-management/menuitems.csv");
    }
}

void MenuController::editItem(const QString &itemName) {
    qDebug() << "Attempting to edit item:" << itemName;
    auto& items = menuModel->getMenuItems();  // Get a reference to the items
    auto itemIt = std::find_if(items.begin(), items.end(), [&](const MenuItem& item) {
        return item.getName() == itemName.toStdString();
    });

    if (itemIt != items.end()) {
        MenuItemDialog dialog(menuView);
        dialog.setItem(*itemIt);  // Set the item's current properties to the dialog
        if (dialog.exec() == QDialog::Accepted) {
            MenuItem newItem = dialog.getItem();
            menuModel->updateItem(newItem);
            saveMenuItemsToFile("/Users/vijithagunta/menu-management/menuitems.csv");
            qDebug() << "Item updated successfully. noww";
             // Assuming you have a method to get index from iterator
        }
    } else {
        qDebug() << "Item not found for editing:" << itemName;
    }
}
