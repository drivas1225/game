#include "Nave.h"

Nave::Nave()
{

}

Nave::Nave(int _x , int _y,int _corazones,int _vidas):x(_x),y(_y),corazones(_corazones),vidas(_vidas)
{

}

void Nave::gotoxy(int _x, int _y){

    HANDLE hCon;
    hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = _x;
    dwPos.Y = _y;
    SetConsoleCursorPosition(hCon,dwPos);
}

void Nave::ocultarCursor(){
    HANDLE hCon;
    hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO cci;
    cci.dwSize = 2;
    cci.bVisible = FALSE;

    SetConsoleCursorInfo(hCon,&cci);

}


void Nave::pintar()
{
    gotoxy(x,y);printf("  %c",30);
    gotoxy(x,y+1);printf(" %c%c%c",40,207,41);
    gotoxy(x,y+2);printf("%c%c %c%c",30,190,190,30);
}

void Nave::borrar()
{
    gotoxy(x,y);  printf("     ");
    gotoxy(x,y+1);printf("     ");
    gotoxy(x,y+2);printf("     ");
}
void Nave::mover()
{
    if(kbhit()){
            char tecla = getch();
            borrar();
            if(tecla == IZQUIERDA && x>3) x--;
            if(tecla == DERECHA && x+5<77) x++;
            if(tecla == ARRIBA && y>4) y--;
            if(tecla == ABAJO && y+3<33) y++;
            if(tecla=='e')corazones--;
            pintar();
            pintar_corazones();
        }
}

void Nave::pintar_corazones()
{
    gotoxy(50,2);printf("Vidas %d",vidas);
    gotoxy(64,2);printf("Salud");
    gotoxy(70,2);printf("      ");
    for(int i = 0 ;i<corazones;i++){
        gotoxy(70+i,2);printf("%c",3);
    }
}

void Nave::morir()
{
    if(corazones==0){
        borrar();
        gotoxy(x,y);    printf("  ** ");
        gotoxy(x,y+1);  printf(" ****");
        gotoxy(x,y+2);  printf("  ** ");
        Sleep(200);
        borrar();
        gotoxy(x,y);    printf("* * *");
        gotoxy(x,y+1);  printf(" *** ");
        gotoxy(x,y+2);  printf("* * *");
        Sleep(200);
        borrar();

        vidas--;
        corazones=3;
        pintar_corazones();
        pintar();

    }
}

Nave::~Nave()
{
    //dtor
}
