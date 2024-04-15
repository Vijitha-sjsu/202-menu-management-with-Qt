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

class MenuItemDialog : public QDialog {
    Q_OBJECT

public:
    explicit MenuItemDialog(QWidget *parent = nullptr);
    MenuItem getItem() const;

private:
    QLineEdit *nameEdit;
    QDoubleSpinBox *priceEdit;
    QTextEdit *descriptionEdit;
    QComboBox *categoryCombo;
    QListWidget *dietaryRestrictionsList;
    QComboBox *availabilityCombo;
    QPushButton *saveButton, *cancelButton;

    void setupUi();
    void setupConnections();
    void populateDietaryRestrictions();
    std::vector<DietaryRestriction> extractDietaryRestrictions() const;
};

#endif // MENUITEMDIALOG_H
