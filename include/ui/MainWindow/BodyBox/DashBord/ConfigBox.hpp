#pragma once

#include <QWidget>
#include <QLayout>
#include <QLabel>
#include <QPushButton>
#include <QCheckBox>
#include <limits>

class ConfigBox : public QWidget{
//Attributs
protected:
    QVBoxLayout * vlayout;
    QLabel * mode_name;
    QWidget * configs_widget;
    QGridLayout * configs_grid;
    QPushButton * valid_button;
    //Selection des generateur
    QLabel * u_char_label;
    QLabel * l_char_label;
    QLabel * d_char_label;
    QLabel * s_char_label;
    QLabel * p_char_label;
    QLabel * wdb_char_label;
    QLabel * homo_gen_label;
    //
    QCheckBox * u_char_check;
    QCheckBox * l_char_check;
    QCheckBox * d_char_check;
    QCheckBox * s_char_check;
    QCheckBox * p_char_check;
    QCheckBox * wdb_char_check;
    QCheckBox * homo_gen_check;

//Methodes
public:
    ConfigBox(QWidget *parent = nullptr);

};