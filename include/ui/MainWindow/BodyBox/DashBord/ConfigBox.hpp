#pragma once

#include <QWidget>
#include <QLayout>
#include <QLabel>
#include <QPushButton>
#include <QCheckBox>
#include <limits>
#include "ui/QSLabel.hpp"
#include "ui/QSCheckBox.hpp"

class ConfigBox : public QWidget{
    Q_OBJECT    
    using QWidget::QWidget;
//Attributs
protected:
    QGridLayout * glayout;
    QLabel * mode_name;
    QWidget * configs_widget;
    QGridLayout * configs_grid;
    //
    QPushButton * valid_button;
    QLabel * error_label;
    //Selection des generateur
    QSLabel * u_char_label;
    QSLabel * l_char_label;
    QSLabel * d_char_label;
    QSLabel * s_char_label;
    QSLabel * p_char_label;
    QSLabel * wdb_char_label;
    QSLabel * homo_gen_label;
    //
    QSCheckBox * u_char_check;
    QSCheckBox * l_char_check;
    QSCheckBox * d_char_check;
    QSCheckBox * s_char_check;
    QSCheckBox * p_char_check;
    QSCheckBox * wdb_char_check;
    QSCheckBox * homo_gen_check;
    //Style
    static const QString w_style;

//Methodes
public:
    /**
     * @brief Easy connected a label with is checkbox
     * @details This method allow interconnect a label a a checkbox
     *          like when the label is clicked, the state of the checkbox change
     * @param[in] label The label
     * @param[in] check The checkbox 
     * @note If the one this the parameter in the function is null,
     *       the operation will be abort and nothing append
     */
    void connect_label_to_check(QSLabel *label, QSCheckBox *check);

    /**
     * @brief Change the state on the validation button
     * @details This method allow to control the state of the validation button of a `ConfigBox`
     * @param[in] state The new state of the button
     */
    void chang_valid_bt_state(bool state){ valid_button->setEnabled(state);}

    /**
     * @brief Get the state of validation button
     * @details This method provide to get the present state of the validation button
     * @return True if the button is `Enable` and false if not
     */
    bool get_valid_bt_state() const { return valid_button->isEnabled();}

public:
    ConfigBox(QWidget *parent = nullptr);
    //Get checkbox state
    bool get_u_char_check_state()const{return u_char_check->checkState(); }
    bool get_l_char_check_state()const{return l_char_check->checkState(); }
    bool get_d_char_check_state()const{return d_char_check->checkState(); }
    bool get_s_char_check_state()const{return s_char_check->checkState(); }
    bool get_p_char_check_state()const{return p_char_check->checkState(); }
    bool get_wdb_char_check_state()const{return wdb_char_check->checkState(); }
    bool get_homo_gen_check_state()const{return homo_gen_check->checkState(); } 

    //Setter of checkbox
    void change_u_char_check_state(bool state) {u_char_check->setCheckState(state ? Qt::CheckState::Checked : Qt::CheckState::Unchecked); }
    void change_l_char_check_state(bool state) {l_char_check->setCheckState(state ? Qt::CheckState::Checked : Qt::CheckState::Unchecked); }
    void change_d_char_check_state(bool state) {d_char_check->setCheckState(state ? Qt::CheckState::Checked : Qt::CheckState::Unchecked); }
    void change_s_char_check_state(bool state) {s_char_check->setCheckState(state ? Qt::CheckState::Checked : Qt::CheckState::Unchecked); }
    void change_p_char_check_state(bool state) {p_char_check->setCheckState(state ? Qt::CheckState::Checked : Qt::CheckState::Unchecked); }
    void change_wdb_char_check_state(bool state) {wdb_char_check->setCheckState(state ? Qt::CheckState::Checked : Qt::CheckState::Unchecked); }
    void change_homo_gen_check_state(bool state) {homo_gen_check->setCheckState(state ? Qt::CheckState::Checked : Qt::CheckState::Unchecked); } 
    
    //Get the enable checkbox
    QWidgetList get_enabled_generators();

    //
    /**
     * @brief Display an error
     * @details This methodes allow to display an error occured
     * @param[in] error The Error to show
     */
    void show_errors(const QString &error);
    void hide_errors();

    //
signals:
    void generate_bt_clicked(ConfigBox *);
    void config_change(ConfigBox *);
};
