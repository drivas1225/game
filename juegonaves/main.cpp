#include <iostream>
#include <stdio.h>
#include<windows.h>
#include <conio.h>
#include "Nave.h"
#include "Ast.h"
#include "Bala.h"
#include <list>
#include <vector>
#include <stdlib.h>


Nave p;


using namespace std;

void pintar_limites(){
    for(int i = 2; i < 78 ;i++){
        p.gotoxy(i,3);printf("%c",205);
        p.gotoxy(i,33);printf("%c",205);
    }
    for(int i =4;i<33;i++){
        p.gotoxy(2,i);printf("%c",186);
        p.gotoxy(77,i);printf("%c",186);
    }
    p.gotoxy(2,3);printf("%c",201);
    p.gotoxy(2,33);printf("%c",200);
    p.gotoxy(77,3);printf("%c",187);
    p.gotoxy(77,33);printf("%c",188);
}

int main()
{

    Nave n(37,30,3,3);
    n.ocultarCursor();
    pintar_limites();
    n.pintar_corazones();
    n.pintar();

    list<Ast*> a;
    list<Ast*>::iterator ita;
    for(int i = 0 ; i< 5;i++){
        a.push_back(new Ast(rand()%75+3 ,rand()%5+4));
    }

    list<Bala*> b;
    list<Bala*>::iterator it;


    bool game_over = false;
    int puntos = 0;
    while(!game_over){
        n.gotoxy(4,2);printf("puntos %d",puntos);
        if(kbhit())
        {


            char tecla = getch();
            if(tecla=='a')
                b.push_back(new Bala(n.getx()+2,n.gety()-1));
        }

        for(it = b.begin();it!=b.end();it++){
            (*it)->mover();
            if((*it)->fuera()){
                n.gotoxy((*it)->getx(),(*it)->gety()); printf(" ");
                delete(*it);
                it=b.erase(it);
            }
        }

        for(ita=a.begin();ita!=a.end();ita++){
            (*ita)->mover();
            (*ita)->choque(n);
        }

        for(ita=a.begin();ita!=a.end();ita++){
            for(it = b.begin();it!=b.end();it++){
                if((*ita)->getx()==(*it)->getx() && ((*ita)->gety()+1==(*it)->gety()||(*ita)->gety()==(*it)->gety())){
                    n.gotoxy((*it)->getx(),(*it)->gety());printf(" ");
                    delete(*it);
                    it = b.erase(it);
                    a.push_back(new Ast(rand()%74+3,4));
                    n.gotoxy((*ita)->getx(),(*ita)->gety());printf(" ");
                    delete(*ita);
                    ita= a.erase(ita);
                    puntos+=5;
                }
            }
        }

        if(n.getvidas()==0) game_over = true;
        n.morir();
        n.mover();
        Sleep(30);
    }
    return 0;
}
