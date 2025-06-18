#pragma once

#include <QLayout>
#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QSpinBox>
#include <QCheckBox>
#include "ui/MainWindow/BodyBox/DashBord/ConfigBox.hpp"

class PseudoConfig : public ConfigBox{
//Attributs
private:
    QLabel * l_pseudo_label;
    QSpinBox * l_pseudo_spin;
    //
    QLabel * n_pseudo_label;
    QSpinBox * n_pseudo_spin;
    //
    QLabel * sample_label;
    QLineEdit * sample_edit;
    //
    QLabel * r_sample_label;
    QCheckBox * r_sample_check;

//Methodes
public:
    PseudoConfig(QWidget * parent = nullptr );

};