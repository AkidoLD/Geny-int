#include "ui/MainWindow/BodyBox/DashBord/ConfigBox.hpp"

ConfigBox::ConfigBox(QWidget * parent):
    QWidget(parent),
    vlayout(new QVBoxLayout()),
    mode_name(new QLabel()),
    configs_widget(new QWidget()),
    configs_grid(new QGridLayout()),
    valid_button(new QPushButton()),
    u_char_label(new QSLabel()),
    l_char_label(new QSLabel()),
    d_char_label(new QSLabel()),
    s_char_label(new QSLabel()),
    p_char_label(new QSLabel()),
    wdb_char_label(new QSLabel()),
    homo_gen_label(new QSLabel()),
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
    
    //Connect Signals
    QObject::connect(valid_button, &QPushButton::clicked, [&](){
        emit generate_bt_clicked(this);
    });

    //Lier chaque label a sont checkbox
    connect_label_to_check(u_char_label, u_char_check);
    connect_label_to_check(l_char_label, l_char_check);
    connect_label_to_check(d_char_label, d_char_check);
    connect_label_to_check(s_char_label, s_char_check);
    connect_label_to_check(p_char_label, p_char_check);
    connect_label_to_check(wdb_char_label, wdb_char_check);
    connect_label_to_check(homo_gen_label, homo_gen_check);
    
}

void ConfigBox::connect_label_to_check(QSLabel *label, QCheckBox *check){
    if(!label || !check) return;
    QObject::connect(label, &QSLabel::slabel_clicked, [&]() mutable{
        auto state = check->checkState();
        if(!state) check->setCheckState(Qt::CheckState::Unchecked);
        else check-> setCheckState(Qt::CheckState::Checked);
    });
}