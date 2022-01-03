#ifndef PEDONE_H
#define PEDONE_H
#include "pezzi.h"


class Pedone: public Pezzi
{
public:
    Pedone(const bool& c,const int& p, Scacchiera* parent,const bool& b =false);
    vector<int> move() const;
    Pedone* clone() const;
    vector<int> enpassant() const;
    void setpass(const bool& c) ;
    void setPosizione(const int& p);
private:
    bool pass;  //viene inpostata a true solo quando viene effettuata una mossa di sue caselle, e viene rimessa false quando passa un turno
};

#endif // PEDONE_H
