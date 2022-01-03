#include "controller.h"
#include"pezzi.h"
#include "chessbutton.h"
#include "Arrocco_Exc.h"
#include "EnPassant_Exc.h"
#include <QLabel>
#include "Promozione.h"
#include "prombutton.h"
#include "winner.h"
Controller::Controller(Scacchiera *s, QObject *p):  QObject(p), scacchiera(s) , vista(nullptr)
{}

void Controller::setView(Scacchi *s)
{
    vista=s;
}

void Controller::ColoraMuovi(const int& r,const int& pos) const
{
    vista->cancellamosse();
    if (r==-1)
        vedimosse(pos);
    else
        EseguiMossa(r, pos);
}

void Controller::EseguiPromozione(const char& t,const int& p) const
{
    vista->Promozione(t,p,!scacchiera->getTurn());
    try{
        scacchiera->Promozione(p, t);
    }
    catch(winner){
        vista->mostravincitore(!scacchiera->getTurn());
    }
}

void Controller::reset()
{
    vista->reset();
    scacchiera->reset();
}

void Controller::vedimosse(const int& pos) const
{
    if(scacchiera->getTurn()==scacchiera->getStato(pos)-1){
        Pezzi* p=scacchiera->getPedina(pos);
        vector<int> v=p->move();
        vista->colora(v,pos);
    }
}


void Controller::EseguiMossa(const int& posi, const int& posf) const
{
        try
    {
        scacchiera->doMove(posi, posf);
        vista->AggiornaIcone(posi, posf);
    }
        catch (EnPassant_Exc)
    {
        vista->AggiornaIcone(posi, posf);
        if (posi<posf)  //il bianco muove
            vista->eliminapedina(56-((posf-8)/8)*8+(posf-8)%8);
        else
            vista->eliminapedina(56-((posf+8)/8)*8+(posf+8)%8);
    }
    catch (Arrocco_Exc)
    {
        vista->AggiornaIcone(posi, posf);
          if (posi==4)     //re bianco
          {
              if (posf==2)     //sinistra        
                vista->AggiornaIcone(0, 3);
              else             //destra                       
                vista->AggiornaIcone(7, 5);
          }
          else             //re nero
          {
             if (posf==58)    //destra                        
                 vista->AggiornaIcone(56, 59);

             else             //sinistra                
                 vista->AggiornaIcone(63, 61);
          }
    }
    catch (Mossa_illegale)
    {
        vista->finestraeccezioni(new QLabel("Mossa Illegale"));
    }
    catch (Mossa_Imposs)
    {
        vista->finestraeccezioni(new QLabel("Mossa Impossibile"));
    }
    catch (promozione)
    {
        vista->AggiornaIcone(posi, posf);
        vista->finestrapromozione(!scacchiera->getTurn(),posf);

    }
    catch(winner)
    {
        vista->AggiornaIcone(posi, posf);
        vista->mostravincitore(!scacchiera->getTurn());
    }

}



