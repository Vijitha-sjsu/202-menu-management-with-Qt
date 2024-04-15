#include "MenuItemDialog.h"
#include <QVBoxLayout>
#include "Enums.h"

    MenuItemDialog::MenuItemDialog(QWidget *parent) : QDialog(parent) {
    setupUi();
    setupConnections();
    populateDietaryRestrictions();
}

void MenuItemDialog::setupUi() {
    nameEdit = new QLineEdit(this);
    priceEdit = new QDoubleSpinBox(this);
    priceEdit->setMaximum(9999.99);
    descriptionEdit = new QTextEdit(this);
    categoryCombo = new QComboBox(this);
    categoryCombo->addItems({"Appetizer", "MainCourse", "Dessert", "Drink", "SideDish"});
    dietaryRestrictionsList = new QListWidget(this);
    availabilityCombo = new QComboBox(this);
    availabilityCombo->addItems({"Available", "OutOfStock", "Seasonal", "Limited"});

    saveButton = new QPushButton(tr("Save"), this);
    cancelButton = new QPushButton(tr("Cancel"), this);

    QFormLayout *formLayout = new QFormLayout;
    formLayout->addRow(tr("Name"), nameEdit);
    formLayout->addRow(tr("Price"), priceEdit);
    formLayout->addRow(tr("Description"), descriptionEdit);
    formLayout->addRow(tr("Category"), categoryCombo);
    formLayout->addRow(tr("Dietary Restrictions"), dietaryRestrictionsList);
    formLayout->addRow(tr("Availability"), availabilityCombo);
    formLayout->addRow(saveButton, cancelButton);

    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->addLayout(formLayout);
    setLayout(mainLayout);
}

void MenuItemDialog::populateDietaryRestrictions() {
    QStringList restrictions = {"Vegan", "GlutenFree", "NutFree", "DairyFree", "Vegetarian"};
    for (const auto &restriction : restrictions) {
        QListWidgetItem *item = new QListWidgetItem(restriction, dietaryRestrictionsList);
        item->setFlags(item->flags() | Qt::ItemIsUserCheckable); // Set item as checkable
        item->setCheckState(Qt::Unchecked); // Initially set to unchecked
    }
}


void MenuItemDialog::setupConnections() {
    connect(saveButton, &QPushButton::clicked, this, &MenuItemDialog::accept);
    connect(cancelButton, &QPushButton::clicked, this, &MenuItemDialog::reject);
}

MenuItem MenuItemDialog::getItem() const {
    return MenuItem(
        nameEdit->text().toStdString(), priceEdit->value(), "", descriptionEdit->toPlainText().toStdString(),
        stringToCategory(categoryCombo->currentText().toStdString()), extractDietaryRestrictions(),
        stringToAvailability(availabilityCombo->currentText().toStdString())
        );
}

std::vector<DietaryRestriction> MenuItemDialog::extractDietaryRestrictions() const  {
    std::vector<DietaryRestriction> restrictions;
    for (int i = 0; i < dietaryRestrictionsList->count(); ++i) {
        QListWidgetItem *item = dietaryRestrictionsList->item(i);
        if (item->checkState() == Qt::Checked) {
            restrictions.push_back(static_cast<DietaryRestriction>(i));
        }
    }
    return restrictions;
}
