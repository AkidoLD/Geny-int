#pragma once

#include <QLabel>

class QSLabel : public QLabel{
    Q_OBJECT
public :
    using QLabel::QLabel;

protected:
    void mousePressEvent(QMouseEvent *event) override{
        emit slabel_clicked();
        qDebug() << "Test clique sur label";
        QLabel::mousePressEvent(event);
    }

signals:
    void slabel_clicked();
};
