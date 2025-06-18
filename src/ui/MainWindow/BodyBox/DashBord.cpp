#include "ui/MainWindow/BodyBox/DashBord.hpp"

PasswordPack::PasswordPack(QObject * parent):
    QObject(parent),
    passwConf(new PasswConfig()),
    resultBox(new ResultBox("Liste des Mot de passe generes")),
    displayButton(new QPushButton())
{
    displayButton->setText("Passw");
    QObject::connect(displayButton, &QPushButton::clicked, [&](){
        emit display_bt_clicked(passwConf, resultBox);
    });
}

UidPack::UidPack(QObject * parent):
    QObject(parent),
    uidConf(new UidConfig()),
    resultBox(new ResultBox("Liste des identifiant generes")),
    displayButton(new QPushButton())
{
    displayButton->setText("Uid");
    QObject::connect(displayButton, &QPushButton::clicked, [&](){
        emit display_bt_clicked(uidConf, resultBox);
    });
}

PseudoPack::PseudoPack(QObject * parent):
    QObject(parent),
    pseudoConf(new PseudoConfig()),
    resultBox(new ResultBox("Liste des pseudonymes generes")),
    displayButton(new QPushButton())
{
    displayButton->setText("Pseudo");
    QObject::connect(displayButton, &QPushButton::clicked, [&](){
        emit display_bt_clicked(pseudoConf, resultBox);
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
    //  
    glayout->setObjectName("dashbord-layout");
    glayout->addWidget(configsStack, 0, 0, 1, 1,  Qt::AlignVCenter);
    glayout->addWidget(switchStackWidget, 0, 1, 1, 1, Qt::AlignVCenter);
    glayout->addWidget(resultStack, 1, 0, 1, 2);
    //
    configsStack->setObjectName("dashbord-config-stack");
    configsStack->addWidget(passwPack->passwConf);
    configsStack->addWidget(uidPack->uidConf);
    configsStack->addWidget(pseudoPack->pseudoConf);
    //
    switchStackWidget->setObjectName("dashbord-switch-widget");
    switchStackWidget->setLayout(switchStackLayout);
    switchStackWidget->setFixedWidth(65);
    switchStackWidget->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    //
    switchStackLayout->setObjectName("dashbord-switch-layout");
    switchStackLayout->setSpacing(4);
    switchStackLayout->addStretch(1);
    switchStackLayout->addWidget(passwPack->displayButton);
    switchStackLayout->addWidget(uidPack->displayButton);
    switchStackLayout->addWidget(pseudoPack->displayButton);
    switchStackLayout->addStretch(1);
    //
    resultStack->setObjectName("dashbord-result-stack");
    resultStack->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    resultStack->addWidget(passwPack->resultBox);
    resultStack->addWidget(uidPack->resultBox);
    resultStack->addWidget(pseudoPack->resultBox);
    //
    QObject::connect(passwPack, &PasswordPack::display_bt_clicked, this, &DashBord::on_display_bt_clicked);
    QObject::connect(uidPack, &UidPack::display_bt_clicked, this, &DashBord::on_display_bt_clicked);
    QObject::connect(pseudoPack, &PseudoPack::display_bt_clicked, this, &DashBord::on_display_bt_clicked);
}

void DashBord::on_display_bt_clicked(ConfigBox *config, ResultBox *result){
    configsStack->setCurrentWidget(config);
    resultStack->setCurrentWidget(result);
}