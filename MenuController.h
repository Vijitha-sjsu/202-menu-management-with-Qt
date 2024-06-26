#ifndef MENUCONTROLLER_H
#define MENUCONTROLLER_H

#include <QObject>
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_io.hpp>
#include "Menu.h"
#include "MenuItemAdapter.h"
#include "MenuListView.h"

class MenuController : public QObject {
    Q_OBJECT
public:
    explicit MenuController(QObject *parent = nullptr);

public slots:
    void handleItemDeletion(const QString &itemUuid);
    void addItem();
    void editItem(const QString &itemUuid);
    void setMenuModel(Menu* menu);
    void setView(MenuListView* view);
    void loadMenuItemsFromFile(const QString& filename);

private:
    Menu* menuModel;
    MenuListView* menuView;
    MenuItemAdapter adapter;
    void saveMenuItemsToFile(const QString &filename);
    boost::uuids::string_generator uuidGen;
};

#endif // MENUCONTROLLER_H
