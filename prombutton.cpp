#include "prombutton.h"

PromButton::PromButton(const char& t, const int& p, QWidget* parent) : QPushButton(parent), tipo(t), pos(p)
{
    connect (this, SIGNAL(clicked()), this, SLOT(clicked()));
}

void PromButton::clicked()
{
 emit buttonclicked(tipo, pos);
}
