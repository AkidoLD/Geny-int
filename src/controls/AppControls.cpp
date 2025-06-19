#include "controls/AppControls.hpp"

const QMap<ConfigError, QString> AppControls::ConfigErrorMap{
    {ConfigError::NoGenerator, "Aucun generateur selectionne"},
    {ConfigError::OnlyOneGenerator, "Vous devez avoir selectionne au moins un generateur"}
};

const QMap<PasswError, QString> AppControls::PasswErrorMap{
    {PasswError::NullLenght, "La taille de votre mot de passe ne peut pas etre null"},
    {PasswError::NullNumber, "Vous devez generer au moins un Mot de passe"}
};

const QMap<UidError, QString> AppControls::UidErrorMap{
    {UidError::NullNumber, "Vous devez generer au moins un UID"},
    {UidError::NullLenghtBloc, "La taille d'un bloc ne peux pas etre null"},
    {UidError::NullNumberBloc, "L'UID genere doit avoir au moins 1 bloc"}
};

const QMap<PseudoError, QString> AppControls::PseudoErrorMap{
    {PseudoError::MaxLessThanMin, "La taille maximale est inferieur a la minimale"},
    {PseudoError::NullMaxLenght, "La taille maximale ne peux pas etre null"},
    {PseudoError::NullMinLenght, "La taille minimale ne peux pas etre null"},
    {PseudoError::NullNumber, "Le nombre de pseudo genere ne peux pas etre null"},
    {PseudoError::SampleRequired, "Un echantillons est requis pour la generation"}
};


AppControls::AppControls(MainWindow * genyView, GenyRand * genyModel, QObject * parent):
    QObject(parent),
    genyView(genyView),
    genyModel(genyModel)
{
    auto & dashbord = genyView->bodyBox->get_dashbord();
    QObject::connect(&dashbord, &DashBord::generate_bt_clicked, this, &AppControls::on_generated_bt_clicked);
    QObject::connect(&dashbord, &DashBord::config_change, this, &AppControls::on_config_change);
    QObject::connect(this, &AppControls::error_occured, this, &AppControls::on_error_occured);
    QObject::connect(this, &AppControls::no_error_occured, this, &AppControls::on_no_error_occured);
    //

}

void AppControls::on_generated_bt_clicked(ConfigBox *conf, ResultBox *result){
    if(!conf || !result) return;
    //
    qDebug() << "Signal de generation emit et recu...";
    QStringList result_table {};
    if(auto g_passw = qobject_cast<PasswConfig *>(conf)){
        result_table = generate_random_password(g_passw);
        qDebug() << "Generation de Mot de passe en cours ...";
        //
    }else if(auto g_uid = qobject_cast<UidConfig *>(conf)){
        result_table = generate_random_uid(g_uid);
        qDebug() << "Generation de UID en cours ...";
        //
    }else if(auto g_pseudo = qobject_cast<PseudoConfig *>(conf)){
        result_table = generate_random_pseudo(g_pseudo);
        qDebug() << "Generation de Pseudo en cours ...";
        //
    }
    result->display_token_list(result_table);
}

const QStringList AppControls::generate_random_password(PasswConfig *passwConfig){
    if(passwConfig == nullptr) return {};
    //Recuperer les composants parametres de la config
    const size_t passw_l = passwConfig->get_lenght_spin_value();
    const size_t passw_n = passwConfig->get_number_spin_value();
    
    //Generateurs
    const bool c_digit = passwConfig->get_d_char_check_state();
    const bool c_u_alpha = passwConfig->get_u_char_check_state();
    const bool c_l_alpha = passwConfig->get_l_char_check_state();
    const bool c_s_char = passwConfig->get_s_char_check_state();
    const bool c_p_char = passwConfig->get_p_char_check_state();
    const bool w_db_char = passwConfig->get_wdb_char_check_state();
    const bool g_homo = passwConfig->get_homo_gen_check_state();
    //
    vector<generator> generators = this->genyModel->make_generator_list(
        c_digit,
        c_u_alpha,
        c_l_alpha,
        c_s_char,
        c_p_char,
        w_db_char
    );
    if(generators.empty()){
        on_config_change(passwConfig);
        return {};
    }
    //Generer les tokens
    QStringList tokens {};
    while(tokens.size() < (qsizetype) passw_n) tokens.append(genyModel->generate_secure_passw(
        passw_l,
        generators,
        g_homo
    ).c_str());
    //
    return tokens;
}

