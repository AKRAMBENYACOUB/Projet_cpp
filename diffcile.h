#ifndef DIFFCILE_H
#define DIFFCILE_H


#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>
#include<QLabel>
#include "deck.h"
#include "carte.h"

class Diffcile : public QWidget
{
    Q_OBJECT

public:
    Diffcile(QWidget *parent = nullptr);

private slots:
    void BoutonDeckClicke();
    void updateBoutonOrdi();
    void jeuxfini();

signals:
    checkGameFini();

public slots:
    void updateUIAfterScore();






private:
    Deck deck;
    QPushButton *bouton_deck;
    QPushButton *carte1;
    QPushButton *carte2;
    QPushButton *carte3;
    QPushButton *carte4;
    QPushButton *carte5;
    QPushButton *carte6;
    QPushButton *bouton_jouer;
    QPushButton *bouton_game1;
    QPushButton *bouton_game2;
    QPushButton *bouton_ordi;
    QLabel *score_jouer;
    QLabel *score_ordi;


    void changerCarte(QPushButton *button, const Carte &carte );
    void changeBoutonJouer(QPushButton *BoutonCarte);
    Carte getCardFromButton(QPushButton *cardButton);
    Rank getCardRank(QPushButton *cardButton);
    QPushButton* findMatchingCard(Rank targetRank);
    void gestionScore();
    void resetGame();
};

#endif // DIFFCILE_H
