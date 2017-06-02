#ifndef NAVE_H
#define NAVE_H
#include <iostream>
#include <stdio.h>
#include<windows.h>
#include <conio.h>

#define ARRIBA 72
#define IZQUIERDA 75
#define DERECHA 77
#define ABAJO 80




using namespace std;



class Nave
{
    public:
        Nave();
        Nave(int _x , int _y, int _corazones, int _vidas);
        int getx(){return x;}
        int gety(){return y;}
        int getvidas(){return vidas;}
        void cor(){corazones--;}
        void gotoxy(int _x, int _y);
        void ocultarCursor();
        void pintar();
        void borrar();
        void mover();
        void pintar_corazones();
        void morir();
        virtual ~Nave();

    protected:

    private:
        int x;
        int y;
        int corazones;
        int vidas;
};



#endif // NAVE_H
