/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *lineEdit_userName;
    QLineEdit *lineEdit_userPass;
    QPushButton *pushButton_Login;
    QPushButton *pushButton_newUser;
    QPushButton *pushButton;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1280, 720);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(0, 0, 1280, 720));
        label->setStyleSheet(QString::fromUtf8("background-image: url(\":/images/background.png\");"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(570, 180, 211, 91));
        label_2->setStyleSheet(QString::fromUtf8("color: #FFF;\n"
"\n"
"font-family: Inter;\n"
"font-size: 63px;\n"
"font-style: normal;\n"
"font-weight: 700;\n"
"line-height: normal;"));
        lineEdit_userName = new QLineEdit(centralwidget);
        lineEdit_userName->setObjectName("lineEdit_userName");
        lineEdit_userName->setGeometry(QRect(500, 280, 340, 61));
        lineEdit_userName->setStyleSheet(QString::fromUtf8("border-radius: 30px;\n"
"background: #1A7290;\n"
"color: #FFF;\n"
"\n"
"text-align: center;\n"
"font-family: Inter;\n"
"font-size: 22px;\n"
"font-style: normal;\n"
"font-weight: 600;\n"
"line-height: normal;"));
        lineEdit_userName->setAlignment(Qt::AlignCenter);
        lineEdit_userPass = new QLineEdit(centralwidget);
        lineEdit_userPass->setObjectName("lineEdit_userPass");
        lineEdit_userPass->setGeometry(QRect(500, 360, 340, 61));
        lineEdit_userPass->setStyleSheet(QString::fromUtf8("border-radius: 30px;\n"
"background: #1A7290;\n"
"color: #FFF;\n"
"\n"
"text-align: center;\n"
"font-family: Inter;\n"
"font-size: 22px;\n"
"font-style: normal;\n"
"font-weight: 600;\n"
"line-height: normal;"));
        lineEdit_userPass->setAlignment(Qt::AlignCenter);
        pushButton_Login = new QPushButton(centralwidget);
        pushButton_Login->setObjectName("pushButton_Login");
        pushButton_Login->setGeometry(QRect(570, 480, 200, 70));
        pushButton_Login->setStyleSheet(QString::fromUtf8("border-radius: 35px;\n"
"background: #D13526;\n"
"color: #FFF;\n"
"\n"
"text-align: center;\n"
"font-family: Inter;\n"
"font-size: 35px;\n"
"font-style: normal;\n"
"font-weight: 600;\n"
"line-height: normal;\n"
""));
        pushButton_newUser = new QPushButton(centralwidget);
        pushButton_newUser->setObjectName("pushButton_newUser");
        pushButton_newUser->setGeometry(QRect(544, 440, 251, 31));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(630, 130, 131, 21));
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QString());
        label_2->setText(QCoreApplication::translate("MainWindow", "LOGIN", nullptr));
        lineEdit_userName->setPlaceholderText(QCoreApplication::translate("MainWindow", "Enter Username", nullptr));
        lineEdit_userPass->setPlaceholderText(QCoreApplication::translate("MainWindow", "Enter Password", nullptr));
        pushButton_Login->setText(QCoreApplication::translate("MainWindow", "SUBMIT", nullptr));
        pushButton_newUser->setText(QCoreApplication::translate("MainWindow", "Create A New Account!", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Login As Admin", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
