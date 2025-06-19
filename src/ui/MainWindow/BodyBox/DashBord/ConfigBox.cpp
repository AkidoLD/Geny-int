#include "ui/MainWindow/BodyBox/DashBord/ConfigBox.hpp"

ConfigBox::ConfigBox(QWidget * parent):
    QWidget(parent),
    glayout(new QGridLayout()),
    mode_name(new QLabel()),
    configs_widget(new QWidget()),
    configs_grid(new QGridLayout()),
    valid_button(new QPushButton()),
    error_label(new QLabel()),
    u_char_label(new QSLabel()),
    l_char_label(new QSLabel()),
    d_char_label(new QSLabel()),
    s_char_label(new QSLabel()),
    p_char_label(new QSLabel()),
    wdb_char_label(new QSLabel()),
    homo_gen_label(new QSLabel()),
    u_char_check(new QSCheckBox()),
    l_char_check(new QSCheckBox()),
    d_char_check(new QSCheckBox()),
    s_char_check(new QSCheckBox()),
    p_char_check(new QSCheckBox()),
    wdb_char_check(new QSCheckBox()),
    homo_gen_check(new QSCheckBox())
{
    this->setObjectName("config-box");
    this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    this->setLayout(glayout);
    this->setStyleSheet(w_style);
    //

    glayout->setObjectName("config-box-layout");
    glayout->addWidget(mode_name, 0, 0, 1, 2,Qt::AlignHCenter | Qt::AlignTop);
    glayout->addWidget(configs_widget, 1, 0, 1, 2, Qt::AlignTop);
    glayout->addWidget(error_label, 2, 0, 1, 1, Qt::AlignLeft | Qt::AlignTop);
    glayout->addWidget(valid_button, 2, 1, 1, 1, Qt::AlignRight | Qt::AlignTop);
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
    error_label->setObjectName("conf-box-error-label");
    error_label->hide();
    error_label->setText("Error Occured");
    //
    valid_button->setObjectName("config-box-valid-button");
    valid_button->setText("Generer");
    valid_button->setFixedSize(150, 46);
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
    //
    QObject::connect(u_char_check, &QSCheckBox::stateChanged, [&](){
        emit config_change(this);
    });
    QObject::connect(l_char_check, &QSCheckBox::stateChanged, [&](){
        emit config_change(this);
    });
    QObject::connect(d_char_check, &QSCheckBox::stateChanged, [&](){
        emit config_change(this);
    });
    QObject::connect(s_char_check, &QSCheckBox::stateChanged, [&](){
        emit config_change(this);
    });
    QObject::connect(p_char_check, &QSCheckBox::stateChanged, [&](){
        emit config_change(this);
    });
    QObject::connect(wdb_char_check, &QSCheckBox::stateChanged, [&](){
        emit config_change(this);
    });
    QObject::connect(homo_gen_check, &QSCheckBox::stateChanged, [&](){
        emit config_change(this);
    });
    //
}

void ConfigBox::connect_label_to_check(QSLabel *label, QSCheckBox *check){
    if(!label || !check) return;
    QObject::connect(label, &QSLabel::slabel_clicked, check, &QSCheckBox::nextCheckState);
}

const QString  ConfigBox::w_style{R"(
        #config-box{
            background-color: rgb(255, 255, 255);
            margin 0; 
            color: black;
            padding: 0;
        }
        
        #config-box * {
            color: black;
        }

        #config-box-layout{
            margin: 0;
            padding: 0;
        }

        #config-box-configs-widget QLabel{
            color: black;
            font-size: 13pt;
            margin: 2px 0;
            font-family: 'cmr10','Cantarell';
        }

        #config-box-configs-widget QSpinBox, QCheckBox{
            color: black;
            background-color:rgb(243, 243, 243);
            font-size: 14pt;
            margin: 2px 0;
            font-family: 'cmr10','Cantarell';
        }

        #config-box-valid-button{
            background-color: #33FF33;
            border: 4px solid black;
            border-radius: 23px;
            color: black;
            font-size: 18pt;
            font-weight: 700;
            font-family: 'iekie Sweet';
        }

        #config-box-mode-label{
            color: black;
            font-size: 24pt;
            font-weight: 800;
            margin: 0 20px;
            font-family: 'URW Gothic';
        }

        #config-box-configs-widget{
            background-color: white;
            padding: 50px;
            border-radius: 15px;
            border: 2px solid black;
        }

        #config-box QLineEdit{
            background-color:rgb(243, 243, 243);
            font-family: 'cmr10','Cantarell';
            font-size: 13pt;
        }
        
        #conf-box-error-label{
            color: red;
            font-weight: 800;
            margin: 20px 5px;
            font-family: 'cmr10','Cantarell';
            font-size: 13pt;
        }
    )"
};

QWidgetList ConfigBox::get_enabled_generators(){
    QWidgetList  check_list;
    if(u_char_check->isChecked()) check_list.append(u_char_check) ;
    if(l_char_check->isChecked()) check_list.append(l_char_check) ;
    if(d_char_check->isChecked()) check_list.append(d_char_check) ;
    if(s_char_check->isChecked()) check_list.append(s_char_check) ;
    if(p_char_check->isChecked()) check_list.append(p_char_check) ;
    //
    return check_list;
}

void ConfigBox::show_errors(const QString &error){
    if(error.isEmpty()) return;
    qDebug() << "Error Occured : " << error;
    error_label->setText(error);
    error_label->show();
}

void ConfigBox::hide_errors(){
    qDebug() << "No Error Occured !";
    error_label->hide();
}
