#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "MenuListView.h"
#include "Menu.h"

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    explicit MainWindow(Menu* menu, QWidget *parent = nullptr);
private:
    MenuListView* menuListView;
};

#endif // MAINWINDOW_H
