#include "ui/MainWindow/FooterBox.hpp"

FooterBox::FooterBox(QWidget * parent):
    QWidget(parent),
    hblayout(new QHBoxLayout()), 
    credits(new QLabel())
{
    this->setObjectName("footer-box");
    this->setStyleSheet(R"(
            #footer-box{
                background-color: white;
                border-radius: 5px;
                color: black;
            }
        )"
    );
    this->setFixedHeight(35);
    this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
    this->setLayout(hblayout);
    //
    hblayout->setObjectName("footer-layout");
    hblayout->addWidget(credits, 0, Qt::AlignRight | Qt::AlignVCenter);
    //
    credits->setText("<span style='color:black'><b style='color: Orange'>Geny-int</b> by <b style= \"color:red\">Akido LD</b> @2025 | INOVA CORP</span>");

}