#include "controls/AppControls.hpp"

AppControls::AppControls(MainWindow * genyView, GenyRand * genyModel, QObject * parent):
    QObject(parent),
    genyView(genyView),
    genyModel(genyModel)
{
    auto dashbord = genyView->bodyBox->get_dashbord();
    if(dashbord != nullptr) QObject::connect(dashbord, &DashBord::generate_bt_clicked, this, &AppControls::on_generated_bt_clicked);
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
    qDebug() << tokens.at(0);
    return tokens;
}
