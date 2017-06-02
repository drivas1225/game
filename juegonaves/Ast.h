#ifndef AST_H
#define AST_H
#include <stdio.h>
#include "Nave.h"
#include <stdlib.h>


class Ast : public Nave
{
    public:
        Ast();
        Ast(int _x,int _y);
        int getx(){return x;}
        int gety(){return y;}
        void pintar();
        void mover();
        void choque(Nave &n);
        virtual ~Ast();

    protected:

    private:
        int x;
        int y;
};

#endif // AST_H
