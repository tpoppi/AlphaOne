#ifndef REGINA_H
#define REGINA_H
#include "mosseacroce.h"
#include "mosseax.h"


class Regina : public mosseacroce , public Mosseax
{
public:
    Regina(const bool& c,const int& p, Scacchiera* parent);
    vector<int> move() const;
    Regina* clone() const;
};

#endif // REGINA_H
