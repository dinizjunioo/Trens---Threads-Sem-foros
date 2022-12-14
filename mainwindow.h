#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "trem.h"
#include <semaphore.h>
#include <pthread.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


public slots:
    void updateInterface(int,int,int);

private slots:
    //void on_pushButton_clicked();

    //void on_pushButton_2_clicked();

    //void on_Slider1_sliderReleased();
    //void restart(int ID);
    void on_Slider1_valueChanged(int value);
    void on_Slider2_valueChanged(int value);
    void on_Slider3_valueChanged(int value);
    void on_Slider4_valueChanged(int value);
    void on_Slider5_valueChanged(int value);

private:
    Ui::MainWindow *ui;
    //
    //bool stoped;
    //Cria os objetos TREM's
    Trem *trem1;
    Trem *trem2;
    Trem *trem3;
    Trem *trem4;
    Trem *trem5;
    sem_t semaphore1full, semaphore1empty, mutex;

};

#endif // MAINWINDOW_H
