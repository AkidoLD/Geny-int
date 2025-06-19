#pragma once

#include <QWidget>
#include <QObject>
#include <string>
#include "ui/MainWindow.hpp"
#include "model/GenyRand.hpp"

//
/**
 * @brief Config Error
 */
enum class ConfigError{
    NoGenerator,
    OnlyOneGenerator
};
/**
 * @brief PasswordConfig Error
 */
enum class PasswError{
    NullLenght,
    NullNumber
};

/**
 * @brief UidConfig Errors
 */
enum class UidError{
    NullLenghtBloc,
    NullNumberBloc,
    NullNumber
};

/**
 * @brief PseudoConfig Errors
 */
enum class PseudoError{
    NullNumber,
    NullMaxLenght,
    NullMinLenght,
    MaxLessThanMin,
    SampleRequired  
};

class AppControls : public QObject{
    Q_OBJECT
//Attributs
private:
    MainWindow * genyView;
    GenyRand * genyModel;
    //
public:
    static const QMap<ConfigError, QString> ConfigErrorMap;
    static const QMap<PasswError, QString> PasswErrorMap;
    static const QMap<UidError, QString> UidErrorMap;
    static const QMap<PseudoError, QString> PseudoErrorMap;

//Methodes
private:
    bool verify_generator(ConfigBox *);
    //
    bool verify_passw_conf(PasswConfig *);
    bool verify_pseudo_conf(PseudoConfig *);
    bool verify_uid_config(UidConfig *);
    void display_db_size();

public:
    AppControls(MainWindow * genyview, GenyRand * genyModel, QObject * parent = nullptr);
    //
    const QStringList generate_random_password(PasswConfig *); // Recuperer les information, generer et afficher
    const QStringList generate_random_uid(UidConfig *);  // Recuperer les information, generer et afficher
    const QStringList generate_random_pseudo(PseudoConfig *); // Recuperer les information, generer et afficher

//Slots
private slots:
    void on_generated_bt_clicked(ConfigBox *, ResultBox *);
    //
    void on_config_change(ConfigBox *);
    //
    void on_error_occured(ConfigBox *conf_box, const QString &error);
    //
    void on_no_error_occured(ConfigBox *conf_box);

public slots:

//Signaux
signals:
    void error_occured(ConfigBox *, const QString &);
    void no_error_occured(ConfigBox *);

};