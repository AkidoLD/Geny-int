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
    Q_OBJECT
    using ConfigBox::ConfigBox;    
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

    //Get configs
    size_t get_lenght_spin_value()const {return lenght_spin->value();}
    size_t get_number_spin_value()const {return number_spin->value();}

    //Getters
};