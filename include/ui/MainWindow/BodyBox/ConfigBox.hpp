#pragma once

#include <QWidget>
#include <QLayout>
#include <QLabel>
#include <QPushButton>

class ConfigBox : public QWidget{
//Attributs
protected:
    QVBoxLayout * vlayout;
    QLabel * mode_name;
    QGridLayout * configs;
    QPushButton * valid_button;

//Methodes
public:
    ConfigBox(const QString &mode_name_text, QWidget *parent = nullptr);

};