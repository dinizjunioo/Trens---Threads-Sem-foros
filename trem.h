#ifndef TREM_H
#define TREM_H

#include <QThread>


#include <semaphore.h>


/*
 * Classe Trem herda QThread
 * Classe Trem passa a ser uma thread.
 * A função START inicializa a thread. Após inicializada, a thread irá executar a função RUN.
 * Para parar a execução da função RUN da thread, basta executar a função TERMINATE.
 *
*/
class Trem: public QThread{
 Q_OBJECT
public:

    Trem(int,int,int);  //construtor
    void run();         //função a ser executada pela thread

    // funções que recebem o valor atual do slide e assim controlam a velocidade de cada trem
    void get_velo1(int value);
    void get_velo2(int value);
    void get_velo3(int value);
    void get_velo4(int value);
    void get_velo5(int value);
    void move(int,int,int);
//Cria um sinal
signals:
    void updateGUI(int,int,int);

private:
   int x;           //posição X do trem na tela
   int y;           //posição Y do trem na tela
   int ID;          //ID do trem

   //criar uma struct depois para isso aqui
   int velocidade1;  //Velocidade. É o tempo de dormir em milisegundos entre a mudança de posição do trem
   int velocidade2;
   int velocidade3;
   int velocidade4;
   int velocidade5;

   // tratamos a primeira regiao critica nesse semaforo.
   sem_t semaphore1;
};

#endif // TREM_H
