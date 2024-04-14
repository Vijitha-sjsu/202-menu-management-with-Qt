#include "MenuItemDelegate.h"
#include "MenuListModel.h"
#include <QPainter>
#include <QDebug>

void MenuItemDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const {
    painter->save();

    // Common setup
    QRect rect = option.rect;
    int padding = 5;
    int yOffset = padding;

    // Set font for the title (name)
    QFont font = painter->font();
    font.setBold(true);
    painter->setFont(font);

    // Draw the name
    QString name = index.data(MenuListModel::NameRole).toString();
    QRect nameRect = rect.adjusted(padding, yOffset, -padding, 0);
    painter->drawText(nameRect, Qt::AlignLeft, name);
    yOffset += painter->fontMetrics().height() + padding;  // Update y-offset

    // Change font for description
    font.setBold(false);
    painter->setFont(font);

    // Draw the description
    QString description = index.data(MenuListModel::DescriptionRole).toString();
    QRect descriptionRect = rect.adjusted(padding, yOffset, -padding, 0);
    painter->drawText(descriptionRect, Qt::AlignLeft, description);
    yOffset += painter->fontMetrics().height() + padding;

    // Change color for price and availability
    painter->setPen(Qt::gray);

    // Draw the price
    QString price = QString::number(index.data(MenuListModel::PriceRole).toDouble(), 'f', 2);
    QRect priceRect = rect.adjusted(padding, yOffset, -padding, 0);
    painter->drawText(priceRect, Qt::AlignLeft, "Price: $" + price);
    yOffset += painter->fontMetrics().height() + padding;

    // Draw the availability
    QString availability = index.data(MenuListModel::AvailabilityRole).toString();
    QRect availabilityRect = rect.adjusted(padding, yOffset, -padding, 0);
    painter->drawText(availabilityRect, Qt::AlignLeft, "Availability: " + availability);
    yOffset += painter->fontMetrics().height() + padding;

    // Draw the dietary restrictions
    QString restrictions = index.data(MenuListModel::DietaryRestrictionRole).toString();
    QRect restrictionRect = rect.adjusted(padding, yOffset, -padding, 0);
    painter->drawText(restrictionRect, Qt::AlignLeft, "Dietary: " + restrictions);

    painter->restore();
}

QSize MenuItemDelegate::sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) const {
    // Set up a painter to measure text height
    QPainter painter;
    QFont font = painter.font();

    // Calculate heights for name, description, price, and dietary restrictions
    font.setBold(true);
    painter.setFont(font);
    int nameHeight = painter.fontMetrics().height();

    font.setBold(false);
    painter.setFont(font);
    int descriptionHeight = painter.fontMetrics().height();

    // Assuming price and availability are the same font size
    int priceHeight = painter.fontMetrics().height();
    int availabilityHeight = painter.fontMetrics().height();

    // Calculate height for dietary restrictions, assuming it's the same font size
    int restrictionsHeight = painter.fontMetrics().height();

    // Add up all heights and padding
    int totalHeight = nameHeight + descriptionHeight + priceHeight + availabilityHeight + restrictionsHeight;
    int padding = 10; // Total padding for top and bottom
    totalHeight += padding * 5; // Add padding between each line

    return QSize(option.rect.width(), totalHeight); // Return total width and height
}

