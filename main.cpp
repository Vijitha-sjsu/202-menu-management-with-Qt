#include <QApplication>
#include "mainwindow.h"
#include "Menu.h"
#include "MenuItem.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    Menu menu;
    // Populate the menu
    menu.addItem(MenuItem("Pizza", 9.99, "path/to/pizza.jpg", "Delicious pizza", Category::MainCourse, {DietaryRestriction::GlutenFree}, Availability::Available));
    menu.addItem(MenuItem("Burger", 11.99, "path/to/burger.jpg", "Juicy burger", Category::MainCourse, {DietaryRestriction::DairyFree}, Availability::Available));

    MainWindow mainWindow(&menu);
    mainWindow.show();
    return app.exec();
}
