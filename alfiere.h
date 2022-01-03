#ifndef ALFIERE_H
#define ALFIERE_H
#include "mosseax.h"

class Alfiere : public Mosseax
{
public:
    Alfiere(const bool& c,const int& p, Scacchiera* parent);
     Alfiere* clone() const;
};

#endif // ALFIERE_H
