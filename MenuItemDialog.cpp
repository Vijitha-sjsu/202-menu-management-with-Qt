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

void MenuItemDialog::setItem(const MenuItem& item) {
    nameEdit->setText(QString::fromStdString(item.getName()));
    priceEdit->setValue(item.getPrice());
    descriptionEdit->setText(QString::fromStdString(item.getDescription()));
    categoryCombo->setCurrentText(QString::fromStdString(categoryToString(item.getCategory())));
    availabilityCombo->setCurrentText(QString::fromStdString(availabilityToString(item.getAvailability())));

    // Assuming dietary restrictions are set correctly
    for (int i = 0; i < dietaryRestrictionsList->count(); ++i) {
        QListWidgetItem *widgetItem = dietaryRestrictionsList->item(i);
        std::string restriction = widgetItem->text().toStdString();
        widgetItem->setCheckState(std::find(item.getDietaryRestrictions().begin(), item.getDietaryRestrictions().end(), stringToDietaryRestriction(restriction)) != item.getDietaryRestrictions().end() ? Qt::Checked : Qt::Unchecked);
    }
}

void MenuItemDialog::setDietaryRestrictions(const std::vector<DietaryRestriction>& restrictions) {
    for (int i = 0; i < dietaryRestrictionsList->count(); ++i) {
        QListWidgetItem *item = dietaryRestrictionsList->item(i);
        // Assume that the text of each item corresponds to the string from dietaryRestrictionToString
        QString restrictionText = QString::fromStdString(dietaryRestrictionToString(static_cast<DietaryRestriction>(i)));
        item->setCheckState(Qt::Unchecked); // Reset first
        for (const auto& restriction : restrictions) {
            if (restrictionText == QString::fromStdString(dietaryRestrictionToString(restriction))) {
                item->setCheckState(Qt::Checked);
            }
        }
    }
}
