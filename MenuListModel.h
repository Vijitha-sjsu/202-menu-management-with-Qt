// MenuListModel.h
#ifndef MENULISTMODEL_H
#define MENULISTMODEL_H

#include <QAbstractListModel>
#include "Menu.h"

class MenuListModel : public QAbstractListModel {
    Q_OBJECT

public:
    explicit MenuListModel(Menu* menu, QObject* parent = nullptr);

    // Overrides from QAbstractListModel
    int rowCount(const QModelIndex& parent = QModelIndex()) const override;
    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;

    enum MenuItemRoles {
        NameRole = Qt::UserRole + 1,
        PriceRole,
        DescriptionRole,
        AvailabilityRole,
        DietaryRestrictionRole,
    };
    Q_ENUM(MenuItemRoles)

private:
    Menu* menu;
    QString dietaryRestrictionsToString(const std::vector<DietaryRestriction>& restrictions) const;
};

#endif // MENULISTMODEL_H
