#include "scacchi.h"
#include <QIcon>
#include <QSize>
#include "controller.h"
#include <QString>

Scacchi::Scacchi(Controller* p,QWidget *parent) : QWidget(parent), controller(p)
{
    mainlayout= new QVBoxLayout(this);
    gridlayout= new QGridLayout();
    setMinimumSize(QSize(600, 600));
    addMenu();

    addButtons();
    setButtons();
    gridlayout->setSpacing(0);
    mainlayout->addLayout(gridlayout);
    setLayout(mainlayout);
}


QLayoutItem *Scacchi::getBoardItem(const int & pos) const
{
    return gridlayout->itemAtPosition(pos/8, pos%8);
}

void Scacchi::setButtons()
{
    QPushButton* p=static_cast<QPushButton*>(gridlayout->itemAtPosition(0, 0)->widget());
    p->setIcon(QIcon(":/TorreNera.png"));
    p=static_cast<QPushButton*>(gridlayout->itemAtPosition(0, 1)->widget());
    p->setIcon(QIcon(":/CavalloNero.png"));
    p=static_cast<QPushButton*>(gridlayout->itemAtPosition(0, 2)->widget());
    p->setIcon(QIcon(":/AlfiereNero.png"));
    p=static_cast<QPushButton*>(gridlayout->itemAtPosition(0, 3)->widget());
    p->setIcon(QIcon(":/ReginaNera.png"));
    p=static_cast<QPushButton*>(gridlayout->itemAtPosition(0, 4)->widget());
    p->setIcon(QIcon(":/ReNero.png"));
    p=static_cast<QPushButton*>(gridlayout->itemAtPosition(0, 5)->widget());
    p->setIcon(QIcon(":/AlfiereNero.png"));
    p=static_cast<QPushButton*>(gridlayout->itemAtPosition(0, 6)->widget());
    p->setIcon(QIcon(":/CavalloNero.png"));
    p=static_cast<QPushButton*>(gridlayout->itemAtPosition(0, 7)->widget());
    p->setIcon(QIcon(":/TorreNera.png"));
    for (int i=0; i<8; i++)
    {
        p=static_cast<QPushButton*>(gridlayout->itemAtPosition(1, i)->widget());
        p->setIcon(QIcon(":/PedoneNero.png"));
    }

    for (int i=0; i<32; i++)
    {
        p=static_cast<QPushButton*>(gridlayout->itemAtPosition(2+i/8, i%8)->widget());
        p->setIcon(QIcon(""));
    }
    for (int i=0; i<8; i++)
    {
        p=static_cast<QPushButton*>(gridlayout->itemAtPosition(6, i)->widget());
        p->setIcon(QIcon(":/PedoneBianco.png"));
    }
    p=static_cast<QPushButton*>(gridlayout->itemAtPosition(7, 0)->widget());
        p->setIcon(QIcon(":/TorreBianca.png"));
        p=static_cast<QPushButton*>(gridlayout->itemAtPosition(7, 1)->widget());
        p->setIcon(QIcon(":/CavalloBianco.png"));
        p=static_cast<QPushButton*>(gridlayout->itemAtPosition(7, 2)->widget());
        p->setIcon(QIcon(":/AlfiereBianco.png"));
        p=static_cast<QPushButton*>(gridlayout->itemAtPosition(7, 3)->widget());
        p->setIcon(QIcon(":/ReginaBianca.png"));
        p=static_cast<QPushButton*>(gridlayout->itemAtPosition(7, 4)->widget());
        p->setIcon(QIcon(":/ReBianco.png"));
        p=static_cast<QPushButton*>(gridlayout->itemAtPosition(7, 5)->widget());
        p->setIcon(QIcon(":/AlfiereBianco.png"));
        p=static_cast<QPushButton*>(gridlayout->itemAtPosition(7, 6)->widget());
        p->setIcon(QIcon(":/CavalloBianco.png"));
        p=static_cast<QPushButton*>(gridlayout->itemAtPosition(7, 7)->widget());
        p->setIcon(QIcon(":/TorreBianca.png"));

        for (int i=0; i<64; i++)
        {
           p=static_cast<QPushButton*>(gridlayout->itemAtPosition(i/8, i%8)->widget());
           p->setIconSize(QSize(60, 60));
        }
}

void Scacchi::addMenu()
{
    QMenuBar* menubar=new QMenuBar(this);
    QMenu* menu= new QMenu("File",menubar);
    QAction* reset= new QAction("Reset",menu);
    QAction* exit = new QAction("Exit",menu);
    connect(exit,SIGNAL(triggered()),this,SLOT(close()));
    connect(reset,SIGNAL(triggered()),controller,SLOT(reset()));
    menubar->addMenu(menu);
    menu->addAction(reset);
    menu->addAction(exit);
    mainlayout->addWidget(menubar);
}

