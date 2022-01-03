#include "scacchiera.h"
#include "cavallo.h"
#include "torre.h"
#include "regina.h"
#include "re.h"
#include "alfiere.h"
#include "pedone.h"
#include "Mossa_Imposs.h"
#include "Mossa_illegale.h"
#include "Arrocco_Exc.h"
#include "EnPassant_Exc.h"
#include <typeinfo>
#include "Promozione.h"
#include "winner.h"

int Scacchiera::caselle=64;

Scacchiera::Scacchiera(const bool& t) : board(caselle,nullptr), turn(t)
{

  board[0]=new Torre(1, 0, this);
  board[1]=new Cavallo(1, 1, this);
  board[2]=new Alfiere(1, 2, this);
  board[3]=new Regina(1, 3, this);
  board[4]=new Re(1, 4, this);
  board[5]=new Alfiere(1, 5, this);
  board[6]=new Cavallo(1, 6, this);
  board[7]=new Torre(1, 7, this);
  for (int i=0; i<8; i++)
    board[8+i]=new Pedone(1, 8+i, this);
  for (int i=0; i<8; i++)
    board[48+i]=new Pedone(0, 48+i, this);
  board[56]=new Torre(0, 56, this);
  board[57]=new Cavallo(0, 57, this);
  board[58]=new Alfiere(0, 58, this);
  board[59]=new Regina(0, 59, this);
  board[60]=new Re(0, 60, this);
  board[61]=new Alfiere(0, 61, this);
  board[62]=new Cavallo(0, 62, this);
  board[63]=new Torre(0, 63, this);
}

Scacchiera::Scacchiera(const Scacchiera &s) : board(caselle,nullptr)
{
    for (vector<Pezzi*>::iterator it=s.board.begin(); it!=s.board.end(); it++)
    {
        if (*it)     // se nella scacchiera da copiare allora copio lo stesso pezzo in this
        {
            board[(*it)->getPosizione()]=(*it)->clone();
            board[(*it)->getPosizione()]->setParent(this);
        }
    }
}

bool Scacchiera::getTurn() const
{
    return turn;
}

giocatore Scacchiera::getStato(const int& pos) const
{
  if (board[pos])
  {
      if (board[pos]->getColore())
          return bianco;
      else
          return nero;
  }
  else
      return none;
}

Pezzi* Scacchiera::getPedina(const int& pos) const
{
    return board[pos];
}

Scacchiera::~Scacchiera()
{
    for (vector<Pezzi*>::iterator i=board.begin(); i!=board.end();i++)
        delete *i;
}

bool Scacchiera::W(const bool& p) const  //funzione che verifica se c'è uno scacco al giocatore p
{
  int re_pos=-1;
  for (vector<Pezzi*>::const_iterator it=board.begin(); it!=board.end();it++)
  {
     if (*it && (*it)->getColore()==p && dynamic_cast<Re*>(*it)!=nullptr)  //cerco il re
     re_pos=(*it)->getPosizione();
  }
  vector<int> v;
  if (p)          //salvo tutte le mosse possibili dell'avversario
  v=Mosse(0);
   else
   v=Mosse(1);

  for (vector<int>::const_iterator it=v.begin(); it!=v.end();it++)   //se nelle mosse possibili dell'avversario c'è la posizione del re allora ritorno vero
  {
      if (*it==re_pos)
          return true;
  }
  return false;    //se esco dal ciclo senza ritornare nulla allora ritorno falso
}

void Scacchiera::reset()
{
    for (vector<Pezzi*>::iterator i=board.begin(); i!=board.end();i++){
        delete *i;
        *i=nullptr;
    }
    turn=true;
    board[0]=new Torre(1, 0, this);
    board[1]=new Cavallo(1, 1, this);
    board[2]=new Alfiere(1, 2, this);
    board[3]=new Regina(1, 3, this);
    board[4]=new Re(1, 4, this);
    board[5]=new Alfiere(1, 5, this);
    board[6]=new Cavallo(1, 6, this);
    board[7]=new Torre(1, 7, this);
    for (int i=0; i<8; i++)
      board[8+i]=new Pedone(1, 8+i, this);
    for (int i=0; i<8; i++)
      board[48+i]=new Pedone(0, 48+i, this);
    board[56]=new Torre(0, 56, this);
    board[57]=new Cavallo(0, 57, this);
    board[58]=new Alfiere(0, 58, this);
    board[59]=new Regina(0, 59, this);
    board[60]=new Re(0, 60, this);
    board[61]=new Alfiere(0, 61, this);
    board[62]=new Cavallo(0, 62, this);
    board[63]=new Torre(0, 63, this);
}

vector<int> Scacchiera::Mosse(const bool& g) const
{
    vector<int> mossetot;
    for (vector<Pezzi*>::const_iterator i=board.begin(); i!=board.end();i++)
    {
        if (*i && (*i)->getColore()==g)
        {
            vector<int> t;
            t=(*i)->move();
            mossetot=mossetot+t;
        }
    }
    return mossetot;
}

