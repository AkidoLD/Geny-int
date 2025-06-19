#pragma once

#include <QWidget>
#include <QLayout>
#include <QScrollArea>
#include <QListWidget>
#include <QLabel>
#include <string>
#include <vector>

class ResultBox : public QWidget{
    Q_OBJECT
//Attributs
private:
    QVBoxLayout * vlayout;
    QScrollArea * result_scroll;
    QListWidget * result_list;
    QLabel * result_title;
    //
    static const QString w_style;

//Methodes
public:
    ResultBox(const QString &result_title_text, QWidget * parent = nullptr);

public :
    void display_token_list(const QStringList &gen_tokens);

};