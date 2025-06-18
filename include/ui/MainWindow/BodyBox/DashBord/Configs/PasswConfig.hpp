#pragma once

#include <QLayout>
#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QCheckBox>
#include <QSpinBox>
#include <limits>
#include "ui/MainWindow/BodyBox/DashBord/ConfigBox.hpp"

class PasswConfig : public ConfigBox{
//Attributs
private: 
    QLabel * lenght_label;
    QSpinBox * lenght_spin;
    //
    QLabel * number_label;
    QSpinBox * number_spin;
    //

//Methodes
public:
    PasswConfig(QWidget * parent = nullptr);

};