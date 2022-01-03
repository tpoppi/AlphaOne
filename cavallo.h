#ifndef CAVALLO_H
#define CAVALLO_H
#include "pezzi.h"


class Cavallo : public Pezzi
{
public:
    Cavallo(const bool& c, const int& p, Scacchiera* parent);
     vector<int> move() const;
     Cavallo* clone() const;
};

#endif // CAVALLO_H