void Scacchiera::Arrocco(const int& pos1, const int& pos2)
{
      if (pos1==4 && !W(1))       //re bianco
      {
        if (pos2==2)     //arrocco lungo
        {
            Scacchiera* prova1=new Scacchiera(*this);
            prova1->board[pos1-1]=prova1->board[pos1];
            prova1->board[pos1-1]->setPosizione(pos1-1);
            prova1->board[pos1]=nullptr;
            Scacchiera* prova2=new Scacchiera(*this);
            prova2->board[pos1-2]=prova2->board[pos1];
            prova2->board[pos1-2]->setPosizione(pos1-2);
            prova2->board[pos1]=nullptr;
            if(!prova1->W(1) && !prova2->W(1))  //faccio l'arrocco lungo
            {
                board[pos2]=board[pos1];
                board[pos1]=nullptr;
                board[pos2]->setPosizione(pos2);
                board[pos2+1]=board[0];
                board[0]=nullptr;
                board[pos2+1]->setPosizione(pos2+1);
                delete prova2;
                delete prova1;
            }
            else{
                delete prova2;
                delete prova1;
                throw Mossa_illegale();
           }

        }
        else if (pos2==6)
        {
            Scacchiera* prova1=new Scacchiera(*this);
            prova1->board[pos1+1]=prova1->board[pos1];
            prova1->board[pos1+1]->setPosizione(pos1+1);
            prova1->board[pos1]=nullptr;
            Scacchiera* prova2=new Scacchiera(*this);
            prova2->board[pos1+2]=prova2->board[pos1];
            prova2->board[pos1+2]->setPosizione(pos1+2);
            prova2->board[pos1]=nullptr;
            if(!prova1->W(1) && !prova2->W(1))  //faccio l'arrocco corto
            {
                board[pos2]=board[pos1];
                board[pos1]=nullptr;
                board[pos2]->setPosizione(pos2);
                board[pos2-1]=board[7];
                board[7]=nullptr;
                board[pos2-1]->setPosizione(pos2-1);
                delete prova2;
                delete prova1;
            }
            else{
                delete prova2;
                delete prova1;
                throw Mossa_illegale();
            }
        }
      }
      else if (pos1==60 && !W(0))
      {
          if (pos2==58)     //arrocco lungo
          {
              Scacchiera* prova1=new Scacchiera(*this);
              prova1->board[pos1-1]=prova1->board[pos1];
              prova1->board[pos1-1]->setPosizione(pos1-1);
              prova1->board[pos1]=nullptr;
              Scacchiera* prova2=new Scacchiera(*this);
              prova2->board[pos1-2]=prova2->board[pos1];
              prova2->board[pos1-2]->setPosizione(pos1-2);
              prova2->board[pos1]=nullptr;
              if(!prova1->W(0) && !prova2->W(0))  //faccio l'arrocco lungo
              {
                  board[pos2]=board[pos1];
                  board[pos1]=nullptr;
                  board[pos2]->setPosizione(pos2);
                  board[pos2+1]=board[56];
                  board[56]=nullptr;
                  board[pos2+1]->setPosizione(pos2+1);
                  delete prova2;
                  delete prova1;
              }
              else{
                  delete prova2;
                  delete prova1;
                  throw Mossa_illegale();
              }
          }
          else if (pos2==62)
          {
              Scacchiera* prova1=new Scacchiera(*this);
              prova1->board[pos1+1]=prova1->board[pos1];
              prova1->board[pos1+1]->setPosizione(pos1+1);
              prova1->board[pos1]=nullptr;
              Scacchiera* prova2=new Scacchiera(*this);
              prova2->board[pos1+2]=prova2->board[pos1];
              prova2->board[pos1+2]->setPosizione(pos1+2);
              prova2->board[pos1]=nullptr;
              if(!prova1->W(0) && !prova2->W(0))  //faccio l'arrocco corto
              {
                  board[pos2]=board[pos1];
                  board[pos1]=nullptr;
                  board[pos2]->setPosizione(pos2);
                  board[pos2-1]=board[63];
                  board[63]=nullptr;
                  board[pos2-1]->setPosizione(pos2-1);
                  delete prova2;
                  delete prova1;
              }
              else{
                  delete prova2;
                  delete prova1;
                  throw Mossa_illegale();
              }
          }
      }
      else
          throw Mossa_illegale();
}



void Scacchiera::Promozione(const int& pos, const char& pezzo)
{
    if (pezzo=='r')
    {
        delete board[pos];
        if (pos<=7)
        board[pos]=new Regina(0, pos, this);
        else
        board[pos]=new Regina(1, pos, this);
    }
    else if (pezzo=='t')
    {
        delete board[pos];
        if (pos<=7)
        board[pos]=new Torre(0, pos, this);
        else
        board[pos]=new Torre(1, pos, this);
    }
    else if (pezzo=='a')
    {
        delete board[pos];
        if (pos<=7)
        board[pos]=new Alfiere(0, pos, this);
        else
        board[pos]=new Alfiere(1, pos, this);
    }
    else if (pezzo=='c')
    {
        delete board[pos];
        if (pos<=7)
        board[pos]=new Cavallo(0, pos, this);
        else
        board[pos]=new Cavallo(1, pos, this);
    }
    if (W(turn))
    {
        if(Winner(turn)!=none)
         {
          throw winner();
         }
    }
}

