#include "trem.h"
#include <QtCore>
#include <pthread.h>
#include <iostream>
#include <semaphore.h>
#define SHARED 0
#define N 1
//Construtor

Trem::Trem(int ID, int x, int y, int velocidade, sem_t &semafore1empty,
           sem_t &semafore1full, sem_t &mutexx){

    // não é uma boa inicializar tanta coisa no construtor

    this->ID = ID;
    this->x = x;
    this->y = y;
    this->velocidade = velocidade;
    this->semaforo1empty = &semafore1empty;
    this->semaforo1full = &semafore1full;
    this->mutex = &mutexx;
    //sem_init(&semaphore1empty,SHARED,N);
    //sem_init(&semaphore1full,SHARED,SHARED);
    //sem_init(&mutex,SHARED,N);

    //pthread_mutex_init(&mutex, NULL);
}

//
Trem::~Trem()
{
    sem_destroy(mutex);
    sem_destroy(semaforo1empty);
    sem_destroy(semaforo1full);
}

//Função a ser executada após executar trem->START
void Trem::run(){
    while(true){
        switch(ID)
        {
        case 1:
            // Trem 1
            if (y <= 150 && x >= 330-21)
            {
                //opa, t1 chegou na secao critica
                std::cout << " End: " << std::endl;
                sem_wait(semaforo1full); //travo secao critica
                std::cout << " End2: " << std::endl;
                sem_wait(mutex);
                std::cout << " End3: "  << std::endl;
                std::cout << "'-coe-'" << std::endl;
                while(y <= 150 && x > 300)
                {
                    std::cout << "entrei na secao critica trem1" << std::endl;
                    if(velocidade != 200)
                    {
                        if (y == 30 && x <330)
                             x+=10;
                        else if (x == 330 && y < 150)
                             y+=10;
                        else if (x > 60 && y == 150)
                             x-=10;
                        else
                             y-=10;

                        emit updateGUI(ID, x,y);    //Emite um sinal
                        msleep(velocidade);
                    }
                }
                //pthread_mutex_unlock(&mutex);
                sem_post(mutex);//libero secao critica
                int tr5;
                sem_getvalue(semaforo1empty, &tr5);
                std::cout << "trem1-"<< tr5 << std::endl;
                if(tr5==0)sem_post(semaforo1empty);
                std::cout << tr5 << "-trem1-" << std::endl;
            }

            //
            // liberando o semaforo1
            int tr2;
            sem_getvalue(semaforo1empty,&tr2);
            if(tr2==0)sem_post(semaforo1empty);

            if(velocidade != 200)
            {
                if (y == 30 && x <330)
                     x+=10;
                else if (x == 330 && y < 150)
                     y+=10;
                else if (x > 60 && y == 150)
                     x-=10;
                else
                     y-=10;
                emit updateGUI(ID, x,y);    //Emite um sinal
                msleep(velocidade);
            }
            break;

        case 2: //Trem 2

            if((x >= 330 && x <=330+21) && (y >= 30 && y<=150))
            {
                std::cout << "entrei aqui no trem 2" << std::endl;
                //pthread_mutex_lock(&mutex);
                sem_wait(semaforo1empty);
                sem_wait(mutex);
                while((x >= 330 && x <=330+10) && (y >= 30 && y<=150))
                {
                    if(velocidade != 200)
                    {
                        if (y == 30 && x <600)
                            x+=10;
                        else if (x == 600 && y < 150)
                            y+=10;
                        else if (x > 330 && y == 150)
                            x-=10;
                        else
                            y-=10;

                        emit updateGUI(ID, x,y);    //Emite um sinal
                        msleep(velocidade);
                    }
                }
                sem_post(mutex);
                if(tr==0)sem_post(semaforo1full);
            //pthread_mutex_unlock(&mutex);
            //sem_post(&semaphore1full); //travo secao critica
            }
            std::cout << x << " " << y << std::endl;
            if(x == 360 && y == 30)
            {
                std::cout << "trem 2 saiu do semaforo: " <<tr << std::endl;
                //sem_post(&semaphore1full);
            }

            // liberando o semaforo1
            int tr;
            sem_getvalue(semaforo1full,&tr);
            if(tr==0)sem_post(semaforo1full);


            if(x == 360 && y == 150)
            {
                //int tr;
                //sem_getvalue(semaforo1full,&tr);
                //std::cout << "trem 2 quer entrar: " <<tr << std::endl;
                //sem_wait(semaforo1full);
                //sem_post(&semaphore1full);
            }

            if(velocidade != 200)
            {
                if (y == 30 && x <600)
                    x+=10;
                else if (x == 600 && y < 150)
                    y+=10;
                else if (x > 330 && y == 150)
                    x-=10;
                else
                    y-=10;

                emit updateGUI(ID, x,y);    //Emite um sinal
                msleep(velocidade);
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
            msleep(velocidade);
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
            msleep(velocidade);
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
            msleep(velocidade);
            break;
        default:
            break;
        }
    }
}


void Trem::get_velo(int value)
{
    velocidade = value;
}




//void Trem::restart(int ID)
//{
//    if (ID == 1)
//        trem1->start();
//}
