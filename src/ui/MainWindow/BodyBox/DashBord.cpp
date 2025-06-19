#include "ui/MainWindow/BodyBox/DashBord.hpp"

PasswordPack::PasswordPack(QObject * parent):
    QObject(parent),
    passwConf(new PasswConfig()),
    resultBox(new ResultBox("Liste des Mot de passe generes")),
    displayButton(new QPushButton())
{
    displayButton->setText("Passw");
    displayButton->setFixedSize(50, 50);
    QObject::connect(displayButton, &QPushButton::clicked, [&](){
        emit display_bt_clicked(passwConf, resultBox);
    });
    //
    QObject::connect(passwConf, &ConfigBox::generate_bt_clicked, [&](ConfigBox *conf){
        emit generate_bt_clicked(conf, resultBox);
    });
    //
    QObject::connect(passwConf, &ConfigBox::config_change, [&](ConfigBox *conf){
        emit config_change(conf);
    });
}

UidPack::UidPack(QObject * parent):
    QObject(parent),
    uidConf(new UidConfig()),
    resultBox(new ResultBox("Liste des identifiant generes")),
    displayButton(new QPushButton())
{
    displayButton->setText("Uid");
    displayButton->setFixedSize(50, 50);
    QObject::connect(displayButton, &QPushButton::clicked, [&](){
        emit display_bt_clicked(uidConf, resultBox);
    });
    //
    QObject::connect(uidConf, &ConfigBox::generate_bt_clicked, [&](ConfigBox *conf){
        emit generate_bt_clicked(conf, resultBox);
    });
    //
    QObject::connect(uidConf, &ConfigBox::config_change, [&](ConfigBox *conf){
        emit config_change(conf);
    });
}

PseudoPack::PseudoPack(QObject * parent):
    QObject(parent),
    pseudoConf(new PseudoConfig()),
    resultBox(new ResultBox("Liste des pseudonymes generes")),
    displayButton(new QPushButton())
{
    displayButton->setText("Pseudo");
    displayButton->setFixedSize(50, 50);
    QObject::connect(displayButton, &QPushButton::clicked, [&](){
        emit display_bt_clicked(pseudoConf, resultBox);
    });
    //
    QObject::connect(pseudoConf, &ConfigBox::generate_bt_clicked, [&](ConfigBox *conf){
        emit generate_bt_clicked(conf, resultBox);
    });
    //
    QObject::connect(pseudoConf, &ConfigBox::config_change, [&](ConfigBox *conf){
        emit config_change(conf);
    });
}

//==================== DashBord ========================//

DashBord::DashBord(QWidget * parent):
    QWidget(parent),
    glayout(new QGridLayout()),
    configsStack(new QStackedWidget()),
    resultStack(new QStackedWidget()),
    switchStackWidget(new QWidget()),
    switchStackLayout(new QVBoxLayout()),
    passwPack(new PasswordPack()),
    uidPack(new UidPack()),
    pseudoPack(new PseudoPack())
{
    this->setObjectName("dashbord");
    this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    this->setLayout(glayout);
    this->setContentsMargins(0, 0, 0, 0);
    this->setStyleSheet(w_style);

    //  
    glayout->setObjectName("dashbord-layout");
    glayout->setContentsMargins(0, 0, 0, 0);
    glayout->addWidget(configsStack, 0, 0, 1, 1,  Qt::AlignVCenter);
    glayout->addWidget(switchStackWidget, 0, 1, 1, 1, Qt::AlignVCenter);
    glayout->addWidget(resultStack, 1, 0, 1, 2);
    //
    configsStack->setObjectName("dashbord-config-stack");
    configsStack->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    configsStack->addWidget(passwPack->passwConf);
    configsStack->addWidget(uidPack->uidConf);
    configsStack->addWidget(pseudoPack->pseudoConf);
    //
    switchStackWidget->setObjectName("dashbord-switch-widget");
    switchStackWidget->setLayout(switchStackLayout);
    switchStackWidget->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Expanding);
    //
    switchStackLayout->setObjectName("dashbord-switch-layout");
    switchStackLayout->setContentsMargins(3,30,3,30);
    switchStackLayout->setSpacing(4);
    switchStackLayout->addStretch(1);
    switchStackLayout->addWidget(passwPack->displayButton, 1, Qt::AlignCenter);
    switchStackLayout->addWidget(uidPack->displayButton, 1, Qt::AlignCenter);
    switchStackLayout->addWidget(pseudoPack->displayButton, 1, Qt::AlignCenter);
    switchStackLayout->addStretch(1);
    //
    resultStack->setObjectName("dashbord-result-stack");
    resultStack->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    resultStack->addWidget(passwPack->resultBox);
    resultStack->addWidget(uidPack->resultBox);
    resultStack->addWidget(pseudoPack->resultBox);
    
    //Signal emit lorsque le bouton de generation est clicke
    QObject::connect(passwPack, &PasswordPack::generate_bt_clicked, this, &DashBord::on_generate_signal_emit);
    QObject::connect(uidPack, &UidPack::generate_bt_clicked, this, &DashBord::on_generate_signal_emit);
    QObject::connect(pseudoPack, &PseudoPack::generate_bt_clicked, this, &DashBord::on_generate_signal_emit);
    
    //Signal emit lorsque le bouton d'affichage est clique
    QObject::connect(passwPack, &PasswordPack::display_bt_clicked, this, &DashBord::on_display_bt_clicked);
    QObject::connect(uidPack, &UidPack::display_bt_clicked, this, &DashBord::on_display_bt_clicked);
    QObject::connect(pseudoPack, &PseudoPack::display_bt_clicked, this, &DashBord::on_display_bt_clicked);
    
    //Signal emit lors que une configuration est modifier sur le dashbord
    QObject::connect(passwPack, &PasswordPack::config_change, this, &DashBord::on_change_config);
    QObject::connect(uidPack, &UidPack::config_change, this, &DashBord::on_change_config);
    QObject::connect(pseudoPack, &PseudoPack::config_change, this, &DashBord::on_change_config);
}



void DashBord::on_display_bt_clicked(ConfigBox *config, ResultBox *result){
    configsStack->setCurrentWidget(config);
    resultStack->setCurrentWidget(result);
}

void DashBord::on_generate_signal_emit(ConfigBox *conf, ResultBox *result){
    if(!conf || !result) return;
    emit generate_bt_clicked(conf, result);
}

void DashBord::on_change_config(ConfigBox *conf_box){
    if(!conf_box) return ;
    qDebug() << "Changement effectue depuis dashbord";
    emit config_change(conf_box);
}

const QString DashBord::w_style{R"(
        #dashbord {
            margin: 0px;
            padding: 0px;
        }

        #dashbord-layout{
            margin: 0px;
            padding: 0px;
        }

        #dashbord-config-stack{
            margin: 0px;
            padding: 0px;
        }

        #dashbord-switch-widget{
            margin: 0px;
            padding: 5px;
            background-color: white;
            border-radius: 15px;
            border: 2px solid rgb(0, 0, 0);
        }
        
        #dashbord-switch-widget > QPushButton{
            background-color: rgb(235, 235, 235);
            border: 2px solid black;
            border-radius: 8px;
            color: black;
        }

        #dashbord-switch-layout{
            margin: 0px;
            padding: 0px;
        }

        #dashbord-result-stack{
            margin: 0px;
            padding: 0px;
        }
    )"
};