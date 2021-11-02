/********************************************************************************
** Form generated from reading UI file 'test1.ui'
**
** Created by: Qt User Interface Compiler version 6.2.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEST1_H
#define UI_TEST1_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_test1Class
{
public:
    QWidget *centralWidget;
    QTableView *tableView;
    QPushButton *show_all_button;
    QPushButton *query_button;
    QPushButton *exit_button;
    QLabel *label;
    QTextEdit *id_textEdit;
    QLabel *label_2;
    QTextEdit *device_id_textEdit;
    QTextEdit *device_name_textEdit;
    QLabel *label_3;
    QPushButton *add_button;
    QPushButton *delete_buttton;
    QPushButton *modify_buttton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *test1Class)
    {
        if (test1Class->objectName().isEmpty())
            test1Class->setObjectName(QString::fromUtf8("test1Class"));
        test1Class->resize(1280, 720);
        centralWidget = new QWidget(test1Class);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        tableView = new QTableView(centralWidget);
        tableView->setObjectName(QString::fromUtf8("tableView"));
        tableView->setGeometry(QRect(10, 10, 771, 541));
        show_all_button = new QPushButton(centralWidget);
        show_all_button->setObjectName(QString::fromUtf8("show_all_button"));
        show_all_button->setGeometry(QRect(360, 580, 81, 51));
        QFont font;
        font.setPointSize(11);
        show_all_button->setFont(font);
        show_all_button->setCursor(QCursor(Qt::PointingHandCursor));
        query_button = new QPushButton(centralWidget);
        query_button->setObjectName(QString::fromUtf8("query_button"));
        query_button->setGeometry(QRect(900, 260, 80, 51));
        QFont font1;
        font1.setPointSize(12);
        query_button->setFont(font1);
        query_button->setCursor(QCursor(Qt::PointingHandCursor));
        exit_button = new QPushButton(centralWidget);
        exit_button->setObjectName(QString::fromUtf8("exit_button"));
        exit_button->setGeometry(QRect(1190, 610, 80, 41));
        exit_button->setFont(font1);
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(830, 60, 51, 41));
        label->setFont(font1);
        id_textEdit = new QTextEdit(centralWidget);
        id_textEdit->setObjectName(QString::fromUtf8("id_textEdit"));
        id_textEdit->setGeometry(QRect(900, 60, 241, 41));
        id_textEdit->setFont(font1);
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(830, 130, 51, 41));
        label_2->setFont(font1);
        device_id_textEdit = new QTextEdit(centralWidget);
        device_id_textEdit->setObjectName(QString::fromUtf8("device_id_textEdit"));
        device_id_textEdit->setGeometry(QRect(900, 130, 241, 41));
        device_id_textEdit->setFont(font1);
        device_name_textEdit = new QTextEdit(centralWidget);
        device_name_textEdit->setObjectName(QString::fromUtf8("device_name_textEdit"));
        device_name_textEdit->setGeometry(QRect(900, 200, 241, 41));
        device_name_textEdit->setFont(font1);
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(820, 200, 71, 41));
        label_3->setFont(font1);
        add_button = new QPushButton(centralWidget);
        add_button->setObjectName(QString::fromUtf8("add_button"));
        add_button->setGeometry(QRect(1060, 260, 80, 51));
        add_button->setFont(font1);
        add_button->setCursor(QCursor(Qt::PointingHandCursor));
        delete_buttton = new QPushButton(centralWidget);
        delete_buttton->setObjectName(QString::fromUtf8("delete_buttton"));
        delete_buttton->setGeometry(QRect(790, 410, 81, 51));
        QFont font2;
        font2.setPointSize(13);
        delete_buttton->setFont(font2);
        modify_buttton = new QPushButton(centralWidget);
        modify_buttton->setObjectName(QString::fromUtf8("modify_buttton"));
        modify_buttton->setGeometry(QRect(790, 500, 81, 51));
        modify_buttton->setFont(font2);
        test1Class->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(test1Class);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1280, 21));
        test1Class->setMenuBar(menuBar);
        mainToolBar = new QToolBar(test1Class);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        test1Class->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(test1Class);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        test1Class->setStatusBar(statusBar);

        retranslateUi(test1Class);
        QObject::connect(show_all_button, SIGNAL(clicked()), test1Class, SLOT(show_all_clicked()));
        QObject::connect(exit_button, SIGNAL(clicked()), test1Class, SLOT(exit_clicked()));
        QObject::connect(query_button, SIGNAL(clicked()), test1Class, SLOT(query_clicked()));
        QObject::connect(add_button, SIGNAL(clicked()), test1Class, SLOT(add_clicked()));
        QObject::connect(delete_buttton, SIGNAL(clicked()), test1Class, SLOT(delete_clicked()));
        QObject::connect(modify_buttton, SIGNAL(clicked()), test1Class, SLOT(modify_clicked()));

        QMetaObject::connectSlotsByName(test1Class);
    } // setupUi

    void retranslateUi(QMainWindow *test1Class)
    {
        test1Class->setWindowTitle(QCoreApplication::translate("test1Class", "test1", nullptr));
        show_all_button->setText(QCoreApplication::translate("test1Class", "\346\230\276\347\244\272\346\211\200\346\234\211", nullptr));
        query_button->setText(QCoreApplication::translate("test1Class", "\346\237\245\350\257\242", nullptr));
        exit_button->setText(QCoreApplication::translate("test1Class", "\351\200\200\345\207\272", nullptr));
        label->setText(QCoreApplication::translate("test1Class", "\350\256\260\345\275\225ID", nullptr));
        label_2->setText(QCoreApplication::translate("test1Class", "\350\256\276\345\244\207ID", nullptr));
        label_3->setText(QCoreApplication::translate("test1Class", "\350\256\276\345\244\207\345\220\215\347\247\260", nullptr));
        add_button->setText(QCoreApplication::translate("test1Class", "\346\267\273\345\212\240", nullptr));
        delete_buttton->setText(QCoreApplication::translate("test1Class", "\345\210\240\351\231\244", nullptr));
        modify_buttton->setText(QCoreApplication::translate("test1Class", "\344\277\256\346\224\271", nullptr));
    } // retranslateUi

};

namespace Ui {
    class test1Class: public Ui_test1Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEST1_H
