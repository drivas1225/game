#include "Bala.h"

Bala::Bala()
{
    //ctor
}

Bala::Bala(int _x, int _y):x(_x),y(_y)
{

}

void Bala::mover()
{
    gotoxy(x,y);printf(" ");
    y--;
    gotoxy(x,y);printf("*");
}

bool Bala::fuera()
{
    if(y==4) return true;
    return false;

}

Bala::~Bala()
{
    //dtor
}
