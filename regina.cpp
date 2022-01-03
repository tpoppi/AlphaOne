#include "regina.h"

Regina::Regina(const bool& c, const int& p, Scacchiera* parent) :Pezzi(c,p,parent),mosseacroce(c,p,parent), Mosseax(c,p,parent)
{

}

vector<int> Regina::move() const
{
    vector<int> mossepossibili=mosseacroce::move();
    vector<int> mossealfiere=Mosseax::move();
    //mossepossibili.insert(mossepossibili.begin(),mossealfiere.begin(),mossealfiere.end());
    mossepossibili=mossepossibili+mossealfiere;
    return mossepossibili;
}

Regina *Regina::clone() const
{
    return new Regina(*this);
}
