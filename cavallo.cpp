#include "cavallo.h"

Cavallo::Cavallo(const bool& c,const int& p, Scacchiera* parent) : Pezzi(c, p, parent)
{}

vector<int> Cavallo::move() const
{
    vector<int> mossepossibili;
    if (colore)
    {
        if (pos/8<=5)  //considero i due passi verso l'alto
        {
            if (pos%8==0)
            {
                if (parent->getStato(pos+2*8+1)!=bianco)
                mossepossibili.push_back(pos+2*8+1);
            }
            else if (pos%8==7)
            {
                if (parent->getStato(pos+2*8-1)!=bianco)
                mossepossibili.push_back(pos+2*8-1);
            }
            else
            {
                if (parent->getStato(pos+2*8+1)!=bianco)
                mossepossibili.push_back(pos+2*8+1);
                if (parent->getStato(pos+2*8-1)!=bianco)
                mossepossibili.push_back(pos+2*8-1);
            }
        }

       if (pos/8>=2)   //considero i due passi verso il basso
       {
           if (pos%8==0)
           {
               if (parent->getStato(pos-2*8+1)!=bianco)
               mossepossibili.push_back(pos-2*8+1);
           }
           else if (pos%8==7)
           {
               if (parent->getStato(pos-2*8-1)!=bianco)
               mossepossibili.push_back(pos-2*8-1);
           }
           else
           {
               if (parent->getStato(pos-2*8+1)!=bianco)
               mossepossibili.push_back(pos-2*8+1);
               if (parent->getStato(pos-2*8-1)!=bianco)
               mossepossibili.push_back(pos-2*8-1);
           }
       }
       if (pos%8<=5)  //considero i due passi verso destra
       {
           if (pos/8==0)
           {
               if (parent->getStato(pos+1*8+2)!=bianco)
               mossepossibili.push_back(pos+1*8+2);
           }
           else if (pos/8==7)
           {
               if (parent->getStato(pos-1*8+2)!=bianco)
               mossepossibili.push_back(pos-1*8+2);
           }
           else
           {
               if (parent->getStato(pos-1*8+2)!=bianco)
               mossepossibili.push_back(pos-1*8+2);
               if (parent->getStato(pos+1*8+2)!=bianco)
               mossepossibili.push_back(pos+1*8+2);
           }
       }
       if (pos%8>=2)  //considero i due passi verso sinistra
       {
           if (pos/8==0)
           {
               if (parent->getStato(pos+1*8-2)!=bianco)
               mossepossibili.push_back(pos+1*8-2);
           }
           else if (pos/8==7)
           {
               if (parent->getStato(pos-1*8-2)!=bianco)
               mossepossibili.push_back(pos-1*8-2);
           }
           else
           {
               if (parent->getStato(pos-1*8-2)!=bianco)
               mossepossibili.push_back(pos-1*8-2);
               if (parent->getStato(pos+1*8-2)!=bianco)
               mossepossibili.push_back(pos+1*8-2);
           }
       }
    }
    else
    {
        if (pos/8<=5)  //considero i due passi verso l'alto
        {
            if (pos%8==0)
            {
                if (parent->getStato(pos+2*8+1)!=nero)
                mossepossibili.push_back(pos+2*8+1);
            }
            else if (pos%8==7)
            {
                if (parent->getStato(pos+2*8-1)!=nero)
                mossepossibili.push_back(pos+2*8-1);
            }
            else
            {
                if (parent->getStato(pos+2*8+1)!=nero)
                mossepossibili.push_back(pos+2*8+1);
                if (parent->getStato(pos+2*8-1)!=nero)
                mossepossibili.push_back(pos+2*8-1);
            }
        }

       if (pos/8>=2)   //considero i due passi verso il basso
       {
           if (pos%8==0)
           {
               if (parent->getStato(pos-2*8+1)!=nero)
               mossepossibili.push_back(pos-2*8+1);
           }
           else if (pos%8==7)
           {
               if (parent->getStato(pos-2*8-1)!=nero)
               mossepossibili.push_back(pos-2*8-1);
           }
           else
           {
               if (parent->getStato(pos-2*8+1)!=nero)
               mossepossibili.push_back(pos-2*8+1);
               if (parent->getStato(pos-2*8-1)!=nero)
               mossepossibili.push_back(pos-2*8-1);
           }
       }
       if (pos%8<=5)  //considero i due passi verso destra
       {
           if (pos/8==0)
           {
               if (parent->getStato(pos+1*8+2)!=nero)
               mossepossibili.push_back(pos+1*8+2);
           }
           else if (pos/8==7)
           {
               if (parent->getStato(pos-1*8+2)!=nero)
               mossepossibili.push_back(pos-1*8+2);
           }
           else
           {
               if (parent->getStato(pos-1*8+2)!=nero)
               mossepossibili.push_back(pos-1*8+2);
               if (parent->getStato(pos+1*8+2)!=nero)
               mossepossibili.push_back(pos+1*8+2);
           }
       }
       if (pos%8>=2)  //considero i due passi verso sinistra
       {
           if (pos/8==0)
           {
               if (parent->getStato(pos+1*8-2)!=nero)
               mossepossibili.push_back(pos+1*8-2);
           }
           else if (pos/8==7)
           {
               if (parent->getStato(pos-1*8-2)!=nero)
               mossepossibili.push_back(pos-1*8-2);
           }
           else
           {
               if (parent->getStato(pos-1*8-2)!=nero)
               mossepossibili.push_back(pos-1*8-2);
               if (parent->getStato(pos+1*8-2)!=nero)
               mossepossibili.push_back(pos+1*8-2);
           }
       }
    }
    return mossepossibili;
}

Cavallo *Cavallo::clone() const
{
    return new Cavallo(*this);
}
