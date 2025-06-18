#pragma once

#include <QLayout>
#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QSpinBox>
#include <QCheckBox>
#include "ui/MainWindow/BodyBox/DashBord/ConfigBox.hpp"

class UidConfig : public ConfigBox{
//Attributs
private:
    QLabel * n_bloc_label;
    QSpinBox * n_bloc_spin;
    //
    QLabel * l_bloc_label;
    QSpinBox * l_bloc_spin;
    //
    QLabel * s_bloc_label;
    QLineEdit * s_bloc_edit;
    //

//Methodes
public:
    UidConfig(QWidget * parent = nullptr);
};