#include "trem.h"
#include <QtCore>

//Construtor

Trem::Trem(int ID, int x, int y){
    this->ID = ID;
    this->x = x;
    this->y = y;
    velocidade1 = 100;
    velocidade2 = 100;
    velocidade3 = 100;
    velocidade4 = 100;
    velocidade5 = 100;
}

//Função a ser executada após executar trem->START
void Trem::run(){
    while(true){
        switch(ID)
        {
        case 1:     //Trem 1
            if (y == 30 && x <330)
                x+=10;
            else if (x == 330 && y < 150)
                y+=10;
            else if (x > 60 && y == 150)
                x-=10;
            else
                y-=10;
            emit updateGUI(ID, x,y);    //Emite um sinal
            msleep(velocidade1);
            break;
        case 2: //Trem 2
            if (y == 30 && x <600)
                x+=10;
            else if (x == 600 && y < 150)
                y+=10;
            else if (x > 330 && y == 150)
                x-=10;
            else
                y-=10;
            emit updateGUI(ID, x,y);    //Emite um sinal
            msleep(velocidade2);
            break;
        case 3: //Trem 3
            if (y == 30 && x <870)
                x+=10;
            else if (x == 870 && y < 150)
                y+=10;
            else if (x > 600 && y == 150)
                x-=10;
            else
                y-=10;
            emit updateGUI(ID, x,y);    //Emite um sinal
            msleep(velocidade3);
            break;
        case 4: //Trem 4
            if (y == 150 && x <460)
                x+=10;
            else if (x == 460 && y < 270)
                y+=10;
            else if (x > 190 && y == 270)
                x-=10;
            else
                y-=10;
            emit updateGUI(ID, x,y);    //Emite um sinal
            msleep(velocidade4);
            break;
        case 5: //Trem 5
            if (y == 150 && x <730)
                x+=10;
            else if (x == 730 && y < 270)
                y+=10;
            else if (x > 460 && y == 270)
                x-=10;
            else
                y-=10;
            emit updateGUI(ID, x,y);    //Emite um sinal
            msleep(velocidade5);
            break;
        default:
            break;
        }
    }
}


void Trem::get_velo1(int value)
{
    velocidade1 = value;
}


void Trem::get_velo2(int value)
{
    velocidade2 = value;
}

void Trem::get_velo3(int value)
{
    velocidade3 = value;
}

void Trem::get_velo4(int value)
{
    velocidade4 = value;
}

void Trem::get_velo5(int value)
{
    velocidade5 = value;
}


