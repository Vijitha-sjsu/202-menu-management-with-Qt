#include <QApplication>
#include "mainwindow.h"
#include "Menu.h"
#include "MenuItemAdapter.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    Menu menu;
    MenuItemAdapter adapter;

    // Load items from a CSV file
    std::vector<MenuItem> items = adapter.loadMenuItemsFromCSV("/Users/vijithagunta/menu-management/menuitems.csv");
    for (const auto& item : items) {
        menu.addItem(item);
    }

    MainWindow mainWindow(&menu);
    mainWindow.show();
    return app.exec();
}
