#ifndef MENULISTVIEW_H
#define MENULISTVIEW_H

#include <QWidget>
#include <QListView>
#include "MenuListModel.h"
#include "Menu.h"  // Ensure Menu is included

class MenuListView : public QWidget {
    Q_OBJECT
public:
    explicit MenuListView(QWidget *parent = nullptr);
    void setMenu(Menu* menu);  // Method to set the menu

private:
    QListView* listView;
    MenuListModel* model;  // This will be initialized with the menu
};

#endif // MENULISTVIEW_H
