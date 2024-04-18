// MenuListView.cpp
#include "MenuListView.h"
#include "MenuItemDelegate.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QContextMenuEvent>
#include <QMenu>
#include <QDebug>
#include <QPushButton>

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

    Menu* menu = new Menu();
    model = new MenuListModel(menu, this);
    listView->setModel(model);

    MenuItemDelegate* delegate = new MenuItemDelegate(this);
    listView->setItemDelegate(delegate);

    QPushButton *addButton = new QPushButton(tr("Add Item"), this);
    connect(addButton, &QPushButton::clicked, this, &MenuListView::onAddItemClicked);
    layout->addWidget(addButton);

    layout->addWidget(listView);
    setLayout(layout);
}

void MenuListView::setMenu(Menu* menu) {
    if (!menu) return;

    MenuListModel* model = new MenuListModel(menu, this);
    listView->setModel(model);
}

void MenuListView::contextMenuEvent(QContextMenuEvent *event) {
    QModelIndex index = listView->indexAt(event->pos());
    qDebug() << "Context menu event triggered";
    if (index.isValid()) {
        QMenu menu(this);
        QAction *deleteAction = menu.addAction("Delete Item");
        QAction *editAction = menu.addAction("Edit Item");
        QAction *selectedAction = menu.exec(mapToGlobal(event->pos()));
        QString itemName = index.data(MenuListModel::NameRole).toString();
        if (selectedAction == deleteAction) {
            qDebug() << "Attempting to delete item:" << itemName;
            emit itemDeleted(itemName);
        } else if (selectedAction == editAction) {
            qDebug() << "Attempting to edit item:" << itemName;
            emit editItemRequested(itemName);
        }
    }
}

void MenuListView::onAddItemClicked() {
    emit addItemRequested();
}
