#pragma once

#include <QLayout>
#include <QWidget>
#include <QLabel>

class FooterBox : public QWidget {
//Attributs
private:
    QHBoxLayout * hblayout;
    QLabel * credits; 
    //
    static const QString w_style;
    
//Methodes
public:
    FooterBox(QWidget * parent = nullptr);

};