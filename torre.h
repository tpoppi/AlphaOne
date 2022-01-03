#ifndef TORRE_H
#define TORRE_H
#include "mosseacroce.h"


class Torre : public mosseacroce
{
public:
    Torre(const bool& c,const int& p, Scacchiera* parent, const bool& m=false);
    bool hasmoved() const;
    Torre* clone() const;
    void setPosizione(const int& p);
private:
    bool moved;
};

#endif // TORRE_H
