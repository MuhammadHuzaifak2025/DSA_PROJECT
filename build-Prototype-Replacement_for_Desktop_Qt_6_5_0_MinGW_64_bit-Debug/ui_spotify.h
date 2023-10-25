/********************************************************************************
** Form generated from reading UI file 'spotify.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SPOTIFY_H
#define UI_SPOTIFY_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>

QT_BEGIN_NAMESPACE

class Ui_spotify
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QPushButton *play_button;
    QPushButton *skip_behind_button;
    QPushButton *skip_foward_button;
    QSlider *musicTimer;
    QSlider *volumeSlider;
    QPushButton *mute_button;
    QPushButton *pushButton;
    QLabel *SongName;
    QLabel *songDuration;
    QPushButton *skip_ten_seconds_foward;
    QPushButton *skip_ten_seconds_back;

    void setupUi(QDialog *spotify)
    {
        if (spotify->objectName().isEmpty())
            spotify->setObjectName("spotify");
        spotify->resize(1269, 700);
        label = new QLabel(spotify);
        label->setObjectName("label");
        label->setGeometry(QRect(-20, 0, 1310, 720));
        label->setStyleSheet(QString::fromUtf8("image: url(:/images/background2.jpg);"));
        label_2 = new QLabel(spotify);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(270, 20, 701, 131));
        label_2->setStyleSheet(QString::fromUtf8("color: #FFF;\n"
"\n"
"font-family: Inter;\n"
"font-size: 63px;\n"
"font-style: normal;\n"
"font-weight: 700;\n"
"line-height: normal;"));
        label_2->setAlignment(Qt::AlignCenter);
        label_3 = new QLabel(spotify);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(260, 130, 701, 131));
        label_3->setStyleSheet(QString::fromUtf8("color: #FFF;\n"
"\n"
"font-family: Inter;\n"
"font-size: 63px;\n"
"font-style: normal;\n"
"font-weight: 700;\n"
"line-height: normal;"));
        label_3->setAlignment(Qt::AlignCenter);
        label_4 = new QLabel(spotify);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(10, 630, 1251, 91));
        label_4->setStyleSheet(QString::fromUtf8("background-color: black;"));
        play_button = new QPushButton(spotify);
        play_button->setObjectName("play_button");
        play_button->setGeometry(QRect(600, 640, 50, 50));
        QFont font;
        font.setPointSize(14);
        play_button->setFont(font);
        play_button->setStyleSheet(QString::fromUtf8("background-color: white;\n"
"border: 1px;\n"
"border-radius: 20px;"));
        play_button->setIconSize(QSize(30, 30));
        skip_behind_button = new QPushButton(spotify);
        skip_behind_button->setObjectName("skip_behind_button");
        skip_behind_button->setGeometry(QRect(550, 650, 30, 30));
        skip_behind_button->setStyleSheet(QString::fromUtf8("background-color: white;\n"
"border: 1px;\n"
"border-radius: 15px;"));
        skip_foward_button = new QPushButton(spotify);
        skip_foward_button->setObjectName("skip_foward_button");
        skip_foward_button->setGeometry(QRect(670, 650, 30, 30));
        skip_foward_button->setStyleSheet(QString::fromUtf8("background-color: white;\n"
"border: 1px;\n"
"border-radius: 15px;"));
        musicTimer = new QSlider(spotify);
        musicTimer->setObjectName("musicTimer");
        musicTimer->setGeometry(QRect(360, 590, 570, 22));
        musicTimer->setStyleSheet(QString::fromUtf8("QSlider::add-page:horizontal {\n"
"    background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop:0 #BBB, stop:1 #BBB);\n"
"    height: 3px;\n"
"}\n"
"\n"
"QSlider::sub-page:horizontal {\n"
"    background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop:0 #FFF, stop:1 #FFF);\n"
"    height: 3px;\n"
"}\n"
"QSlider::handle:horizontal {\n"
"    background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 #FFF, stop:1 #DDD);\n"
"    width: 3px;\n"
"    margin: 0px 0; \n"
"\n"
"}\n"
"QSlider::groove:horizontal {\n"
"    height: 3px; \n"
"    background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop:0 #BBB, stop:1 #BBB);\n"
"    margin: 0px 0;\n"
"}"));
        musicTimer->setMaximum(100);
        musicTimer->setOrientation(Qt::Horizontal);
        volumeSlider = new QSlider(spotify);
        volumeSlider->setObjectName("volumeSlider");
        volumeSlider->setGeometry(QRect(1090, 650, 160, 22));
        volumeSlider->setStyleSheet(QString::fromUtf8("QSlider::add-page:horizontal {\n"
"    background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop:0 #BBB, stop:1 #BBB);\n"
"    height: 3px;\n"
"}\n"
"\n"
"QSlider::sub-page:horizontal {\n"
"    background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop:0 #FFF, stop:1 #FFF);\n"
"    height: 3px;\n"
"}\n"
"QSlider::handle:horizontal {\n"
"    background: qlineargradient(x1:0, y1:0, x2:1, y2:1, stop:0 #FFF, stop:1 #DDD);\n"
"    width: 3px;\n"
"    margin: 0px 0; \n"
"\n"
"}\n"
"QSlider::groove:horizontal {\n"
"    height: 3px; \n"
"    background: qlineargradient(x1:0, y1:0, x2:1, y2:0, stop:0 #BBB, stop:1 #BBB);\n"
"    margin: 0px 0;\n"
"}"));
        volumeSlider->setOrientation(Qt::Horizontal);
        mute_button = new QPushButton(spotify);
        mute_button->setObjectName("mute_button");
        mute_button->setGeometry(QRect(1040, 650, 30, 30));
        mute_button->setStyleSheet(QString::fromUtf8("background-color: white;\n"
"border: 1px;\n"
"border-radius:10px;"));
        pushButton = new QPushButton(spotify);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(1100, 20, 141, 41));
        SongName = new QLabel(spotify);
        SongName->setObjectName("SongName");
        SongName->setGeometry(QRect(20, 640, 171, 71));
        SongName->setStyleSheet(QString::fromUtf8("font: 600 18pt \"Segoe UI Semibold\";\n"
"\n"
"color: #FFF;"));
        songDuration = new QLabel(spotify);
        songDuration->setObjectName("songDuration");
        songDuration->setGeometry(QRect(295, 693, 49, 16));
        songDuration->setStyleSheet(QString::fromUtf8("color:grey;"));
        songDuration->setAlignment(Qt::AlignCenter);
        skip_ten_seconds_foward = new QPushButton(spotify);
        skip_ten_seconds_foward->setObjectName("skip_ten_seconds_foward");
        skip_ten_seconds_foward->setGeometry(QRect(710, 650, 30, 30));
        skip_ten_seconds_foward->setStyleSheet(QString::fromUtf8("background-color: white;\n"
"border: 1px;\n"
"border-radius: 15px;"));
        skip_ten_seconds_back = new QPushButton(spotify);
        skip_ten_seconds_back->setObjectName("skip_ten_seconds_back");
        skip_ten_seconds_back->setGeometry(QRect(510, 650, 30, 30));
        skip_ten_seconds_back->setStyleSheet(QString::fromUtf8("background-color: white;\n"
"border: 1px;\n"
"border-radius: 15px;"));

        retranslateUi(spotify);

        QMetaObject::connectSlotsByName(spotify);
    } // setupUi

    void retranslateUi(QDialog *spotify)
    {
        spotify->setWindowTitle(QCoreApplication::translate("spotify", "Dialog", nullptr));
        label->setText(QString());
        label_2->setText(QCoreApplication::translate("spotify", "Spotify", nullptr));
        label_3->setText(QString());
        label_4->setText(QString());
        play_button->setText(QString());
        skip_behind_button->setText(QString());
        skip_foward_button->setText(QString());
        mute_button->setText(QString());
        pushButton->setText(QCoreApplication::translate("spotify", "Open File (.mp3)", nullptr));
        SongName->setText(QString());
        songDuration->setText(QString());
        skip_ten_seconds_foward->setText(QString());
        skip_ten_seconds_back->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class spotify: public Ui_spotify {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SPOTIFY_H
