// MenuListModel.cpp
#include "MenuListModel.h"

MenuListModel::MenuListModel(Menu* menu, QObject* parent)
    : QAbstractListModel(parent), menu(menu) {
    // The constructor is now correctly implemented and should not give redefinition error
}

int MenuListModel::rowCount(const QModelIndex& parent) const {
    if (parent.isValid())
        return 0;
    return menu->getMenuItems().size();
}

QVariant MenuListModel::data(const QModelIndex& index, int role) const {
    if (!index.isValid() || index.row() >= rowCount() || role != Qt::DisplayRole)
        return QVariant();

    const MenuItem& item = menu->getMenuItems().at(index.row());
    return QString::fromStdString(item.getName() + " - $" + std::to_string(item.getPrice()));
}
