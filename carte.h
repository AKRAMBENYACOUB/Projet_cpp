#ifndef CARTE_H
#define CARTE_H

#include <QString>

enum Suit
{
    Hearts,
    Diamonds,
    Clubs,
    Spades,
    InvalidSuit
};

enum Rank
{
    One,
    Two,
    Three,
    Four,
    Five,
    Six,
    Seven,
    Ten,
    Eleven,
    Twelve,
    InvalidRank
};

class Carte

{
public:
    Carte();
    Carte(Suit suite, Rank rang);
    QString getImageCarte() const;
    //QString toString() const;
    bool isValide() const;
    Rank getCardRank() const;

private:
    Suit suite;
    Rank rang;

};

#endif // CARTE_H
