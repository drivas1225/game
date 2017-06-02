#include "Ast.h"

Ast::Ast()
{
    //ctor
}
Ast::Ast(int _x,int _y):x(_x),y(_y)
{

}
void Ast::pintar()
{
    gotoxy(x,y);printf("%c",184);
}
void Ast::mover()
{
    gotoxy(x,y);printf(" ");
    y++;
    if(y>32){
        x = rand()%71+4;
        y = 4;
    }
    pintar();
}

void Ast::choque(Nave &n)
{
    if(x>=n.getx() && x < n.getx()+5 && y >= n.gety()&& y <=n.gety()){
        n.cor();
        n.borrar();
        n.pintar();
        n.pintar_corazones();
        x = rand()%71+4;
        y = 4;
    }
}

Ast::~Ast()
{
    //dtor
}