const QStringList AppControls::generate_random_uid(UidConfig *uidConfig){
    if(uidConfig == nullptr) return {};
    //Recuperer les composants parametres de la config
    const size_t l_bloc = uidConfig->get_l_bloc_spin_value();
    const size_t n_bloc = uidConfig->get_n_bloc_spin_value();
    const size_t n_uid = uidConfig->get_n_uid_spin_value();
    const string s_bloc = uidConfig->get_s_bloc_edit_text().toStdString();
    
    //Generateurs
    const bool c_digit = uidConfig->get_d_char_check_state();
    const bool c_u_alpha = uidConfig->get_u_char_check_state();
    const bool c_l_alpha = uidConfig->get_l_char_check_state();
    const bool c_s_char = uidConfig->get_s_char_check_state();
    const bool c_p_char = uidConfig->get_p_char_check_state();
    const bool w_db_char = uidConfig->get_wdb_char_check_state();
    const bool g_homo = uidConfig->get_homo_gen_check_state();
    //
    vector<generator> generators = this->genyModel->make_generator_list(
        c_digit,
        c_u_alpha,
        c_l_alpha,
        c_s_char,
        c_p_char,
        w_db_char
    );
    if(generators.empty()){
        on_config_change(uidConfig);
        return {};
    }
    //Generer les tokens
    QStringList tokens {};
    while(tokens.size() < (qsizetype) n_uid) tokens.append(genyModel->generate_unique_uid(
        n_bloc,
        l_bloc,
        s_bloc,
        generators,
        g_homo
    ).c_str());
    //
    return tokens;
}

const QStringList AppControls::generate_random_pseudo(PseudoConfig *pseudoConfig){
        if(pseudoConfig == nullptr) return {};
    //Recuperer les composants parametres de la config
    const size_t l_pseudo_max = pseudoConfig->get_l_pseudo_max_spin_value ();
    const size_t l_pseudo_min = pseudoConfig->get_l_pseudo_min_spin_value();
    const size_t n_pseudo = pseudoConfig->get_n_pseudo_spin_value ();
    const string sample = pseudoConfig->get_sample_edit_text ().toStdString();
    const bool r_sample = pseudoConfig->get_r_sample_check_state ();
    
    //Generateurs
    const bool c_digit = pseudoConfig->get_d_char_check_state();
    const bool c_u_alpha = pseudoConfig->get_u_char_check_state();
    const bool c_l_alpha = pseudoConfig->get_l_char_check_state();
    const bool c_s_char = pseudoConfig->get_s_char_check_state();
    const bool c_p_char = pseudoConfig->get_p_char_check_state();
    const bool w_db_char = pseudoConfig->get_wdb_char_check_state();
    const bool g_homo = pseudoConfig->get_homo_gen_check_state();
    //
    vector<generator> generators = this->genyModel->make_generator_list(
        c_digit,
        c_u_alpha,
        c_l_alpha,
        c_s_char,
        c_p_char,
        w_db_char
    );
    //
    if(generators.empty()){
        on_config_change(pseudoConfig);
        return {};
    }
    //Generer les tokens
    QStringList tokens {};
    while(tokens.size() < (qsizetype) n_pseudo) tokens.append(genyModel->generate_personal_pseudo(
        sample,
        l_pseudo_max,
        l_pseudo_min,
        generators,
        g_homo,
        r_sample
    ).c_str());
    //
    return tokens;
}

void AppControls::on_config_change(ConfigBox *conf_box){
    if(!conf_box) return ;
    qDebug() << "Verification en cours";
    bool error_occured = false;
    error_occured |= verify_generator(conf_box);
    //
    if(auto passw_conf = qobject_cast<PasswConfig *>(conf_box))
        error_occured |= verify_passw_conf(passw_conf);
    else if(auto uid_conf = qobject_cast<UidConfig *>(conf_box))
        error_occured |= verify_uid_config(uid_conf);
    else if(auto pseudo_conf = qobject_cast<PseudoConfig *>(conf_box))
        error_occured |= verify_pseudo_conf(pseudo_conf);

    //Si aucune erreur n'est emise
    if(!error_occured)
        emit no_error_occured(conf_box);
}   

