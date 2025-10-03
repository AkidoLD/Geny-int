#pragma once

#include <QLayout>
#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QSpinBox>
#include <QCheckBox>
#include "ui/MainWindow/BodyBox/DashBord/ConfigBox.hpp"
#include "ui/QSCheckBox.hpp"
#include "ui/QSLabel.hpp"

class PseudoConfig : public ConfigBox{
    Q_OBJECT
    using ConfigBox::ConfigBox;
//Attributs
private:
    QSLabel * l_pseudo_max_label;
    QSpinBox * l_pseudo_max_spin;
    //
    QSLabel * l_pseudo_min_label;
    QSpinBox * l_pseudo_min_spin;
    //
    QSLabel * n_pseudo_label;
    QSpinBox * n_pseudo_spin;
    //
    QSLabel * sample_label;
    QLineEdit * sample_edit;
    //
    QSLabel * r_sample_label;
    QSCheckBox * r_sample_check;

//Methodes
public:
    PseudoConfig(QWidget * parent = nullptr );

    //Getter Configs
    size_t get_l_pseudo_max_spin_value () const { return l_pseudo_max_spin->value();}
    size_t get_l_pseudo_min_spin_value () const { return l_pseudo_min_spin->value();}
    size_t get_n_pseudo_spin_value () const { return n_pseudo_spin->value();}
    const QString get_sample_edit_text () const { return sample_edit->text();}
    bool get_r_sample_check_state () const { return r_sample_check->checkState();}

};