void Scacchiera::cambiaturno(const int& posf)
{
    turn=!turn;
    if (!turn)
    {
    for (int i=0; i<8; i++)
      {
      Pedone* t;
      t=dynamic_cast<Pedone*>(board[32+i]);
       if (t)
        t->setpass(false);
       }
    if (typeid(*board[posf])==typeid(Pedone) && posf>=56)
        throw promozione();
    }
    else
    {
        for (int i=0; i<8; i++)
          {
          Pedone* t;
          t=dynamic_cast<Pedone*>(board[24+i]);
           if (t)
            t->setpass(false);
           }
        if (typeid(*board[posf])==typeid(Pedone) && posf<=7)
            throw promozione();
    }
    if (W(turn))
    {
        if(Winner(turn)!=none)
          throw winner();
    }
}


giocatore Scacchiera::Winner(const bool& p)   //ipotizzo che il re sia sottoscacco, perche winner viene chiamata solo se dopo una mossa il re è sottoscacco
{
    for (int it=0; it<caselle;it++)   // scorro la scacchiera, se trovo un pezzo bianco salvo le sue mosse e le simulo nel for annidato
     {
      if (board[it] && board[it]->getColore()==p)
       {

          vector<int> mosse=board[it]->move();
      for (vector<int>::const_iterator i=mosse.begin(); i!=mosse.end();i++)
      {
         Scacchiera* prova=new Scacchiera(*this);
         if (prova->board[*i])
         delete prova->board[*i];
        prova->board[*i]=prova->board[it];
        prova->board[it]=nullptr;
        prova->board[*i]->setPosizione(*i);
         if(!prova->W(p)){
            delete prova;
             return none;
         }
        delete prova;
      }
      }
 }
   return p ? nero : bianco;
}

void Scacchiera::Enpassant(const int& pos1, const int& pos2)
{
    Scacchiera* prova=new Scacchiera(*this);
    if(prova->board[pos1]->getColore()){
        delete prova->board[pos2-8];
        prova->board[pos2-8]=nullptr;
    }
    else{
        delete prova->board[pos2+8];
        prova->board[pos2+8]=nullptr;
    }
    prova->board[pos2]=prova->board[pos1];
    prova->board[pos1]=nullptr;
    prova->board[pos2]->setPosizione(pos2);
    if (prova->W(board[pos1]->getColore())){
        delete prova;
        throw Mossa_illegale();
    }
    delete prova;
    if(board[pos1]->getColore()){
        delete board[pos2-8];
        board[pos2-8]=nullptr;
    }
    else{
        delete board[pos2+8];
        board[pos2+8]=nullptr;
    }
    board[pos2]=board[pos1];
   board[pos1]=nullptr;
   board[pos2]->setPosizione(pos2);
   cambiaturno(pos2);
}

void Scacchiera::doMove(const int& pos1,const int& pos2)
{
          if (board[pos1]->getColore()==turn)
          {
            vector<int> v=board[pos1]->move();
            for(vector<int>::const_iterator i=v.begin(); i!=v.end();i++){
                if(*i==pos2){
                    if (typeid(*getPedina(pos1))==typeid(Re)) //se devo muovere il re e la mossa è nelle ultime due posizioni devo fare l'arrocco
                    {
                         vector<int> p=dynamic_cast<Re*>(getPedina(pos1))->MoveArrocco();
                         for(vector<int>::const_iterator y=p.begin(); y!=p.end();y++){
                             if(pos2==*y){
                                 Arrocco(pos1, *i);
                                 cambiaturno(pos2);
                                 throw Arrocco_Exc();
                                 }
                        }
                    }
                    if(typeid(*getPedina(pos1))==typeid(Pedone)){
                        vector<int> p=dynamic_cast<Pedone*>(getPedina(pos1))->enpassant();
                            for(vector<int>::const_iterator y=p.begin(); y!=p.end();y++){
                                if(pos2==*y){
                                    Enpassant(pos1,pos2);
                                    throw EnPassant_Exc();
                               }
                            }
                     }
                    Scacchiera* prova=new Scacchiera(*this);
                    if(prova->board[pos2])
                     delete prova->board[pos2];
                      prova->board[pos2]=prova->board[pos1];
                      prova->board[pos1]=nullptr;
                      prova->board[pos2]->setPosizione(pos2);
                      if (prova->W(board[pos1]->getColore())){
                          delete prova;
                          throw Mossa_illegale();
                    }
                    delete prova;
                    if(board[pos2])
                        delete board[pos2];
                    board[pos2]=board[pos1];
                    board[pos1]=nullptr;
                    board[pos2]->setPosizione(pos2);
                    cambiaturno(pos2);
                    return;
                    }

            }
}
        throw Mossa_Imposs();
}
