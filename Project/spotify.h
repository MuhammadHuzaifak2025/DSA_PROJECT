#ifndef SPOTIFY_H
#define SPOTIFY_H

#include <QDialog>

namespace Ui {
class spotify;
}

class spotify : public QDialog
{
    Q_OBJECT

public:
    explicit spotify(QWidget *parent = nullptr);
    ~spotify();

private:
    Ui::spotify *ui;
};

#endif // SPOTIFY_H
