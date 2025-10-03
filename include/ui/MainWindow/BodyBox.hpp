#pragma once

#include <QLayout>
#include <QWidget>
#include <QStack>
#include <QStackedWidget>
#include "ui/MainWindow/BodyBox/DashBord.hpp"

class BodyBox : public QWidget{
//Attributs
private:
    QVBoxLayout * vlayout;
    QStackedWidget * menu_stack;
    DashBord * dashBord;
    //
    static const QString w_style;
    
//Methodes
public:
    BodyBox(QWidget * parent = nullptr);

    //Getters
    DashBord &get_dashbord()const{ return *dashBord;}

};