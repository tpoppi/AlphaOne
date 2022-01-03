#ifndef RE_H
#define RE_H
#include "pezzi.h"
#include "scacchiera.h"

class Re : public Pezzi
{
public:
    Re(const bool& c,const int& p, Scacchiera* parent,const bool& m=false);
    vector<int> move() const;
    bool hasmoved() const;
    Re* clone() const;
   void setPosizione(const int& p);
    vector<int> MoveArrocco() const;
    private:
    bool moved=false;
};

#endif // RE_H
