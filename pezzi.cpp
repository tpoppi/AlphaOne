#include "pezzi.h"
Pezzi::Pezzi(const bool& c,const int& p, Scacchiera* g): colore(c) , pos(p), parent(g) {}

bool Pezzi::getColore() const
{
    return colore;
}

void Pezzi::setPosizione(const int& p)
{
    pos=p;
}

int Pezzi::getPosizione() const
{
    return pos;
}

Pezzi::~Pezzi()
{

}


void Pezzi::setParent(Scacchiera *s)
{
 parent=s;
}
