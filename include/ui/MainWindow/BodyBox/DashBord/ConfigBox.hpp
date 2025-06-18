#pragma once

#include <QWidget>
#include <QLayout>
#include <QLabel>
#include <QPushButton>
#include <QCheckBox>
#include <limits>
#include "ui/QSLabel.hpp"

class ConfigBox : public QWidget{
    Q_OBJECT    
//Attributs
protected:
    QVBoxLayout * vlayout;
    QLabel * mode_name;
    QWidget * configs_widget;
    QGridLayout * configs_grid;
    QPushButton * valid_button;
    //Selection des generateur
    QSLabel * u_char_label;
    QSLabel * l_char_label;
    QSLabel * d_char_label;
    QSLabel * s_char_label;
    QSLabel * p_char_label;
    QSLabel * wdb_char_label;
    QSLabel * homo_gen_label;
    //
    QCheckBox * u_char_check;
    QCheckBox * l_char_check;
    QCheckBox * d_char_check;
    QCheckBox * s_char_check;
    QCheckBox * p_char_check;
    QCheckBox * wdb_char_check;
    QCheckBox * homo_gen_check;

//Methodes
private:
    /**
     * @brief Easy connected a label with is checkbox
     * @details This method allow interconnect a label a a checkbox
     *          like when the label is clicked, the state of the checkbox change
     * @param[in] label The label
     * @param[in] check The checkbox 
     * @note If the one this the parameter in the function is null,
     *       the operation will be abort and nothing append
     */
    void connect_label_to_check(QSLabel *label, QCheckBox *check);

public:
    ConfigBox(QWidget *parent = nullptr);
    //Get checkbox state
    //Get State of u_char_check
    bool get_u_char_check_state()const{return u_char_check->checkState(); }
    
    //Get State of l_char_check
    bool get_l_char_check_state()const{return l_char_check->checkState(); }
    
    //Get State of d_char_check
    bool get_d_char_check_state()const{return d_char_check->checkState(); }
    
    //Get State of s_char_check
    bool get_s_char_check_state()const{return s_char_check->checkState(); }
    
    //Get State of p_char_check
    bool get_p_char_check_state()const{return p_char_check->checkState(); }
    
    //Get State of wdb_char_check
    bool get_wdb_char_check_state()const{return wdb_char_check->checkState(); }
    
    //Get State of homo_gen_check
    bool get_homo_gen_check_state()const{return homo_gen_check->checkState(); }

    //
signals:
    void generate_bt_clicked(ConfigBox *);
};