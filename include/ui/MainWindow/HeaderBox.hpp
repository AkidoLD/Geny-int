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
    static const QString w_style;
    
//Methodes
public:
    HeaderBox(QWidget * parent = nullptr);

};