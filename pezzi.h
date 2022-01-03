#ifndef PEZZI_H
#define PEZZI_H
#include "vector.h"
#include "scacchiera.h"
#include "Mossa_illegale.h"
#include "Mossa_Imposs.h"
class Pezzi
{
public:
     Pezzi(const bool& c,const int& p, Scacchiera* g =nullptr);
    bool getColore() const;// 1=bianco; 0=nero;
    int getPosizione() const;
    virtual void setPosizione(const int& p);
    virtual ~Pezzi();
    virtual Pezzi* clone() const =0;
    virtual vector<int> move() const =0;
    void setParent(Scacchiera* s);
protected:
    bool colore;
    //posizione
    int pos;
    Scacchiera* parent;
};

#endif // PEZZI_H
