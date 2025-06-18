#pragma once

#include <QWidget>
#include <QLayout>
#include <QStackedWidget>
#include "ui/MainWindow/BodyBox/DashBord/Configs/PasswConfig.hpp"
#include "ui/MainWindow/BodyBox/DashBord/Configs/UidConfig.hpp"
#include "ui/MainWindow/BodyBox/DashBord/Configs/PseudoConfig.hpp"
#include "ui/MainWindow/BodyBox/DashBord/ResultBox.hpp"

class PasswordPack : public QObject{
    Q_OBJECT
public:
    PasswConfig * passwConf;
    ResultBox * resultBox;
    QPushButton * displayButton;
    //
    PasswordPack(QObject * parent = nullptr);
    
signals:
    void display_bt_clicked(ConfigBox *, ResultBox*);
} ;

class UidPack : public QObject{
    Q_OBJECT
public:
    UidConfig * uidConf;
    ResultBox * resultBox;
    QPushButton * displayButton;
    //
    UidPack(QObject * parent = nullptr);
signals:
    void display_bt_clicked(ConfigBox *, ResultBox*);
};

class PseudoPack : public QObject{
    Q_OBJECT
public:
    PseudoConfig * pseudoConf;
    ResultBox * resultBox;
    QPushButton * displayButton;
    //
    PseudoPack(QObject * parent = nullptr);

signals:
    void display_bt_clicked(ConfigBox *, ResultBox*);

};

//============== DashBord ===============//
class DashBord : public QWidget{
    Q_OBJECT
//Attributs
private:
    QGridLayout * glayout;
    //
    QStackedWidget * configsStack;
    QStackedWidget * resultStack;
    QWidget * switchStackWidget;
    QVBoxLayout * switchStackLayout;
    //
    PasswordPack * passwPack;
    UidPack * uidPack;
    PseudoPack * pseudoPack;
    //

//Methodes
public:
    DashBord(QWidget * parent = nullptr);

private slots:
    void on_display_bt_clicked(ConfigBox *, ResultBox *);

};