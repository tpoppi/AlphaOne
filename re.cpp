#include "re.h"
#include "torre.h"
Re::Re(const bool& c,const int& p, Scacchiera* parent,const bool& m) : Pezzi(c, p, parent), moved(m)
{}

vector<int> Re::move() const

{
 vector<int> mossepossibili;
 if (colore)
 {
 if (pos==0) //sono in basso a sinistra
  {
     if (parent->getStato(pos+8)!=bianco)
     mossepossibili.push_back(pos+8); //vado in alto
     if (parent->getStato(pos+8+1)!=bianco )
     mossepossibili.push_back(pos+8+1); //vado in alto a destra
     if (parent->getStato(pos+1)!=bianco )
     mossepossibili.push_back(pos+1);  //vado a destra
  }
 else if(pos==7)  // basso a destra
  {
     if (parent->getStato(pos+8)!=bianco )
     mossepossibili.push_back(pos+8); //vado in alto
     if (parent->getStato(pos+8-1)!=bianco )
     mossepossibili.push_back(pos+8-1); //vado in alto a sinistra
     if (parent->getStato(pos-1)!=bianco)
     mossepossibili.push_back(pos-1);  //vado a sinistra
  }
 else if (pos==56)  //alto a sinistra
  {
     if (parent->getStato(pos-8)!=bianco)
     mossepossibili.push_back(pos-8); //vado in basso
     if (parent->getStato(pos-8+1)!=bianco)
     mossepossibili.push_back(pos-8+1); //vado in basso a destra
     if (parent->getStato(pos+1)!=bianco)
     mossepossibili.push_back(pos+1);  //vado a destra
  }
 else if(pos==63) //alto a destra
  {
     if (parent->getStato(pos-8)!=bianco)
     mossepossibili.push_back(pos-8); //vado in basso
     if (parent->getStato(pos-8-1)!=bianco)
     mossepossibili.push_back(pos-8-1); //vado in basso a sinistra
     if (parent->getStato(pos-1)!=bianco)
     mossepossibili.push_back(pos-1);  //vado a sinistra
  }
 else if (pos/8==0)  //sono in basso ma non negli angoli
  {
     for (int i=0; i<3; i++)  //vado in alto
     {
         if (parent->getStato(pos+8-1+i)!=bianco)
             mossepossibili.push_back(pos+8-1+i);
     }
     if (parent->getStato(pos-1)!=bianco)      //vado a sinistra
         mossepossibili.push_back(pos-1);
     if (parent->getStato(pos+1)!=bianco)      //vado a destra
         mossepossibili.push_back(pos+1);
  }
 else if (pos/8==7)  //sono in alto ma non negli angoli
  {
     for (int i=0; i<3; i++)  //vado in basso
     {
         if (parent->getStato(pos-8-1+i)!=bianco)
             mossepossibili.push_back(pos-8-1+i);
     }
     if (parent->getStato(pos-1)!=bianco)      //vado a sinistra
         mossepossibili.push_back(pos-1);
     if (parent->getStato(pos+1)!=bianco)      //vado a destra
         mossepossibili.push_back(pos+1);
  }
 else if (pos%8==0)  //sono a sinistra ma non negli angoli
  {
     for (int i=-1; i<2; i++)  //vado a destra
     {
         if (parent->getStato(pos+8*i+1)!=bianco)
             mossepossibili.push_back(pos+8*i+1);
     }
     if (parent->getStato(pos-8)!=bianco)      //vado in basso
         mossepossibili.push_back(pos-8);
     if (parent->getStato(pos+8)!=bianco)      //vado in alto
         mossepossibili.push_back(pos+8);
  }
 else if (pos%8==7)  //sono a destra ma non negli angoli
  {
     for (int i=-1; i<2; i++)  //vado a sinistra
     {
         if (parent->getStato(pos+8*i-1)!=bianco)
             mossepossibili.push_back(pos+8*i-1);
     }
     if (parent->getStato(pos-8)!=bianco)      //vado in basso
         mossepossibili.push_back(pos-8);
     if (parent->getStato(pos+8)!=bianco)      //vado in alto
         mossepossibili.push_back(pos+8);
  }
 else
 {
     for (int i=0; i<3; i++)  //vado in alto
     {
         if (parent->getStato(pos+8-1+i)!=bianco)
             mossepossibili.push_back(pos+8-1+i);
     }
     for (int i=0; i<3; i++)  //vado in basso
     {
         if (parent->getStato(pos-8-1+i)!=bianco)
             mossepossibili.push_back(pos-8-1+i);
     }
     if (parent->getStato(pos-1)!=bianco)      //vado a sinistra
         mossepossibili.push_back(pos-1);
     if (parent->getStato(pos+1)!=bianco)      //vado a destra
         mossepossibili.push_back(pos+1);
 }

  }
 else
 {
     if (pos==0) //sono in basso a sinistra
      {
         if (parent->getStato(pos+8)!=nero)
         mossepossibili.push_back(pos+8); //vado in alto
         if (parent->getStato(pos+8+1)!=nero)
         mossepossibili.push_back(pos+8+1); //vado in alto a destra
         if (parent->getStato(pos+1)!=nero)
         mossepossibili.push_back(pos+1);  //vado a destra
      }
     else if(pos==7)  // basso a destra
      {
         if (parent->getStato(pos+8)!=nero )
         mossepossibili.push_back(pos+8); //vado in alto
         if (parent->getStato(pos+8-1)!=nero)
         mossepossibili.push_back(pos+8-1); //vado in alto a sinistra
         if (parent->getStato(pos-1)!=nero)
         mossepossibili.push_back(pos-1);  //vado a sinistra
      }
     else if (pos==56)  //alto a sinistra
      {
         if (parent->getStato(pos-8)!=nero)
         mossepossibili.push_back(pos-8); //vado in basso
         if (parent->getStato(pos-8+1)!=nero)
         mossepossibili.push_back(pos-8+1); //vado in basso a destra
         if (parent->getStato(pos+1)!=nero)
         mossepossibili.push_back(pos+1);  //vado a destra
      }
     else if(pos==63) //alto a destra
      {
         if (parent->getStato(pos-8)!=nero)
         mossepossibili.push_back(pos-8); //vado in basso
         if (parent->getStato(pos-8-1)!=nero)
         mossepossibili.push_back(pos-8-1); //vado in basso a sinistra
         if (parent->getStato(pos-1)!=nero)
         mossepossibili.push_back(pos-1);  //vado a sinistra
      }
     else if (pos/8==0)  //sono in basso ma non negli angoli
      {
         for (int i=0; i<3; i++)  //vado in alto
         {
             if (parent->getStato(pos+8-1+i)!=nero)
                 mossepossibili.push_back(pos+8-1+i);
         }
         if (parent->getStato(pos-1)!=nero)      //vado a sinistra
             mossepossibili.push_back(pos-1);
         if (parent->getStato(pos+1)!=nero)      //vado a destra
             mossepossibili.push_back(pos+1);
      }
     else if (pos/8==7)  //sono in alto ma non negli angoli
      {
         for (int i=0; i<3; i++)  //vado in basso
         {
             if (parent->getStato(pos-8-1+i)!=nero)
                 mossepossibili.push_back(pos-8-1+i);
         }
         if (parent->getStato(pos-1)!=nero)      //vado a sinistra
             mossepossibili.push_back(pos-1);
         if (parent->getStato(pos+1)!=nero)      //vado a destra
             mossepossibili.push_back(pos+1);
      }
     else if (pos%8==0)  //sono a sinistra ma non negli angoli
      {
         for (int i=-1; i<2; i++)  //vado a destra
         {
             if (parent->getStato(pos+8*i+1)!=nero)
                 mossepossibili.push_back(pos+8*i+1);
         }
         if (parent->getStato(pos-8)!=nero)      //vado in basso
             mossepossibili.push_back(pos-8);
         if (parent->getStato(pos+8)!=nero)      //vado in alto
             mossepossibili.push_back(pos+8);
      }
     else if (pos%8==7)  //sono a destra ma non negli angoli
      {
         for (int i=-1; i<2; i++)  //vado a sinistra
         {
             if (parent->getStato(pos+8*i-1)!=nero)
                 mossepossibili.push_back(pos+8*i-1);
         }
         if (parent->getStato(pos-8)!=nero)      //vado in basso
             mossepossibili.push_back(pos-8);
         if (parent->getStato(pos+8)!=nero)      //vado in alto
             mossepossibili.push_back(pos+8);
      }
     else
     {
         for (int i=0; i<3; i++)  //vado in alto
         {
             if (parent->getStato(pos+8-1+i)!=nero)
                 mossepossibili.push_back(pos+8-1+i);
         }
         for (int i=0; i<3; i++)  //vado in basso
         {
             if (parent->getStato(pos-8-1+i)!=nero)
                 mossepossibili.push_back(pos-8-1+i);
         }
         if (parent->getStato(pos-1)!=nero)      //vado a sinistra
             mossepossibili.push_back(pos-1);
         if (parent->getStato(pos+1)!=nero)      //vado a destra
             mossepossibili.push_back(pos+1);
     }

 }
 vector<int> v=MoveArrocco();
 mossepossibili=mossepossibili+v;
 return mossepossibili;
}

