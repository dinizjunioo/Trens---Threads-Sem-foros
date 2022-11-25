#include "trem.h"
#include <QtCore>
#include <iostream>
#include <semaphore.h>
//Construtor

Trem::Trem(int ID, int x, int y){

    // não é uma boa inicializar tanta coisa no construtor

    this->ID = ID;
    this->x = x;
    this->y = y;
    velocidade1 = 100;
    velocidade2 = 200;
    velocidade3 = 100;
    velocidade4 = 100;
    velocidade5 = 100;
    sem_init(&semaphore1,0,0);
}

//Função a ser executada após executar trem->START
void Trem::run(){
    while(true){
        switch(ID)
        {
        case 1:     //Trem 1

            // semaforo1 = (300,30)
            if (x >= 330-21 && y == 30)
            {//opa, t1 chegou na secao critica
               //if(x == 300 && y == 30)
               //{
                sem_wait(&semaphore1); //travo secao critica
                while(y != 150 && x >= 330-21)
                {
                    if(velocidade1 == 200){
                        // não faça nada
                        // break;
                        emit updateGUI(ID, x,y);
                    }
                    else{
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
                    }
                }
                sem_post(&semaphore1);//libero secao critica
            }
            //move(ID,x,y);
            // verificar onde ele está
            // onde_esta_o_trem1()
            // enquando o semaphoro1
            //
            if(velocidade1 == 200){  break;}
            else{
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
            }
            break;
        case 2: //Trem 2

            // ele já esta na secao na secao critica

            if((x >= 330 && x <= 330+21) && y == 30)
            {
                std::cout << "trem2 - " << x << std::endl;
                sem_wait(&semaphore1);
                while(x < 330+21)
                {
                    std::cout << "secao critica" << "- velocidade" << 200 - velocidade2 <<std::endl;

                    if(velocidade2 == 200){
                        // não faça nada
                        std::cout << "velocidade zero do trem2" << std::endl;
                        emit updateGUI(ID, x,y);
                         break;
                    }else{
                        std::cout << "aumentei a velocidade do trem2" << std::endl;

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
                    }
                }
                sem_post(&semaphore1);
            }

            //opa, t2 quer entrar na secao critica
            else if (x >= 300+21 && y == 150)
            {
               //if(x == 300 && y == 30)
               //{
               sem_wait(&semaphore1); //travo secao critica
                while(y != 30 && x >= 330-21)
                {
                    if(velocidade2 == 200){
                        emit updateGUI(ID, x,y);
                        // não faça nada
                         break;
                    }else{

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
                    }
                }
               sem_post(&semaphore1);//libero secao critica
            }

            if(velocidade2 == 200){
                // não faça nada
                 break;
            }else{

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
            }
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

void move (int id, int x, int y)
{
   /* if(velocidade1 == 200)
    {
        //nao faça nada
        //continue;
    }else{
        if (y == 30 && x <330)
            x+=10;
        else if (x == 330 && y < 150)
            y+=10;
        else if (x > 60 && y == 150)
            x-=10;
        else
            y-=10;
        emit updateGUI(id, x,y);    //Emite um sinal
        msleep(velocidade1);
    }*/
}
//void Trem::restart(int ID)
//{
//    if (ID == 1)
//        trem1->start();
//}
