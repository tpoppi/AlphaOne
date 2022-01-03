#include "torre.h"

Torre::Torre(const bool& c, const int& p, Scacchiera* parent, const bool &m) : Pezzi(c,p,parent), mosseacroce(c, p, parent), moved(m)
{}

bool Torre::hasmoved() const
{
    return moved;
}

Torre *Torre::clone() const
{
    return new Torre(*this);
}

void Torre::setPosizione(const int& p)
{
    pos=p;
    if (!moved)
     moved=true;
}

