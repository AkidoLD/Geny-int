#pragma once

#include <QLayout>
#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QSpinBox>
#include <QCheckBox>
#include "ui/MainWindow/BodyBox/DashBord/ConfigBox.hpp"

class UidConfig : public ConfigBox{
    Q_OBJECT
//Attributs
private:
    QLabel * n_bloc_label;
    QSpinBox * n_bloc_spin;
    //
    QLabel * l_bloc_label;
    QSpinBox * l_bloc_spin;
    //
    QLabel * n_uid_label;
    QSpinBox * n_uid_spin;
    //
    QLabel * s_bloc_label;
    QLineEdit * s_bloc_edit;
    //

//Methodes
public:
    UidConfig(QWidget * parent = nullptr);

    //Getters generation config
    size_t get_l_bloc_spin_value()const {return l_bloc_spin->value();}
    size_t get_n_bloc_spin_value()const {return n_bloc_spin->value();}
    size_t get_n_uid_spin_value() const {return n_uid_spin->value();}
    const QString get_s_bloc_edit_text() const {return s_bloc_edit->text();}
};