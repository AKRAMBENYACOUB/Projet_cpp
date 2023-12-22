#ifndef DECK_H
#define DECK_H

#include "carte.h"
#include <vector>

class Deck
{
public:
    Deck();
    void shuffle();
    bool isEmpty() const;
    Carte DistribuerCarte();
    void resetDeck();




private:
    std::vector<Carte> cartes;
    int IndexeCarte;


};

#endif // DECK_H
