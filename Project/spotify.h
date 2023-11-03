#ifndef SPOTIFY_H
#define SPOTIFY_H

#include <QDialog>
#include <QtMultimedia>

namespace Ui {
class spotify;
}

class spotify : public QDialog
{
    Q_OBJECT

public:
    explicit spotify(QWidget *parent = nullptr);
    ~spotify();

private slots:

    void updateDuration(qint64 duration);

    void durationChanged(qint64 duration);

    void positionChanged(qint64 position);

    void on_play_button_clicked();

    void on_mute_button_clicked();

//    void on_pushButton_clicked();

    void on_volumeSlider_valueChanged(int value);

    void on_musicTimer_valueChanged(int value);

    void on_skip_ten_seconds_back_clicked();

    void on_skip_ten_seconds_foward_clicked();

private:
    Ui::spotify *ui;

    bool isPlaying = false;
    bool isMuted = false;
    qint64 PlayerDuration;

    QMediaPlayer* Player;
    QAudioOutput *audioOutput;

};

#endif // SPOTIFY_H
