// MenuController.h

#ifndef MENUCONTROLLER_H
#define MENUCONTROLLER_H

#include <QObject>
#include "Menu.h"
#include "MenuItemAdapter.h"
#include "MenuListView.h"

class MenuController : public QObject {
    Q_OBJECT
public:
    explicit MenuController(QObject *parent = nullptr);

    void setMenuModel(Menu* menu);
    void setView(MenuListView* view);
    void loadMenuItemsFromFile(const QString& filename);

private:
    Menu* menuModel;
    MenuListView* menuView;
    MenuItemAdapter adapter;
};

#endif // MENUCONTROLLER_H
