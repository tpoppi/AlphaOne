#include "chessbutton.h"

ChessButton::ChessButton(const int& p,  QWidget* parent,const  int& r) : QPushButton(parent), pos(p), red(r)
{
    connect(this, SIGNAL(clicked()), this, SLOT(clicked()));
}

void ChessButton::setRed(const int& r)
{
    red=r;
}

void ChessButton::clicked()
{
 emit buttonclicked(red, pos);
}
