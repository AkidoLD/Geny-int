#pragma once

#include <QWidget>
#include <QLayout>
#include <QStackedWidget>
#include "ui/MainWindow/BodyBox/DashBord/Configs/PasswConfig.hpp"
#include "ui/MainWindow/BodyBox/DashBord/Configs/UidConfig.hpp"
#include "ui/MainWindow/BodyBox/DashBord/Configs/PseudoConfig.hpp"
#include "ui/MainWindow/BodyBox/DashBord/ResultBox.hpp"

class PasswordPack{
public:
    PasswConfig * passwConf;
    ResultBox * resultBox;
    QPushButton * displayButton;    
} ;

class UidPack{

};

class PseudoPack{

};


class DashBord : public QWidget{
//Attributs
private:
    QGridLayout * glayout;
    PasswConfig * pswConfig;
    //

//Methodes
public:
    DashBord(QWidget * parent = nullptr);

};