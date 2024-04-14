// MenuItemDelegate.h
#ifndef MENUITEMDELEGATE_H
#define MENUITEMDELEGATE_H

#include <QStyledItemDelegate>

class MenuItemDelegate : public QStyledItemDelegate {
    Q_OBJECT

public:
    using QStyledItemDelegate::QStyledItemDelegate; // Inherit constructors

    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const override;
    QSize sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const override;
};

#endif // MENUITEMDELEGATE_H
