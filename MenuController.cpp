#include "MenuController.h"
#include "MenuItemDialog.h"
#include <QDebug>

MenuController::MenuController(QObject *parent)
    : QObject(parent), menuModel(nullptr), menuView(nullptr) {}

void MenuController::setMenuModel(Menu* menu) {
    menuModel = menu;
    if (menuView) {
        menuView->setMenu(menuModel);
    }
}

void MenuController::setView(MenuListView* view) {
    menuView = view;
    connect(menuView, &MenuListView::itemDeleted, this, &MenuController::handleItemDeletion);
    connect(menuView, &MenuListView::addItemRequested, this, &MenuController::addItem);
    connect(menuView, &MenuListView::editItemRequested, this, &MenuController::editItem);
    if (menuModel) {
        menuView->setMenu(menuModel);
    }
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

void MenuController::handleItemDeletion(const QString &itemUuid) {
    if (menuModel) {
        menuModel->removeItem(uuidGen(itemUuid.toStdString()));
        saveMenuItemsToFile("/Users/vijithagunta/menu-management/menuitems.csv");
    }
}

void MenuController::addItem() {
    MenuItemDialog dialog(menuView);
    if (dialog.exec() == QDialog::Accepted) {
        MenuItem newItem = dialog.getItem();
        menuModel->addItem(newItem);
        menuView->setMenu(menuModel);
        saveMenuItemsToFile("/Users/vijithagunta/menu-management/menuitems.csv");
    }
}

void MenuController::editItem(const QString &itemUuid) {
    auto& items = menuModel->getMenuItems();
    boost::uuids::uuid uuid = uuidGen(itemUuid.toStdString());
    auto itemIt = std::find_if(items.begin(), items.end(), [&](const MenuItem& item) {
        return item.getId() == uuid;
    });

    if (itemIt != items.end()) {
        MenuItemDialog dialog(menuView);
        dialog.setItem(*itemIt);
        if (dialog.exec() == QDialog::Accepted) {
            MenuItem updatedItem = dialog.getItem();
            menuModel->updateItem(updatedItem);
            saveMenuItemsToFile("/Users/vijithagunta/menu-management/menuitems.csv");
            qDebug() << "Item updated successfully.";
        }
    } else {
        qDebug() << "Item not found for editing:" << itemUuid;
    }
}
