#pragma once

#include <QLayout>
#include <QWidget>
#include <QLabel>

class FooterBox : public QWidget {
    Q_OBJECT
//Attributs
private:
    QHBoxLayout * hblayout;
    QLabel * credits; 
    QLabel * nbr_words;
    //
    static const QString w_style;
    
//Methodes
public:
    FooterBox(QWidget * parent = nullptr);

    /**
     * @brief Set the content of nbr_words
     * @details This method allow to set the text of the nbr_word label.
     */
    void set_nbr_words_text(QString const &text);

};