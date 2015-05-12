#ifndef CUSTOMLABEL_H
#define CUSTOMLABEL_H

#include <QWidget>
#include <QLabel>
#include <QPaintEvent>
#include <QPainter>
#include <QString>

class CustomLabel : public QLabel
{
    Q_OBJECT
    QString imagePathBackground;
    QString imagePathText;
public:
    explicit CustomLabel(QWidget *parent = 0);
    CustomLabel(int height, int width, QWidget *parent = 0);
    ~CustomLabel();

    QString getImagePathText() const;
    void setImagePathText(const QString &value);

    QString getImagePathBackground() const;
    void setImagePathBackground(const QString &value);

    void paintEvent(QPaintEvent* pe);

signals:

public slots:
};

#endif // CUSTOMLABEL_H
