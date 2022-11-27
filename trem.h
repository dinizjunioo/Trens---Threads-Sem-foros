#ifndef TREM_H
#define TREM_H

#include <QThread>


#include <semaphore.h>
#include <pthread.h>

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

    Trem(int,int,int,int,sem_t&,sem_t&,sem_t&);  //construtor
    ~Trem(); //destructor
    void run();         //função a ser executada pela thread

    // funções que recebem o valor atual do slide e assim controlam a velocidade de cada trem
    void get_velo(int value);

//Cria um sinal
signals:
    void updateGUI(int,int,int);

private:
   int x;           //posição X do trem na tela
   int y;           //posição Y do trem na tela
   int ID;          //ID do trem

   //criar uma struct depois para isso aqui
   int velocidade;  //Velocidade. É o tempo de dormir em milisegundos entre a mudança de posição do trem

   sem_t * mutex; // pointer para o mutex
   sem_t * semaforo1empty; // pointer
   sem_t * semaforo1full; // pointer

   // tratamos a primeira regiao critica nesse semaforo.
   //sem_t semaphore1full, semaphore1empty,mutex;
   //pthread_mutex_t mutex;
};

#endif // TREM_H
