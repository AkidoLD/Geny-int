#include <QMainWindow>
#include <QLayout>
#include <QLabel>

class HeaderBox : public QWidget{
    public:
    QHBoxLayout * layout;
    QLabel * name;
    
    //
    HeaderBox(QWidget * parent = NULL);
};

class CenterBox : public QWidget{
    public:
    QHBoxLayout * layout;
    QLabel * name;

    //
    CenterBox(QWidget * parent = NULL);
};

class LateralBox : public QWidget{
    public:
    QHBoxLayout * layout;
    QLabel * name;

    //
    LateralBox(QWidget * parent = NULL);
};

class MainWindow : public QMainWindow{
    //Attributs
    public:
    QWidget * central_widget;
    QGridLayout * central_layout;
    //
    HeaderBox * header_widget;
    CenterBox * center_widget;
    LateralBox  * lateral_widget;
    
    //Methodes
    MainWindow(QWidget * parent = NULL);
};