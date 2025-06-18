#include "ui/MainWindow/BodyBox/DashBord/ConfigBox.hpp"

ConfigBox::ConfigBox(QWidget * parent):
    QWidget(parent),
    vlayout(new QVBoxLayout()),
    mode_name(new QLabel()),
    configs_widget(new QWidget()),
    configs_grid(new QGridLayout()),
    valid_button(new QPushButton()),
    u_char_label(new QLabel()),
    l_char_label(new QLabel()),
    d_char_label(new QLabel()),
    s_char_label(new QLabel()),
    p_char_label(new QLabel()),
    wdb_char_label(new QLabel()),
    homo_gen_label(new QLabel()),
    u_char_check(new QCheckBox()),
    l_char_check(new QCheckBox()),
    d_char_check(new QCheckBox()),
    s_char_check(new QCheckBox()),
    p_char_check(new QCheckBox()),
    wdb_char_check(new QCheckBox()),
    homo_gen_check(new QCheckBox())
{
    this->setObjectName("config-box");
    this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    this->setLayout(vlayout);
    this->setStyleSheet(R"(
            #config-box{
                background-color: white;
                border-radius: 15px;
                margin: 0px;
                padding: 5px;
            }

            #config-box QLabel{
                color: white;
            }
        )"
    );
    //
    vlayout->setObjectName("config-box-layout");
    vlayout->addWidget(mode_name, 0, Qt::AlignLeft | Qt::AlignTop);
    vlayout->addWidget(configs_widget, 1);
    vlayout->addWidget(valid_button, 0, Qt::AlignRight | Qt::AlignBottom);
    //
    mode_name->setObjectName("config-box-mode-label");
    mode_name->setText("Non configure");
    //
    configs_widget->setObjectName("config-box-configs-widget");
    configs_widget->setLayout(configs_grid);
    configs_widget->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    //
    configs_grid->setObjectName("config-box-configs-layout");
    configs_grid->setSpacing(5);
    //
    valid_button->setObjectName("config-box-valid-button");
    valid_button->setText("Generer");
    //
    u_char_label->setText("Caracteres Aphabetiques Maj :");
    l_char_label->setText("Caracteres Aphabetiques Min :");
    d_char_label->setText("Caracteres Numeriques :");
    s_char_label->setText("Caracteres Speciaux :");
    p_char_label->setText("Caracteres de ponctuation : ");
    wdb_char_label->setText("Utiliser la base de mot :");
    homo_gen_label->setText("Generation Homogene :");
}