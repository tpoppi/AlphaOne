#ifndef MOSSEAX_H
#define MOSSEAX_H
#include "pezzi.h"

class Mosseax : virtual public Pezzi
{
public:
    Mosseax(const bool& c,const int& p, Scacchiera* parent);
    virtual vector<int> move() const;
};


#endif // MOSSEAX_H
