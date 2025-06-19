#include "ui/MainWindow/FooterBox.hpp"

FooterBox::FooterBox(QWidget * parent):
    QWidget(parent),
    hblayout(new QHBoxLayout()), 
    credits(new QLabel())
{
    this->setObjectName("footer-box");
    this->setStyleSheet(w_style);
    this->setFixedHeight(35);
    this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    this->setLayout(hblayout);
    //
    hblayout->setObjectName("footer-layout");
    hblayout->addWidget(credits, 0, Qt::AlignRight | Qt::AlignVCenter);
    //
    credits->setText("<span style='color:black'><b style='color: Orange'>Geny-int</b> by <b style= 'color: #7838b4'>Akido LD</b> <strong>@</strong>2025 | <b>INOVA CORP</b></span>");

}

const QString FooterBox::w_style{R"(
        #footer-box QLabel{
            font-size: 11pt;
            font-weight: 500;
        }    
    )"
};