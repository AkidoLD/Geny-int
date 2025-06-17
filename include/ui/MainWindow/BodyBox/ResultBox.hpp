#pragma once

#include <QWidget>
#include <QLayout>
#include <QScrollArea>
#include <QListWidget>
#include <QLabel>

class ResultBox : public QWidget{
//Attributs
private:
    QVBoxLayout * vlayout;
    QScrollArea * result_scroll;
    QListWidget * result_list;
    QLabel * result_title;

//Methodes
public:
    ResultBox(const QString result_title_text, QWidget * parent = nullptr);

};