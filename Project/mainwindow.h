#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QFile>
#include<QDir>
#include<QTextStream>
#include<QString>
#include<newuser.h>
#include<spotify.h>
#include "user.h"
#include "admin2.h"
#include <QCloseEvent>
#include<QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    bool loginUser();

private slots:
    void on_pushButton_Login_clicked();

    void on_pushButton_newUser_clicked();

    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    newUser *newWindow;
    spotify *spopify;
};



#endif // MAINWINDOW_H
