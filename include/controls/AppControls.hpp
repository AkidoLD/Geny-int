#pragma once

#include <QWidget>
#include <QObject>
#include <string>
#include "ui/MainWindow.hpp"
#include "model/GenyRand.hpp"

class AppControls : public QObject{
    Q_OBJECT
//Attributs
private:
    MainWindow * genyView;
    GenyRand * genyModel;

//Methodes
public:
    AppControls(MainWindow * genyview, GenyRand * genyModel, QObject * parent = nullptr);
    //
    const vector<string> generate_random_password(PasswConfig *); // Recuperer les information, generer et afficher
    const vector<string> generate_random_uid(UidConfig *);  // Recuperer les information, generer et afficher
    const vector<string> generate_random_pseudo(PseudoConfig *); // Recuperer les information, generer et afficher

//Slots
private slots:
    void on_generated_bt_clicked(ConfigBox *, ResultBox *);

public slots:

//Signaux
signals:

};