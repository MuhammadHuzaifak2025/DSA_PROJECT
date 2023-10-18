/********************************************************************************
** Form generated from reading UI file 'newuser.ui'
**
** Created by: Qt User Interface Compiler version 6.5.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWUSER_H
#define UI_NEWUSER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_newUser
{
public:
    QLabel *label;
    QLabel *label_2;
    QLineEdit *lineEdit_userName;
    QLineEdit *lineEdit_email;
    QLineEdit *lineEdit_pass;
    QLineEdit *lineEdit_age;
    QPushButton *pushButton_Login;

    void setupUi(QDialog *newUser)
    {
        if (newUser->objectName().isEmpty())
            newUser->setObjectName("newUser");
        newUser->resize(1074, 669);
        label = new QLabel(newUser);
        label->setObjectName("label");
        label->setEnabled(true);
        label->setGeometry(QRect(0, 0, 1081, 671));
        label->setStyleSheet(QString::fromUtf8("background-image: url(\":/images/background.png\");"));
        label_2 = new QLabel(newUser);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(210, 50, 701, 131));
        label_2->setStyleSheet(QString::fromUtf8("color: #FFF;\n"
"\n"
"font-family: Inter;\n"
"font-size: 63px;\n"
"font-style: normal;\n"
"font-weight: 700;\n"
"line-height: normal;"));
        lineEdit_userName = new QLineEdit(newUser);
        lineEdit_userName->setObjectName("lineEdit_userName");
        lineEdit_userName->setGeometry(QRect(100, 270, 340, 61));
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
        lineEdit_email = new QLineEdit(newUser);
        lineEdit_email->setObjectName("lineEdit_email");
        lineEdit_email->setGeometry(QRect(100, 380, 340, 61));
        lineEdit_email->setStyleSheet(QString::fromUtf8("border-radius: 30px;\n"
"background: #1A7290;\n"
"color: #FFF;\n"
"\n"
"text-align: center;\n"
"font-family: Inter;\n"
"font-size: 22px;\n"
"font-style: normal;\n"
"font-weight: 600;\n"
"line-height: normal;"));
        lineEdit_email->setAlignment(Qt::AlignCenter);
        lineEdit_pass = new QLineEdit(newUser);
        lineEdit_pass->setObjectName("lineEdit_pass");
        lineEdit_pass->setGeometry(QRect(580, 270, 340, 61));
        lineEdit_pass->setStyleSheet(QString::fromUtf8("border-radius: 30px;\n"
"background: #1A7290;\n"
"color: #FFF;\n"
"\n"
"text-align: center;\n"
"font-family: Inter;\n"
"font-size: 22px;\n"
"font-style: normal;\n"
"font-weight: 600;\n"
"line-height: normal;"));
        lineEdit_pass->setAlignment(Qt::AlignCenter);
        lineEdit_age = new QLineEdit(newUser);
        lineEdit_age->setObjectName("lineEdit_age");
        lineEdit_age->setGeometry(QRect(580, 380, 340, 61));
        lineEdit_age->setStyleSheet(QString::fromUtf8("border-radius: 30px;\n"
"background: #1A7290;\n"
"color: #FFF;\n"
"\n"
"text-align: center;\n"
"font-family: Inter;\n"
"font-size: 22px;\n"
"font-style: normal;\n"
"font-weight: 600;\n"
"line-height: normal;"));
        lineEdit_age->setAlignment(Qt::AlignCenter);
        pushButton_Login = new QPushButton(newUser);
        pushButton_Login->setObjectName("pushButton_Login");
        pushButton_Login->setGeometry(QRect(380, 490, 271, 81));
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

        retranslateUi(newUser);

        QMetaObject::connectSlotsByName(newUser);
    } // setupUi

    void retranslateUi(QDialog *newUser)
    {
        newUser->setWindowTitle(QCoreApplication::translate("newUser", "Dialog", nullptr));
        label->setText(QString());
        label_2->setText(QCoreApplication::translate("newUser", "Enter User Information", nullptr));
        lineEdit_userName->setText(QString());
        lineEdit_userName->setPlaceholderText(QCoreApplication::translate("newUser", "Enter Unique Username", nullptr));
        lineEdit_email->setText(QString());
        lineEdit_email->setPlaceholderText(QCoreApplication::translate("newUser", "Enter Email Address", nullptr));
        lineEdit_pass->setText(QString());
        lineEdit_pass->setPlaceholderText(QCoreApplication::translate("newUser", "Enter Password", nullptr));
        lineEdit_age->setText(QString());
        lineEdit_age->setPlaceholderText(QCoreApplication::translate("newUser", "Enter Age(18+)", nullptr));
        pushButton_Login->setText(QCoreApplication::translate("newUser", "Create!", nullptr));
    } // retranslateUi

};

namespace Ui {
    class newUser: public Ui_newUser {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWUSER_H
