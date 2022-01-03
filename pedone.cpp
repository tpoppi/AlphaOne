#include "pedone.h"

Pedone::Pedone(const bool& c,const int& p, Scacchiera* parent, const bool& b) : Pezzi(c,p, parent), pass(b) {}

vector<int> Pedone::move() const
{
    vector<int> mossepossibili;
    //sx e dx guardando il pedone
    if(colore){//se il colore è bianco sommo, e la mossa +7 va in diagonale a sinistra, mentre, +9 va in diagonale a destra
        if(pos<56){
            if(pos>=8 && pos<16){
                if(!parent->getStato(pos+8) && !parent->getStato(pos+16))
                    mossepossibili.push_back(pos+16); 
            }
            if(!parent->getStato(pos+8))
                    mossepossibili.push_back(pos+8);
            if((pos%8)!=0 && parent->getStato(pos+7)==nero)
                    mossepossibili.push_back(pos+7);
             if((pos%8)!=7 && parent->getStato(pos+9)==nero)
                    mossepossibili.push_back(pos+9);
        }
    }
    else{
        //se il colore è nero, la mossa -7 va in diagole a sinistra, mentre -9 va in diagonale a destra
        if(pos>7){
            if(pos>=48 && pos<56){
                if(!parent->getStato(pos-8) && !parent->getStato(pos-16))
                    mossepossibili.push_back(pos-16);
            }
            if(!parent->getStato(pos-8))
                    mossepossibili.push_back(pos-8);
            if((pos%8)!=7 && parent->getStato(pos-7)==bianco)
                    mossepossibili.push_back(pos-7);
            if((pos%8)!=0 && parent->getStato(pos-9)==bianco)
                    mossepossibili.push_back(pos-9);
        }
    }
    vector<int> v=enpassant();
    mossepossibili=mossepossibili+v;
    return mossepossibili;
}


Pedone *Pedone::clone() const
{
    return new Pedone(*this);
}


vector<int> Pedone::enpassant() const
{
    vector<int> mosse;
    if(colore){                         //en passant colore bianco
        if(pos/8==4 && (pos%8)!=0 && parent->getStato(pos+7)==none){   //en passant a sinistra
            Pedone* p=dynamic_cast<Pedone*>(parent->getPedina(pos-1));
            if(p && !p->getColore() && p->pass)
                mosse.push_back(pos+7);
        }
        if(pos/8==4 && (pos%8)!=7 && parent->getStato(pos+9)==none){
            Pedone* p=dynamic_cast<Pedone*>(parent->getPedina(pos+1));
            if(p && !p->getColore() && p->pass)
                mosse.push_back(pos+9);
        }
    }
    else{                               //enpassant nero
        if(pos/8==3 && (pos%8)!=7 && parent->getStato(pos-7)==none){   //en passant a destra
            Pedone* p=dynamic_cast<Pedone*>(parent->getPedina(pos+1));
            if(p && p->getColore() && p->pass)
                mosse.push_back(pos-7);
        }
        if(pos/8==3 && (pos%8)!=0 && parent->getStato(pos-9)==none){
            Pedone* p=dynamic_cast<Pedone*>(parent->getPedina(pos-1));
            if(p && p->getColore() && p->pass)
                mosse.push_back(pos-9);
        }
    }
    return mosse;
}

void Pedone::setpass(const bool& c)
{
    pass=c;
}

void Pedone::setPosizione(const int& p)
{
    if(p==pos+16 || p==pos-16)
        pass=true;
    pos=p;
}