bool AppControls::verify_generator(ConfigBox *conf_box){
    if(!conf_box) return true ;
    //
    auto check_list = conf_box->get_enabled_generators();
    if(check_list.isEmpty()){
        emit error_occured(conf_box, ConfigErrorMap[ConfigError::NoGenerator]);
        return true;
    }

    if(check_list.size() == 1){
        check_list.at(0)->setEnabled(false);
        //emit error_occured(conf_box, ConfigErrorMap[ConfigError::OnlyOneGenerator]);
        return false ;
    }

    //cas echeant
    foreach(auto check, check_list) check->setEnabled(true);
    return false;
}

bool AppControls::verify_passw_conf(PasswConfig *conf_box){
    if(!conf_box) return true;
    //
    auto l_passw = conf_box->get_lenght_spin_value();
    auto n_passw = conf_box->get_number_spin_value();
    //
    if(l_passw <= 0){
        emit error_occured(conf_box, PasswErrorMap[PasswError::NullLenght]);
        return true;
    }
    if( n_passw <= 0){
        emit error_occured(conf_box, PasswErrorMap[PasswError::NullNumber]);
        return true;
    }

    //Cas echeant
    return false;
}

bool AppControls::verify_pseudo_conf(PseudoConfig *conf_box){
    if(!conf_box) return true ;
    //
    auto l_pseudo_max = conf_box->get_l_pseudo_max_spin_value();
    auto l_pseudo_min = conf_box->get_l_pseudo_min_spin_value();
    auto n_pseudo = conf_box->get_n_pseudo_spin_value();
    //
    auto sample = conf_box->get_sample_edit_text();
    auto r_sample = conf_box->get_r_sample_check_state();
    //
    if(l_pseudo_max <= 0){
        emit error_occured(conf_box, PseudoErrorMap[PseudoError::NullMaxLenght]);
        return true;
    }
    //
    if(l_pseudo_min <= 0){
        emit error_occured(conf_box, PseudoErrorMap[PseudoError::NullMinLenght]);
        return true;
    }
    //
    if(n_pseudo <= 0){
        emit error_occured(conf_box, PseudoErrorMap[PseudoError::NullNumber]);
        return true;
    }
    //
    if(l_pseudo_max < l_pseudo_min){
        emit error_occured(conf_box, PseudoErrorMap[PseudoError::MaxLessThanMin]);
        return true;
    }
    //
    if(r_sample && sample.isEmpty() ){
        emit error_occured(conf_box, PseudoErrorMap[PseudoError::SampleRequired]);
        return true;
    }
    //Cas echeant
    return false;
}

bool AppControls::verify_uid_config(UidConfig *conf_box){
    if(!conf_box) return false;
    //
    auto n_bloc = conf_box->get_n_bloc_spin_value(); 
    auto l_bloc = conf_box->get_l_bloc_spin_value(); 
    auto n_uid = conf_box->get_n_uid_spin_value(); 
    //
    if(n_bloc <= 0){
        emit error_occured(conf_box, UidErrorMap[UidError::NullNumberBloc]);
        return true;
    }

    if(l_bloc <= 0){
        emit error_occured(conf_box, UidErrorMap[UidError::NullLenghtBloc]);
        return true;
    }

    if(n_uid <= 0){
        emit error_occured(conf_box, UidErrorMap[UidError::NullNumber]);
        return true ;
    }

    //Si aucune erreur n'est detecte
    return false;
}

void AppControls::on_error_occured(ConfigBox *conf_box, const QString &error){
    if(!conf_box || error.isEmpty()) return ;
    conf_box->show_errors(error);
    conf_box->chang_valid_bt_state(false);
}

void  AppControls::on_no_error_occured(ConfigBox *conf_box){
    if(!conf_box) return ;
    conf_box->hide_errors();
    conf_box->chang_valid_bt_state(true);
}