void Scacchi::addButtons()
{
    for(int i=0;i<8;i++){
       if(i%2!=0){
            for(int y=0;y<8;y++){
                ChessButton* button=new ChessButton((i*8-56)*-1+y,this);
                connect(button,SIGNAL(buttonclicked(int, int)),controller,SLOT(ColoraMuovi(int, int)));
                button->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
                if(y%2==0){
                    QFile file(":/styleBlack.css");
                    file.open(QFile::ReadOnly);
                    QString styleSheet = QLatin1String(file.readAll());
                    button->setStyleSheet(styleSheet);
                }
                else{
                    QFile file(":/styleWhite.css");
                    file.open(QFile::ReadOnly);
                    QString styleSheet = QLatin1String(file.readAll());
                    button->setStyleSheet(styleSheet);
                }
               gridlayout->addWidget(button,i,y);
            }
       }
       else{
           for(int y=0;y<8;y++){
               ChessButton* button=new ChessButton((i*8-56)*-1+y,this);
               connect(button,SIGNAL(buttonclicked(int, int)),controller,SLOT(ColoraMuovi(int, int)));
               button->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
               if(y%2==0){
                   QFile file(":/styleWhite.css");
                   file.open(QFile::ReadOnly);
                   QString styleSheet = QLatin1String(file.readAll());
                   button->setStyleSheet(styleSheet);
               }
               else{
                   QFile file(":/styleBlack.css");
                   file.open(QFile::ReadOnly);
                   QString styleSheet = QLatin1String(file.readAll());
                   button->setStyleSheet(styleSheet);
               }
            gridlayout->addWidget(button,i,y);
           }
       }
    }
}

void Scacchi::reset()
{
    setButtons();
    for (int i=0; i<64; i++)
        static_cast<QPushButton*>(getBoardItem(i)->widget())->setEnabled(true);
}

void Scacchi::finestrapromozione(bool k, int posf)
{
    QDialog* finestra=new QDialog(this);
    QVBoxLayout* l=new QVBoxLayout(finestra);
    finestra->setMinimumSize(QSize(80, 80));
    if (k)               //tocca al bianco
    {
        PromButton* torre=new PromButton('t', posf, finestra);
        torre->setIcon(QIcon(":/TorreBianca.png"));
        connect(torre, SIGNAL(buttonclicked(char, int)), controller, SLOT(EseguiPromozione(char, int)));
        connect(torre, SIGNAL(clicked()), finestra, SLOT(close()));
        PromButton* regina=new PromButton('r', posf, finestra);
        regina->setIcon(QIcon(":/ReginaBianca.png"));
        connect(regina, SIGNAL(buttonclicked(char, int)),  controller, SLOT(EseguiPromozione(char, int)));
        connect(regina, SIGNAL(clicked()), finestra, SLOT(close()));
        PromButton* cavallo=new PromButton('c', posf, finestra);
        cavallo->setIcon(QIcon(":/CavalloBianco.png"));
        connect(cavallo, SIGNAL(buttonclicked(char, int)),  controller, SLOT(EseguiPromozione(char, int)));
        connect(cavallo, SIGNAL(clicked()), finestra, SLOT(close()));
        PromButton* alfiere=new PromButton('a', posf, finestra);
        alfiere->setIcon(QIcon(":/AlfiereBianco.png"));
        connect(alfiere, SIGNAL(buttonclicked(char, int)),  controller, SLOT(EseguiPromozione(char, int)));
        connect(alfiere, SIGNAL(clicked()), finestra, SLOT(close()));
        l->addWidget(torre);
        l->addWidget(regina);
        l->addWidget(cavallo);
        l->addWidget(alfiere);

    }
    else
    {
        PromButton* torre=new PromButton('t', posf, finestra);
        torre->setIcon(QIcon(":/TorreNera.png"));
        connect(torre, SIGNAL(buttonclicked(char, int)),  controller, SLOT(EseguiPromozione(char, int)));
        connect(torre, SIGNAL(clicked()), finestra, SLOT(close()));
        PromButton* regina=new PromButton('r', posf, finestra);
        regina->setIcon(QIcon(":/ReginaNera.png"));
        connect(regina, SIGNAL(buttonclicked(char, int)),  controller, SLOT(EseguiPromozione(char, int)));
        connect(regina, SIGNAL(clicked()), finestra, SLOT(close()));
        PromButton* cavallo=new PromButton('c', posf, finestra);
        cavallo->setIcon(QIcon(":/CavalloNero.png"));
        connect(cavallo, SIGNAL(buttonclicked(char, int)),  controller, SLOT(EseguiPromozione(char, int)));
        connect(cavallo, SIGNAL(clicked()), finestra, SLOT(close()));
        PromButton* alfiere=new PromButton('a', posf, finestra);
        alfiere->setIcon(QIcon(":/AlfiereNero.png"));
        connect(alfiere, SIGNAL(buttonclicked(char, int)),  controller, SLOT(EseguiPromozione(char, int)));
        connect(alfiere, SIGNAL(clicked()), finestra, SLOT(close()));
        l->addWidget(torre);
        l->addWidget(regina);
        l->addWidget(cavallo);
        l->addWidget(alfiere);
    }
    finestra->show();
}

