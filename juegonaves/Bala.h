#ifndef BALA_H
#define BALA_H
#include <stdio.h>
#include "Nave.h"
#include <stdlib.h>


class Bala: public Nave
{
    public:
        Bala();
        Bala(int _x, int _Y);
        int getx(){return x;}
        int gety(){return y;}
        void mover();
        bool fuera();
        virtual ~Bala();

    protected:

    private:
        int x;
        int y;
};

#endif // BALA_H
