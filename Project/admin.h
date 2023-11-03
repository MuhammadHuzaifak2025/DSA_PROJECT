#ifndef ADMIN_H
#define ADMIN_H

#include <QDialog>
#include<mainwindow.h>

namespace Ui {
class Admin;
}

class Admin : public QDialog
{
    Q_OBJECT

public:
    explicit Admin(QWidget *parent = nullptr);
    ~Admin();

private slots:
    void on_Register_Song_clicked();

    void on_Save_clicked();

    void on_Back_clicked();

private:
    Ui::Admin *ui;
};

#endif // ADMIN_H
