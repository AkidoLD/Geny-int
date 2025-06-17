#pragma once

#include <QLayout>
#include <QWidget>
#include <QLabel>

class FooterBox : public QWidget {
//Attributs
private:
    QHBoxLayout * hblayout;
    QLabel * credits; 

//Methodes
public:
    FooterBox(QWidget * parent = nullptr);

};