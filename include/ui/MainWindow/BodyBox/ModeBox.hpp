#pragma once

#include <QWidget>
#include <QLayout>

class ModeBox : public QWidget{
//Attributs
private:
    QVBoxLayout * vlayout;
    QWidget * mode_widget;
    QVBoxLayout * mode_layout;

//Methodes
public:
    ModeBox(QWidget * parent = nullptr);

};