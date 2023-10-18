#ifndef NEWUSER_H
#define NEWUSER_H

#include <QDialog>
#include <QFile>
#include<QDir>
#include<QTextStream>
#include <QString>
#include <QMessageBox>

namespace Ui {
class newUser;
}

class newUser : public QDialog
{
    Q_OBJECT

public:
    explicit newUser(QWidget *parent = nullptr);
    ~newUser();

private slots:
    void on_pushButton_Login_clicked();

private:
    Ui::newUser *ui;
};

#endif // NEWUSER_H
