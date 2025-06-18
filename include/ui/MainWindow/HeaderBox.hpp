#pragma once

#include <QLayout>
#include <QWidget>
#include <QLabel>

class HeaderBox : public QWidget {
//Attributs
private:
    QGridLayout * glayout;
    QLabel * appName; 
    QLabel * present_msg;
    
//Methodes
public:
    HeaderBox(QWidget * parent = nullptr);

};