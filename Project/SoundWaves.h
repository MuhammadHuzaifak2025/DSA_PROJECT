#ifndef SOUNDWAVES_H
#define SOUNDWAVES_H

#include <QWidget>
#include <QPainter>
#include <QAudioOutput>

class SoundWaves : public QWidget
{
public:
    SoundWaves(QWidget *parent = nullptr);
    ~SoundWaves();

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    QAudioOutput *audioOutput;
    QTimer *timer;
    QVector<int> samples;
};

#endif // SOUNDWAVES_H
