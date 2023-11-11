#ifndef ADMIN2_H
#define ADMIN2_H

#include <QDialog>

namespace Ui {
class admin2;
}

class admin2 : public QDialog
{
    Q_OBJECT

public:
    explicit admin2(QWidget *parent = nullptr);
    ~admin2();

private:
    Ui::admin2 *ui;
};

#endif // ADMIN2_H
