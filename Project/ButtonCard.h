#include <QtWidgets>
#include <QPalette>

class ButtonCard : public QFrame
{
    Q_OBJECT

public:
    ButtonCard(const QString &text, QWidget *parent = nullptr);
    void setImage(const QPixmap &image);
    void setBackgroundColor(const QColor &color);

    void mousePressEvent(QMouseEvent *event){

        if (event->button() == Qt::RightButton) {
            QMenu menu(this);

            QAction *action1 = menu.addAction("Add To Queue");
            QAction *action2 = menu.addAction("Add To Playlist");

            connect(action1, &QAction::triggered, this, &ButtonCard::addToQueue);
            connect(action2, &QAction::triggered, this, &ButtonCard::addToPlaylist);
            menu.setStyleSheet("");
            menu.setStyleSheet("QMenu {\n""    background-color: rgba(255,255,255,50);\n""    border: 1px solid black;\n"
                               "    font-family: Arial, sans-serif;\n"
                               "    font-size: 12px;\n"
                               "    border-radius: 1px;\n"
                               "}\n"
                               "QMenu::item {\n"
                               "    padding: 5px;\n"
                               "    margin: 2px;\n"
                               "}\n"

                               "QMenu::item:hover {\n"
                               "    background-color: #e0e0e0;\n"
                               "}\n"

                               "QMenu::item:selected {\n"
                               "    background-color: #d0d0d0;\n"
                               "}\n");
            menu.exec(event->globalPosition().toPoint());
        }
        else {
            QFrame::mousePressEvent(event);
        }
    }


    void setPlay(const QPixmap &image){

        QPixmap xd = image;
        playButton->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        playButton->setFixedSize(40,40);
        //        playButton->setMinimumSize(35,35);
        playButton->setStyleSheet("background-color: transparent; border: none; image: url(:icons/playbtn.png);");
        //        playButton->setScaledContents(true);

    }

    void addToPlaylist(){
        emit addToPlaylistRequested(textLabel->text());
    }

    void addToQueue(){
        addToQueueRequested(textLabel->text());
    }

signals:
    void Clicked(const QString &text);
    void addToPlaylistRequested(const QString &text);
    void addToQueueRequested(const QString &text);

protected:
    //    void enterEvent(QEvent *event);

    //    void leaveEvent(QEvent *event);
    //    void mousePress(QMouseEvent *event){
    //        QFrame::mousePressEvent(event);
    //        emit clicked();
    //    }


private slots:
    void on_playButton_clicked();
    void setText(const QString &text);
    QString text() const;


private:
    QLabel *imageLabel;
    QLabel *textLabel;
    QString text_;
    QColor backgroundColor;
    QPixmap image;
    QToolBox *toolBox;
    QPixmap play;
    QPushButton *playButton;
    bool isHovered;
};



