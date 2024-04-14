// main.cpp

#include <QApplication>
#include "Menu.h"
#include "MenuListView.h"
#include "MenuController.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    Menu menu;
    MenuListView view;
    MenuController controller;

    controller.setMenuModel(&menu);
    controller.setView(&view);
    controller.loadMenuItemsFromFile("/Users/vijithagunta/menu-management/menuitems.csv");

    view.show();

    return app.exec();
}
