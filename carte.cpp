#include "carte.h"

Carte::Carte() : suite(InvalidSuit), rang(InvalidRank) {}

Carte::Carte(Suit suite, Rank rang) : suite(suite), rang(rang) {}

QString Carte::getImageCarte() const
{
    QString suitStr;
    QString rankStr;


    switch (suite)
    {
    case Hearts:
        suitStr = "Hearts";
        break;
    case Diamonds:
        suitStr = "Diamonds";
        break;
    case Clubs:
        suitStr = "Clubs";
        break;
    case Spades:
        suitStr = "Spades";
        break;
    }


    switch (rang)
    {
    case One:
        rankStr = "00";
        break;
    case Two:
        rankStr = "01";
        break;
    case Three:
        rankStr = "02";
        break;
    case Four:
        rankStr = "03";
        break;
    case Five:
        rankStr = "04";
        break;
    case Six:
        rankStr = "05";
        break;
    case Seven:
        rankStr = "06";
        break;
    case Ten:
        rankStr = "07";
        break;
    case Eleven:
        rankStr = "08";
        break;
    case Twelve:
        rankStr = "09";
        break;
    }


    return QString(":/picture/cards/") + rankStr + "_" + suitStr + ".gif";
}


bool Carte::isValide() const
{

    return suite != InvalidSuit && rang != InvalidRank;
}

Rank Carte::getCardRank() const
{
    return rang;
}


