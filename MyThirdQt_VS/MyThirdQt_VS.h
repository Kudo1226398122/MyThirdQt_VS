#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_test1.h"
class QSqlTableModel;
class test1 : public QMainWindow
{
    Q_OBJECT

public:
    test1(QWidget *parent = Q_NULLPTR);

private:
    Ui::test1Class ui;
    QSqlTableModel* model;

private slots:
    void exit_clicked();
    void show_all_clicked();
    void query_clicked();
    void add_clicked();
    void delete_clicked();
    void modify_clicked();
};
