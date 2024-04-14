// MenuListView.cpp
#include "MenuListView.h"
#include "MenuItemDelegate.h"
#include <QVBoxLayout>
#include <QLabel>

MenuListView::MenuListView(QWidget *parent) : QWidget(parent), listView(new QListView(this)) {
    QVBoxLayout* layout = new QVBoxLayout(this);

    // Set up the QListView appearance with a stylesheet
    // listView->setStyleSheet(R"(
    //     QListView {
    //         show-decoration-selected: 1; // Make the selection border visible
    //         border: none; // No border around the list view
    //         background-color: white; // White background
    //         alternate-background-color: #f0f0f0; // Light gray for alternate rows
    //     }
    //     QListView::item {
    //         border-bottom: 1px solid #d0d0d0; // Separator between items
    //         padding: 10px; // Padding around items
    //         height: 60px; // Set the height for the items
    //     }
    //     QListView::item:selected {
    //         background-color: #e7e7e7; // Color when an item is selected
    //     }
    //     QListView::item:selected:!active {
    //         background-color: #e7e7e7;
    //     }
    //     QListView::item:selected:active {
    //         background-color: #d7d7d7;
    //     }
    // )");

    QLabel* label = new QLabel(tr("Menu Management"), this);
    layout->addWidget(label);

    // Assume you have an instance of your Menu model
    Menu* menu = new Menu();  // This would be replaced with your actual Menu instance
    model = new MenuListModel(menu, this);
    listView->setModel(model);

    MenuItemDelegate* delegate = new MenuItemDelegate(this);
    listView->setItemDelegate(delegate);

    layout->addWidget(listView);
    setLayout(layout);
}

void MenuListView::setMenu(Menu* menu) {
    if (!menu) return;

    MenuListModel* model = new MenuListModel(menu, this);
    listView->setModel(model);
}
