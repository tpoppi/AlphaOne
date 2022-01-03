#ifndef MOSSEACROCE_H
#define MOSSEACROCE_H
#include "pezzi.h"

class mosseacroce: virtual public Pezzi
{
public:
    mosseacroce(const bool& c,const int& p, Scacchiera* parent);
    virtual vector<int> move() const;
};

#endif // MOSSEACROCE_H
