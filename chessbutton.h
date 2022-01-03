#ifndef CHESSBUTTON_H
#define CHESSBUTTON_H

#include <QPushButton>

class ChessButton : public QPushButton
{
    Q_OBJECT
public:
    ChessButton(const int& p, QWidget* parent=nullptr,const int& r=-1);
    void setRed(const int& r) ;
private:
    int pos;
    int red;
signals:
    void buttonclicked(int r, int pos);
public slots:
   void clicked();
};

#endif // CHESSBUTTON_H
