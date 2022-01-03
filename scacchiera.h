#ifndef SCACCHIERA_H
#define SCACCHIERA_H
#include "vector.h"
#include<iostream>
class Pezzi;
enum giocatore{none = 0, nero =1, bianco =2};

class Scacchiera
{
public:
    Scacchiera(const bool& t=true);
    Scacchiera(const Scacchiera& s);
    bool getTurn() const;
    giocatore getStato(const int& pos) const;  //ritorna se nella posizione 'pos' la casella è libera oppure è occupata da un giocatore bianco o nero
    Pezzi* getPedina(const int& pos) const;  //ritorna un puntatore al pezzo che risiede nela casella pos
    ~Scacchiera();
    void Promozione(const int& pos, const char& pezzo);
    void reset();
    void doMove(const int& pos1,const int& pos2);   //doMove è la funzione che muove le pedine (nel caso di arrocco (cioè re di muove di due passi rispetto alla sua posizione) deve preoccuparsi di muovere anche la torre coinvolta)
private:
    static int caselle;
    vector<Pezzi*> board;
    bool turn;   //false=turno del nero, true bianco
    vector<int> Mosse(const bool& g) const;
    void Arrocco(const int& pos1, const int& pos2);
    void Enpassant(const int& pos1, const int& pos2);
    void cambiaturno(const int& posf);
     giocatore Winner(const bool& p);
    bool W(const bool& p) const;  // p è il colore del re di cui si vuole controllare lo scacco
};



#endif // SCACCHIERA_H

