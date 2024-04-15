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
public slots:
    void handleItemDeletion(const QString &itemName);

    void setMenuModel(Menu* menu);
    void setView(MenuListView* view);
    void loadMenuItemsFromFile(const QString& filename);
    void addItem();

private:
    Menu* menuModel;
    MenuListView* menuView;
    MenuItemAdapter adapter;
    void saveMenuItemsToFile(const QString &filename);
};

#endif // MENUCONTROLLER_H