bool Re::hasmoved() const
{
    return moved;
}

Re *Re::clone() const
{
    return new Re(*this);
}


void Re::setPosizione(const int& p)
{
    pos=p;
    if(!moved)
        moved=true;
}

vector<int> Re::MoveArrocco() const
{

   vector<int> mossepossibili;
   if (colore)
   {
       Torre* t=nullptr;
       if (parent->getStato(0)==bianco)
       t=dynamic_cast<Torre*>(parent->getPedina(0));
       if (t && !t->hasmoved() && parent->getStato(1)==none && parent->getStato(2)==none && parent->getStato(3)==none  && !moved) //arrocco a sinistra
           mossepossibili.push_back(pos-2);
       t=nullptr;
       if (parent->getStato(7)==bianco)
        t=dynamic_cast<Torre*>(parent->getPedina(7));   //arrocco a destra
       if (t && !t->hasmoved() && parent->getStato(5)==none && parent->getStato(6)==none  && !moved)
            mossepossibili.push_back(pos+2);

   }
   else  //nero
   {   Torre* t=nullptr;
       if (parent->getStato(56)==nero)
       t=dynamic_cast<Torre*>(parent->getPedina(56));
       if (t && !t->hasmoved() && parent->getStato(57)==none && parent->getStato(58)==none && parent->getStato(59)==none  && !moved) //arrocco a sinistra
           mossepossibili.push_back(pos-2);

       t=nullptr;
       if (parent->getStato(63)==nero)
       t=dynamic_cast<Torre*>(parent->getPedina(63));   //arrocco a destra
       if (t && !t->hasmoved() && parent->getStato(61)==none && parent->getStato(62)==none  && !moved)
           mossepossibili.push_back(pos+2);
   }
   return mossepossibili;
}
