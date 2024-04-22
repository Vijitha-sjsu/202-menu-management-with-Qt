// MenuItemDialog.h
#ifndef MENUITEMDIALOG_H
#define MENUITEMDIALOG_H

#include <QDialog>
#include <QLineEdit>
#include <QComboBox>
#include <QDoubleSpinBox>
#include <QTextEdit>
#include <QPushButton>
#include <QFormLayout>
#include "MenuItem.h"
#include <QListWidget>
#include <boost/uuid/uuid.hpp>

class MenuItemDialog : public QDialog {
    Q_OBJECT

public:
    explicit MenuItemDialog(QWidget *parent = nullptr);
    void setItem(const MenuItem& item);
    MenuItem getItem();
    void setDietaryRestrictions(const std::vector<DietaryRestriction>& restrictions);

private:
    QLineEdit *nameEdit;
    QDoubleSpinBox *priceEdit;
    QTextEdit *descriptionEdit;
    QComboBox *categoryCombo;
    QListWidget *dietaryRestrictionsList;
    QComboBox *availabilityCombo;
    QPushButton *saveButton, *cancelButton;
    boost::uuids::uuid currentItemUuid;

    void setupUi();
    void setupConnections();
    void populateDietaryRestrictions();
    std::vector<DietaryRestriction> extractDietaryRestrictions() const;
};

#endif // MENUITEMDIALOG_H