void Scacchi::cancellamosse() const
{
    for(int i=0;i<8;i++){
       if(i%2!=0){
            for(int y=0;y<8;y++){
                ChessButton* button=static_cast<ChessButton*>(getBoardItem(i*8+y)->widget());
                if(y%2==0){
                    QFile file(":/styleBlack.css");
                    file.open(QFile::ReadOnly);
                    QString styleSheet = QLatin1String(file.readAll());
                    button->setStyleSheet(styleSheet);

                }
                else{
                    QFile file(":/styleWhite.css");
                    file.open(QFile::ReadOnly);
                    QString styleSheet = QLatin1String(file.readAll());
                    button->setStyleSheet(styleSheet);
                }
                 button->setRed(-1);
            }
       }
       else{
           for(int y=0;y<8;y++){
               ChessButton* button=static_cast<ChessButton*>(getBoardItem(i*8+y)->widget());
               if(y%2==0){
                   QFile file(":/styleWhite.css");
                   file.open(QFile::ReadOnly);
                   QString styleSheet = QLatin1String(file.readAll());
                   button->setStyleSheet(styleSheet);
               }
               else{
                   QFile file(":/styleBlack.css");
                   file.open(QFile::ReadOnly);
                   QString styleSheet = QLatin1String(file.readAll());
                   button->setStyleSheet(styleSheet);
               }
               button->setRed(-1);
           }
       }
    }
}

void Scacchi::colora(vector<int> v,const int& pos) const
{
    for(unsigned int i=0;i<v.getSize();i++){
        ChessButton* c=static_cast<ChessButton*>(getBoardItem(56-(v[i]/8)*8+v[i]%8)->widget());
        QFile file(":/styleselected.css");
        file.open(QFile::ReadOnly);
        QString styleSheet = QLatin1String(file.readAll());
        c->setStyleSheet(styleSheet);
        c->setRed(pos);
}
}

void Scacchi::AggiornaIcone(const int& posi, const int& posf) const
{
    QPushButton* i=static_cast<QPushButton*>(getBoardItem(56-(posi/8)*8+posi%8)->widget());
    QPushButton* f=static_cast<QPushButton*>(getBoardItem(56-(posf/8)*8+posf%8)->widget());
    f->setIcon(i->icon());
    i->setIcon(QIcon(" "));
}

void Scacchi::Promozione(const char& t, const int& p,const bool& k) const {
    QPushButton* f=static_cast<QPushButton*>(getBoardItem(56-(p/8)*8+p%8)->widget());
    if (k)
    {
        if (t=='r')
        f->setIcon(QIcon(":/ReginaBianca.png"));
        if (t=='t')
        f->setIcon(QIcon(":/TorreBianca.png"));
        if (t=='a')
        f->setIcon(QIcon(":/AlfiereBianco.png"));
        if (t=='c')
        f->setIcon(QIcon(":/CavalloBianco.png"));
    }
    else
    {
        if (t=='r')
        f->setIcon(QIcon(":/ReginaNera.png"));
        if (t=='t')
        f->setIcon(QIcon(":/TorreNera.png"));
        if (t=='a')
        f->setIcon(QIcon(":/AlfiereNero.png"));
        if (t=='c')
        f->setIcon(QIcon(":/CavalloNero.png"));
    }
}

void Scacchi::mostravincitore(const bool& k)
{
    QDialog* finestra=new QDialog(this);
    QVBoxLayout* l=new QVBoxLayout(finestra);
    finestra->setMinimumSize(QSize(80, 80));
    if (k)
    l->addWidget(new QLabel("Ha vinto il bianco"));
    else
    l->addWidget(new QLabel("Ha vinto il nero"));
    for (int i=0; i<64; i++)
    static_cast<QPushButton*>(getBoardItem(i)->widget())->setEnabled(false);
    finestra->show();
}

void Scacchi::eliminapedina(const int &p) const
{
    QPushButton* t=static_cast<QPushButton*>(getBoardItem(p)->widget());
    t->setIcon(QIcon(" "));
}

void Scacchi::finestraeccezioni(QLabel* p)
{
    QDialog* finestra=new QDialog(this);
    QVBoxLayout* l=new QVBoxLayout(finestra);
    l->addWidget(p);
    finestra->show();
}


