#include "ui/MainWindow/FooterBox.hpp"

FooterBox::FooterBox(QWidget * parent):
    QWidget(parent),
    hblayout(new QHBoxLayout()),
    credits(new QLabel()),
    nbr_words(new QLabel())
{
    this->setObjectName("footer-box");
    this->setStyleSheet(w_style);
    this->setFixedHeight(50);
    this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    this->setLayout(hblayout);
    //
    hblayout->setObjectName("footer-layout");
    hblayout->addWidget(nbr_words, 0, Qt::AlignLeft | Qt::AlignBottom);
    hblayout->addWidget(credits, 0, Qt::AlignRight);
    //
    credits->setObjectName("footer-box-credits");
    credits->setText("<span style='color:black'><b style='color: Orange'>Geny-int</b> by <b style= 'color: #7838b4'>Akido LD</b> <strong>@</strong>2025 | <b>INOVA CORP</b></span>");
    //
    nbr_words->setObjectName("footer-box-nbr-words");
    nbr_words->setText("Base de mots : <b style='color:rgb(71, 85, 207)'>0</b> mots.");
    nbr_words->setFixedHeight(40);
}

void FooterBox::set_nbr_words_text(QString const &text){
    if(text.isEmpty()) return;
    nbr_words->setText(text);
}

const QString FooterBox::w_style{R"(
        #footer-box QLabel{
            font-size: 11pt;
            font-weight: 500;
        }

        #footer-box-nbr-words{
            background-color: white;
            border: 2px solid black;
            font-weight: 800;
            font-family: 'DejaVu Serif', monospace;
            color:rgb(0, 0, 0);
            border-radius: 20px;
            font-size: 15pt;
            margin: 0 10px;
        }
    )"
};