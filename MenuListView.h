#ifndef MENULISTVIEW_H
#define MENULISTVIEW_H

#include <QWidget>
#include <QListView>
#include "MenuListModel.h"
#include "Menu.h"

class MenuListView : public QWidget {
    Q_OBJECT
public:
    explicit MenuListView(QWidget *parent = nullptr);
    void setMenu(Menu* menu);
    void contextMenuEvent(QContextMenuEvent *event);
    void onAddItemClicked();

private:
    QListView* listView;
    MenuListModel* model;

signals:
    void itemDeleted(const QString &itemUuid);
    void editItemRequested(const QString &itemUuid);
    void addItemRequested();

};

#endif
