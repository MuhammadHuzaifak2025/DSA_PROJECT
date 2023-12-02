#ifndef SPOTIFY_H
#define SPOTIFY_H

#include <QtWidgets>
#include <QDialog>
#include <QtMultimedia>
#include<QMessageBox>
#include <QCloseEvent>
#include <QVector>
#include "song.h"
#include "user.h"
#include <QMediaPlayer>
#include "SoundWaves.h"

namespace Ui {
class spotify;
}

class spotify : public QDialog
{
    Q_OBJECT

public:
    explicit spotify(QWidget *parent = nullptr);
    ~spotify();

protected:
    bool eventFilter(QObject *obj, QEvent *event) override;

    void keyPressEvent(QKeyEvent *event) override;

private slots:
    void handleTextFromButtonCard(const QString &text);

    void updateDuration(qint64 duration);

    void durationChanged(qint64 duration);

    void positionChanged(qint64 position);

//    void on_play_button_clicked(const QString &str);

    void on_play_button_clicked();

    void on_mute_button_clicked();

//    void on_pushButton_clicked();

    void on_volumeSlider_valueChanged(int value);

    void on_musicTimer_valueChanged(int value);

    void on_skip_ten_seconds_back_clicked();

    void on_skip_ten_seconds_foward_clicked();

    void on_pushButton_clicked();

//    void on_scrollArea_customContextMenuRequested(const QPoint &pos);

//    void on_Pages_currentChanged(int arg1);

    void on_Home_Button_clicked();

    void on_Search_Button_clicked();

    void updateSongList();

    void hideList();

    void showList();

    void handleAddToPlaylist(const QString &text);

    void handleAddToQueue(const QString &text);

    void on_mediaStateChanged(QMediaPlayer::MediaStatus status);

    void updateSliderPosition();

    void onItemClicked(QListWidgetItem *item);




private:
    Ui::spotify *ui;

    bool isPlaying = false;
    bool isMuted = false;
    qint64 PlayerDuration;
    QString listStyle;
    QListWidget* Playlist;
    QStringList suggestion;
    QStringList songs;
    QStringList playlists;
    QList<Song*> songList2;
    QList<Song*> songList;
    Song s;
    user* u;
    QVector <Song*> songQueue;

    QLabel* sName;
    QLabel* nowPlaying;
    QMediaPlayer* Player;
    QAudioOutput *audioOutput;
    void closeEvent(QCloseEvent *event);
    void deleteAllFilesInDirectory(const QString &directoryPath);

};

#endif // SPOTIFY_H
