#include <QtWidgets>
#include <QPalette>

class ButtonCard : public QFrame
{
    Q_OBJECT

public:
    ButtonCard(const QString &text, QWidget *parent = nullptr);
    void setImage(const QPixmap &image);
    void setBackgroundColor(const QColor &color);

signals:
//    void clicked();

private slots:
    void onButtonClicked();
    void setText(const QString &text);
    QString text() const;

private:
    QLabel *imageLabel;
    QLabel *textLabel;
    QString text_;
    QColor backgroundColor;
    QPixmap image;
};



