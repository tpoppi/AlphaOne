#ifndef SCACCHI_H
#define SCACCHI_H

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QPushButton>
#include <QFile>
#include <QDialog>
#include <QLabel>
#include "prombutton.h"
#include "chessbutton.h"
#include "vector.h"

class Controller;


class Scacchi : public QWidget
{
    Q_OBJECT

public:
    Scacchi(Controller* p,QWidget *parent = nullptr);
    QLayoutItem* getBoardItem(const int& pos) const;
    void reset();
    void finestrapromozione(bool k, int posf);
    void cancellamosse() const;
    void colora(vector<int> v,const int& pos) const;
    void AggiornaIcone(const int& posi, const int& posf) const;
    void Promozione(const char& t, const int& p,const bool& k) const;
    void mostravincitore(const bool& k);
    void eliminapedina(const int& p) const;
    void finestraeccezioni(QLabel* p);
private:
    Controller* controller;
    QVBoxLayout* mainlayout;
    QGridLayout* gridlayout;
    void addMenu();
    void addButtons();
    void setButtons();
};
#endif // SCACCHI_H
