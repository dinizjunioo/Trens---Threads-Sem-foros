#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "trem.h"
#include <iostream>
#include <semaphore.h>
#define SHARED 0
#define N 1

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //Cria o trem com seu (ID, posição X, posição Y, velocidade, endereço dos semaphoros)


    sem_init(&semaphore1empty,SHARED,N);
    sem_init(&semaphore1full,SHARED,SHARED);
    sem_init(&mutex,SHARED,N);

    trem1 = new Trem(1, 60, 30,100,semaphore1empty,semaphore1full,mutex
                     );
    trem2 = new Trem(2,330, 30,200,semaphore1empty,semaphore1full,mutex);
    trem3 = new Trem(3,600, 30,100,semaphore1empty,semaphore1full,mutex);
    trem4 = new Trem(4,190,150,100,semaphore1empty,semaphore1full,mutex);
    trem5 = new Trem(5,460,150,100,semaphore1empty,semaphore1full,mutex);


    //stoped = false;
    /*
     * Conecta o sinal UPDATEGUI à função UPDATEINTERFACE.
     * Ou seja, sempre que o sinal UPDATEGUI foi chamado, será executada a função UPDATEINTERFACE.
     * Os 3 parâmetros INT do sinal serão utilizados na função.
     * Trem1 e Trem2 são os objetos que podem chamar o sinal. Se um outro objeto chamar o
     * sinal UPDATEGUI, não haverá execução da função UPDATEINTERFACE
     */
    connect(trem1,SIGNAL(updateGUI(int,int,int)),SLOT(updateInterface(int,int,int)));
    connect(trem2,SIGNAL(updateGUI(int,int,int)),SLOT(updateInterface(int,int,int)));
    connect(trem3,SIGNAL(updateGUI(int,int,int)),SLOT(updateInterface(int,int,int)));
    connect(trem4,SIGNAL(updateGUI(int,int,int)),SLOT(updateInterface(int,int,int)));
    connect(trem5,SIGNAL(updateGUI(int,int,int)),SLOT(updateInterface(int,int,int)));

    //velocidade do trem 1
    //connect(ui->Slider1, &QSlider::valueChanged,
      //      ui->label_trem1, &QLabel::setValue);

    trem1->start();
    trem2->start();
    trem3->start();
    trem4->start();
    trem5->start();
}

//Função que será executada quando o sinal UPDATEGUI for emitido
void MainWindow::updateInterface(int id, int x, int y){
    switch(id){
    case 1: //Atualiza a posição do objeto da tela (quadrado) que representa o trem1
        ui->label_trem1->setGeometry(x,y,21,17);
        break;
    case 2: //Atualiza a posição do objeto da tela (quadrado) que representa o trem2
        ui->label_trem2->setGeometry(x,y,21,17);
        break;
    case 3: //Atualiza a posição do objeto da tela (quadrado) que representa o trem3
        ui->label_trem3->setGeometry(x,y,21,17);
        break;
    case 4: //Atualiza a posição do objeto da tela (quadrado) que representa o trem4
        ui->label_trem4->setGeometry(x,y,21,17);
        break;
    case 5: //Atualiza a posição do objeto da tela (quadrado) que representa o trem5
        ui->label_trem5->setGeometry(x,y,21,17);
        break;
    default:
        break;
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

//void MainWindow::on_Slider1_sliderReleased()
//{
//}

void MainWindow::on_Slider1_valueChanged(int value)
{
    //passando velocidade para o objeto trem1
    trem1->get_velo(200 - value);
    if(200 - value == 200)
        std::cout << "trem1 == zero" << std::endl;
        //trem1->terminate();
    else {
        trem1->start();
    }
}

void MainWindow::on_Slider2_valueChanged(int value)
{
    //passando velocidade para o objeto trem1
    trem2->get_velo(200 - value);
    if(200 - value == 200);
        //trem2->terminate();
    else {
        trem2->start();
    }
}

void MainWindow::on_Slider3_valueChanged(int value)
{
    //passando velocidade para o objeto trem1
    trem3->get_velo(200 - value);
    if(200 - value == 200)
        trem3->terminate();
    else {
        trem3->start();
    }
}

void MainWindow::on_Slider4_valueChanged(int value)
{
    //passando velocidade para o objeto trem1
    trem4->get_velo(200 - value);
    if(200 - value == 200)
        //criar um booleano e usar esse terminate em algum outro lugar
        trem4->terminate();
    else {
        trem4->start();
    }
}

void MainWindow::on_Slider5_valueChanged(int value)
{
    //passando velocidade para o objeto trem1
    trem5->get_velo(200 - value);
    if(200 - value == 200)
        trem5->terminate();
    else {
        trem5->start();
    }
}


