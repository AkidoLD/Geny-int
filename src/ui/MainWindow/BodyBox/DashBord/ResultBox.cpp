#include "ui/MainWindow/BodyBox/DashBord/ResultBox.hpp"

ResultBox::ResultBox(const QString &result_title_text,QWidget * parent):
    QWidget(parent),
    vlayout(new QVBoxLayout()),
    result_scroll(new QScrollArea()),
    result_list(new QListWidget()),
    result_title(new QLabel())
{
    this->setObjectName("result-box");
    this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    this->setLayout(vlayout);
    this->setStyleSheet(w_style);
    //
    vlayout->setObjectName("result-box-layout");
    vlayout->addWidget(result_title, 0, Qt::AlignLeft | Qt::AlignTop);
    vlayout->addWidget(result_scroll, 1);
    //
    result_title->setObjectName("result-box-title");
    result_title->setText(result_title_text);
    //
    result_scroll->setObjectName("result-box-scroll");
    result_scroll->setWidget(result_list);
    result_scroll->setWidgetResizable(true);
    //
    result_list->setObjectName("result-box-list");
    result_list->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
}

void ResultBox::display_token_list(const QStringList &gen_tokens){
    if(gen_tokens.empty()){
        result_list->clear();
        return;
    }
    result_list->clear();
    result_list->addItems(gen_tokens);
}

const QString ResultBox::w_style{R"(

        #result-box #result-box-title{
            color: black;
            font-size: 20pt;
            margin: 0 30px;
            font-family: 'URW Gothic';
            font-weight: 700;
        }

        #result-box-list{
            color: black;
            font-size: 14pt;
            font-family: 'Andale Mono';
            font-weight: 700;
            background-color: white;
            border: 2px solid black;
        }

        #result-box-list QListWidgetItem{
            margin: 4px 0;
            border: 1px solid black;
        }
        
    )"
};