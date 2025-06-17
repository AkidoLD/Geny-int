#pragma once

#include <QMainWindow>
#include <QLayout>
#include <QWidget>
#include "ui/MainWindow/HeaderBox.hpp"
#include "ui/MainWindow/BodyBox.hpp"
#include "ui/MainWindow/FooterBox.hpp"
class MainWindow : public QMainWindow{
//Attributs
private:
    QWidget * widget;
    QVBoxLayout * layout;
    HeaderBox * headerBox; 
    BodyBox * bodyBox;
    FooterBox * footerBox;
//Methodes
public:
    MainWindow(const QString title, QWidget * parent = nullptr);
    //
};