// MenuListView.cpp
#include "MenuListView.h"
#include <QVBoxLayout>
#include <QLabel>

MenuListView::MenuListView(QWidget *parent) : QWidget(parent), listView(new QListView(this)) {
    QVBoxLayout* layout = new QVBoxLayout(this);
    QLabel* label = new QLabel(tr("Menu Management"), this);
    layout->addWidget(label);

    // Assume you have an instance of your Menu model
    Menu* menu = new Menu();  // This would be replaced with your actual Menu instance
    model = new MenuListModel(menu, this);
    listView->setModel(model);

    layout->addWidget(listView);
    setLayout(layout);
}

void MenuListView::setMenu(Menu* menu) {
    if (!menu) return;

    MenuListModel* model = new MenuListModel(menu, this);
    listView->setModel(model);
}
