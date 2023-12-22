#include "mainwindow.h"
#include<QLabel>
#include<QWidget>
#include <QVBoxLayout>
#include<QPushButton>
#include<QFrame>
#include "facile.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    this->setStyleSheet("background-color: green;"); // Set background color to navy blue

    QWidget *ma_fenetre = new QWidget(this);
    QVBoxLayout *mon_container = new QVBoxLayout(ma_fenetre);
    QLabel *mon_text = new QLabel("JEU DE CARTES Marocaine");
    QFrame *mon_image = new QFrame;
    QPushButton *bouton_difficile = new QPushButton("Difficile");
    QPushButton *bouton_facile = new QPushButton("Facile");
    QPushButton *bouton_quitter = new QPushButton("Quitter");

    bouton_facile->setFixedSize(200, 50);
    bouton_difficile->setFixedSize(200, 50);
    bouton_quitter->setFixedSize(200, 50);

    mon_image->setFixedSize(1000, 420);
    mon_image->setStyleSheet("background-image: url(:/picture/akram.jpg);");

    mon_container->addWidget(mon_text, 0, Qt::AlignCenter);
    mon_container->addSpacing(30);
    mon_container->addWidget(mon_image, 0, Qt::AlignCenter);
    mon_container->addWidget(bouton_facile, 0, Qt::AlignCenter);
    mon_container->addWidget(bouton_difficile, 0, Qt::AlignCenter);
    mon_container->addWidget(bouton_quitter, 0, Qt::AlignCenter);

    bouton_facile->setStyleSheet("QPushButton {"
                                "    background-color: white;"
                                "    color: black;"
                                "    border: 2px solid blue;"
                                "}"
                                "QPushButton:hover {"
                                "    background-color: #90EE90;"
                                "    color: white;"
                                "}"
                                "QPushButton:pressed {"
                                "    background-color: white;"
                                "    color: black;"
                                "}");

    bouton_difficile->setStyleSheet("QPushButton {"
                                    "    background-color: white;"
                                    "    color: black;"
                                    "    border: 2px solid blue;"
                                    "}"
                               "QPushButton:hover {"
                               "    background-color: #90EE90;"
                               "    color: white;"
                               "}"
                               "QPushButton:pressed {"
                               "    background-color: white;"
                               "    color: black;"
                               "}");

    bouton_quitter->setStyleSheet("QPushButton {"
                                  "    background-color: white;"
                                  "    color: black;"
                                  "    border: 2px solid blue;"
                                  "}"
                                  "QPushButton:hover {"
                                  "background-color: red;"
                                  "color: white;"
                                  "}"
                                  "QPushButton:pressed {"
                                  "    background-color: white;"
                                  "    color: black;"
                                  "}");



    mon_text->setStyleSheet("QLabel {"
                           "    font-weight: bold;"
                           "    font-size: 30px;"
                           "    color: red;"
                           "}");

    setCentralWidget(ma_fenetre);

    connect(bouton_facile, &QPushButton::clicked, this, &MainWindow::start);
    connect(bouton_difficile, &QPushButton::clicked, this, &MainWindow::start2);


}

void MainWindow::start()
{
    Facile *PageFacile = new Facile();//on cree  un nouveau objet de la classe suivante (page)
    setCentralWidget(PageFacile);//on definit le nouveau widget central a celle de la nouvelle page
    this->update();//on effectuer les modification


}

void MainWindow::start2()
{
    Diffcile *PageDifficile = new Diffcile();//on cree  un nouveau objet de la classe suivante (page)
    setCentralWidget(PageDifficile);//on definit le nouveau widget central a celle de la nouvelle page
    this->update();//on effectuer les modification


}

MainWindow::~MainWindow()
{

}


