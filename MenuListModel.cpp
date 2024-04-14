// MenuListModel.cpp
#include "MenuListModel.h"
#include "Enums.h"

MenuListModel::MenuListModel(Menu* menu, QObject* parent)
    : QAbstractListModel(parent), menu(menu) {}

int MenuListModel::rowCount(const QModelIndex& parent) const {
    if (parent.isValid())
        return 0;
    return menu->getMenuItems().size();
}

QVariant MenuListModel::data(const QModelIndex& index, int role) const {
    if (!index.isValid() || index.row() >= rowCount())
        return QVariant();

    const MenuItem& item = menu->getMenuItems().at(index.row());

    switch (role) {
    case NameRole:
        return QString::fromStdString(item.getName());
    case PriceRole:
        return item.getPrice();
    case DescriptionRole:
        return QString::fromStdString(item.getDescription());
    case AvailabilityRole:
        return QString::fromStdString(availabilityToString(item.getAvailability()));
    case DietaryRestrictionRole:
        return dietaryRestrictionsToString(item.getDietaryRestrictions());
    default:
        return QVariant();
    }
}

QString MenuListModel::dietaryRestrictionsToString(const std::vector<DietaryRestriction>& restrictions) const {
    QStringList restrictionsList;
    for (const auto& restriction : restrictions) {
        restrictionsList << QString::fromStdString(dietaryRestrictionToString(restriction));
    }
    return restrictionsList.join(", ");
}
