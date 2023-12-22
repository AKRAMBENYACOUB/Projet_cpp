#include "facile.h"
#include <QLabel>
#include <QWidget>
#include <QVBoxLayout>
#include <QFrame>
#include<QWidget>
#include <QHBoxLayout>
#include <QPushButton>
#include <QTimer>
#include <QMessageBox>
#include <QRegularExpression>
#include <QRegularExpressionMatch>
#include <QApplication>
#include <QMetaObject>


Facile::Facile(QWidget *parent)
    : QWidget (parent)
{
   // this->setStyleSheet("background-color: #00008b;");
    QVBoxLayout *container_jeux = new QVBoxLayout(this);

    QWidget *container_ordi = new QWidget(this);
    QHBoxLayout *jouer_ordi = new QHBoxLayout(container_ordi);
    carte1 = new QPushButton;
    carte2 = new QPushButton;
    carte3 = new QPushButton;
    score_ordi = new QLabel(" SCORE ORDI : 0 ");

    score_ordi->setStyleSheet("QLabel {"
                              "    font-weight: bold;"
                              "    font-size: 30px;"
                              "     color: #8b4513;"
                              "     font-family: 'Papyrus', cursive;"
                              "}");

    carte1->setFixedSize(90, 135);
    carte2->setFixedSize(90, 135);
    carte3->setFixedSize(90, 135);

    carte1->setStyleSheet("background-color: green;"
                          "border-radius: 10px;");
    carte2->setStyleSheet("background-color: green;"
                          "border-radius: 10px;");
    carte3->setStyleSheet("background-color: green;"
                          "border-radius: 10px;");

    jouer_ordi->addWidget(carte1, 0, Qt::AlignCenter);
    jouer_ordi->addWidget(carte2, 0, Qt::AlignCenter);
    jouer_ordi->addWidget(carte3, 0, Qt::AlignCenter);
    jouer_ordi->addWidget(score_ordi, 0, Qt::AlignCenter);

    container_jeux->addWidget(container_ordi);

    QWidget *place_jeux = new QWidget(this);
    QHBoxLayout *Layout_jeux = new QHBoxLayout(place_jeux);
    bouton_deck = new QPushButton;
    bouton_jouer = new QPushButton;
    bouton_ordi = new QPushButton;
    bouton_game1 = new QPushButton;
    bouton_game2 = new QPushButton;

    bouton_deck->setFixedSize(90, 135);
    bouton_deck->setStyleSheet("background-image: url(:/picture/back.gif);"
                               "border-radius: 10px;");

    bouton_game1->setFixedSize(90, 135);
    bouton_game2->setFixedSize(90, 135);

    bouton_jouer->setFixedSize(90, 135);
    bouton_ordi->setFixedSize(90, 135);

    bouton_jouer->setStyleSheet("QPushButton {"
                                "border-radius: 10px;"
                                "background-color: green;"

                                "}");

    bouton_ordi->setStyleSheet("QPushButton {"
                              "border-radius: 10px;"
                              "background-color: green;"

                              "}");

     bouton_game1->setStyleSheet("QPushButton {"
                               "border-radius: 10px;"
                               "background-color: green;"

                               "}");
    bouton_game2->setStyleSheet("QPushButton {"
                                "border-radius: 10px;"
                                "background-color: green;"

                                "}");

    Layout_jeux->addWidget(bouton_jouer, 0, Qt::AlignRight);
    Layout_jeux->addWidget(bouton_game1, 0, Qt::AlignRight);
    Layout_jeux->addWidget(bouton_game2, 0, Qt::AlignRight);
    Layout_jeux->addWidget(bouton_ordi, 0, Qt::AlignRight);
    Layout_jeux->addWidget(bouton_deck, 0, Qt::AlignRight);



    place_jeux->setStyleSheet("QWidget {"
                            "border: 2px solid black;"
                            "border-radius: 15px;"
                            "background-image: url(:/picture/akram (3).jpg);"
                             // "background-color: blue;"


                            "}");

    container_jeux->addWidget(place_jeux, 5);



    QWidget *container_jouer = new QWidget(this);
    QHBoxLayout *jouer_1 = new QHBoxLayout(container_jouer);
    carte4 = new QPushButton;
    carte5 = new QPushButton;
    carte6 = new QPushButton;
   score_jouer = new QLabel(" SCORE JOUER: 0 ");

    score_jouer->setStyleSheet("QLabel {"
                              "    font-weight: bold;"
                              "    font-size: 30px;"
                              "     color: #8b4513;"
                              "     font-family: 'Papyrus', cursive;"
                              "}");

    carte4->setFixedSize(90, 135);
    carte5->setFixedSize(90, 135);
    carte6->setFixedSize(90, 135);

    carte4->setStyleSheet("background-color: green;"
                          "border-radius: 10px;");
    carte5->setStyleSheet("background-color: green;"
                          "border-radius: 10px;");
    carte6->setStyleSheet("background-color: green;"
                          "border-radius: 10px;");

    jouer_1->addWidget(carte4, 0, Qt::AlignCenter);
    jouer_1->addWidget(carte5, 0, Qt::AlignCenter);
    jouer_1->addWidget(carte6, 0, Qt::AlignCenter);
    jouer_1->addWidget(score_jouer, 0, Qt::AlignCenter);

  container_jeux->addWidget(container_jouer);

  connect(bouton_deck, &QPushButton::clicked, this, &Facile::BoutonDeckClicke);

  connect(carte4, &QPushButton::clicked, this, [this]() { changeBoutonJouer(carte4); updateBoutonOrdi();});
  connect(carte5, &QPushButton::clicked, this, [this]() { changeBoutonJouer(carte5); updateBoutonOrdi();});
  connect(carte6, &QPushButton::clicked, this, [this]() { changeBoutonJouer(carte6); updateBoutonOrdi();});

   connect(this, &Facile::checkGameFini, this, &Facile::jeuxfini);


}

void Facile::BoutonDeckClicke()
{
  //const int numCardsToDeal = 8;
  const int delayIncrement = 200; // milliseconds
  int currentDelay = 200;



  // Deal the highest cards to card_11, card_22, and card_33
  for (int i = 0; i < 8; ++i)
  {
      QTimer::singleShot(currentDelay, [this, i]() {
          // Deal a random card from the deck
          Carte Cartedistribuer = deck.DistribuerCarte();

          // Update the corresponding card button
          switch (i)
          {
          case 0:
              changerCarte(carte4, Cartedistribuer);
              break;
          case 1:
              changerCarte(carte5, Cartedistribuer);
              break;
          case 2:
              changerCarte(carte6, Cartedistribuer);
              break;
          case 3:
              changerCarte(carte1, Cartedistribuer);

              break;
          case 4:
              changerCarte(carte2, Cartedistribuer);


              break;
          case 5:
              changerCarte(carte3, Cartedistribuer);


              break;
          case 6:
              changerCarte(bouton_game1, Cartedistribuer);
              break;
          case 7:
              changerCarte(bouton_game2, Cartedistribuer);
              break;
          }
      });

      // Increment the delay for the next card
      currentDelay += delayIncrement;
  }
}


// Assuming the header files are properly included

  void Facile::changerCarte(QPushButton *button, const Carte &carte)
  {
      // Update the appearance of the button based on the dealt card
      button->setFixedSize(90, 135);
      button->setStyleSheet(QString("background-image: url(%1);").arg(carte.getImageCarte()));



   }

  void Facile::changeBoutonJouer(QPushButton *BoutonCarte)
  {
      // Set the playerButton's background image based on the clicked card
      QString backgroundImage = BoutonCarte->styleSheet();
      backgroundImage.replace("background-image:", "").trimmed(); // Remove "background-image:" and trim spaces

      // Set the playerButton's background image
      bouton_jouer->setStyleSheet(QString("background-image: %1;").arg(backgroundImage));

      // Reset the clicked card's background image to the default
      //cardButton->setStyleSheet("background-image: url(:/image/blank.gif);");
      BoutonCarte->setStyleSheet("background-color: green;");

  }

  void Facile::updateBoutonOrdi()
  {
      // Check if playerButton has a background image or color
     // bool hasBackgroundImage = bouton_jouer->styleSheet().contains("background-image");
     // bool hasBackgroundColor = bouton_jouer->styleSheet().contains("background-color");

      //if (hasBackgroundImage && !hasBackgroundColor)
     // {
      // Get the rank of the card clicked by the player
      Rank playerCardRank = getCardRank(bouton_game2);

      // Find a card with a matching rank among card_1, card_2, card_3, and card_4
      QPushButton* compCardButton = findMatchingCard(playerCardRank);

      // If no matching card is found, use the first card among card_1, card_2, card_3, and card_4
      if (!compCardButton)
      {
          // Find the first available card among card_1, card_2, card_3, and card_4
                  Rank cardRank1 = getCardRank(carte1);
                  Rank cardRank2 = getCardRank(carte2);
                  Rank cardRank3 = getCardRank(carte3);


                      if (cardRank1 != playerCardRank && cardRank1 != InvalidRank)
                      {
                          compCardButton = carte1;
                      }else if (cardRank2 != playerCardRank && cardRank2 != InvalidRank)
                      {
                         compCardButton = carte2;
                      }else if (cardRank3 != playerCardRank && cardRank3 != InvalidRank)
                      {
                         compCardButton = carte3;
                      }




      }

      // Update compButton with the chosen card
      if (compCardButton)
      {
          QTimer::singleShot(800, [this, compCardButton]() {
              // Check if playerButton still has a background image before updating compButton
            //  if (bouton_game2->styleSheet().contains("background-image"))
             // {
                  // Use the stored image style for compButton
                  bouton_ordi->setStyleSheet(compCardButton->styleSheet());

                  // Update the corresponding card button to the default blank image
                  compCardButton->setStyleSheet("background-color: green;");
                  gestionScore();
             // }
          });
      }
     // }
      // If playerButton has a background color, do nothing
  }
// Cette fonction permet de prendre l'image d'une carte qui est dans un bouton
  Carte Facile::getCardFromButton(QPushButton *cardButton)
  {
      // Extract the rank and suit from the background image path
      QString imagePath = cardButton->styleSheet();
      imagePath.replace("background-image:", "").trimmed(); // Remove "background-image:" and trim spaces

      QRegularExpression regex(":/picture/cards/(\\d+)_(\\w+).gif");
      QRegularExpressionMatch match = regex.match(imagePath);

      if (match.hasMatch())
      {
      // Convert the matched strings to Rank and Suit enums

      Rank rang = static_cast<Rank>(match.captured(1).toInt());
      Suit suite;
      QString suitStr = match.captured(2);
      if (suitStr == "Hearts")
          suite = Hearts;
      else if (suitStr == "Diamonds")
          suite = Diamonds;
      else if (suitStr == "Clubs")
          suite = Clubs;
      else if (suitStr == "Spades")
          suite = Spades;

      // Create and return the Card object
      return Carte(suite, rang);
      }


      return Carte(); // Return a default-constructed Card if not matched
  }

  Rank Facile::getCardRank(QPushButton *cardButton)
  {
      Carte carte = getCardFromButton(cardButton);
      return carte.getCardRank();
  }

  QPushButton* Facile::findMatchingCard(Rank targetRank)
  {
      // Find a card with the target rank among card_1, card_2, card_3, and card_4
      for (QPushButton* cardButton : {carte1, carte2, carte3})
      {
      Rank cardRank = getCardRank(cardButton);
      if (cardRank == targetRank)
      {
          return cardButton;
      }
      }

      return nullptr; // No matching card found
  }

  void Facile::gestionScore()
 {
      // Get the ranks of the cards in compButton and playerButton
      Rank compCard1 = getCardRank(bouton_ordi);
      Rank compCard2 = getCardRank(bouton_game2);
      Rank playerCard1 = getCardRank(bouton_jouer);
      Rank playerCard2 = getCardRank(bouton_game1);

      // Compare the ranks and update scores
      if (compCard1 == compCard2 && playerCard1 != playerCard2 )
      {
      // Ranks are equal, update comp_score
      int currentCompScore = score_ordi->text().split(":").back().trimmed().toInt();
      score_ordi->setText(" SCORE ORDI : " + QString::number(currentCompScore + 1));

      score_ordi->setStyleSheet("QLabel {"
                                "    font-weight: bold;"
                                "    font-size: 30px;"
                                "     color: #8b4513;"
                                "    font-family: 'Papyrus', cursive;"
                                "}");
      // Add an 800 ms delay before updating both playerButton and compButton
      QTimer::singleShot(800, [this]() {
      QMetaObject::invokeMethod(this, "updateUIAfterScore", Qt::QueuedConnection);
      });
      }
     else if (playerCard1 == playerCard2 && compCard1 != compCard2 || playerCard1 == compCard2)
      {
      // Ranks are not equal, update player_score
      int currentPlayerScore = score_jouer->text().split(":").back().trimmed().toInt();
      score_jouer->setText("SCORE JOUER: " + QString::number(currentPlayerScore + 1));

      score_jouer->setStyleSheet("QLabel {"
                                 "    font-weight: bold;"
                                 "    font-size: 30px;"
                                 "     color: #8b4513;"
                                 "     font-family: 'Papyrus', cursive;"
                                 "}");
      // Add an 800 ms delay before updating both playerButton and compButton
      QTimer::singleShot(800, [this]() {
      QMetaObject::invokeMethod(this, "updateUIAfterScore", Qt::QueuedConnection);
      });

      }
      else if (playerCard1 == playerCard2 && compCard1 == compCard2)
      {
      // Ranks are not equal, update player_score
      int currentPlayerScore = score_jouer->text().split(":").back().trimmed().toInt();
      score_jouer->setText("SCORE JOUER: " + QString::number(currentPlayerScore + 1));

      score_jouer->setStyleSheet("QLabel {"
                                 "    font-weight: bold;"
                                 "    font-size: 30px;"
                                 "     color: #8b4513;"
                                 "    font-family: 'Papyrus', cursive;"
                                 "}");
      int currentCompScore = score_ordi->text().split(":").back().trimmed().toInt();
      score_ordi->setText(" SCORE ORDI : " + QString::number(currentCompScore + 1));

      score_ordi->setStyleSheet("QLabel {"
                                "    font-weight: bold;"
                                "    font-size: 30px;"
                                "     color: #8b4513;"
                                "     font-family: 'Papyrus', cursive;"
                                "}");


      // Add an 800 ms delay before updating both playerButton and compButton
      QTimer::singleShot(800, [this]() {
          QMetaObject::invokeMethod(this, "updateUIAfterScore", Qt::QueuedConnection);


      });

      }
      else{

      QTimer::singleShot(800, [this]() {
          bouton_ordi->setStyleSheet("background-color: green;");
          bouton_jouer->setStyleSheet("background-color: green;");
      });
      }

      jeuxfini();

      emit checkGameFini();

 }

 void Facile::jeuxfini()
 {
      static int numComparisons = 0;

      // Increment the number of comparisons
      numComparisons++;

      // Check if 20 comparisons have been reached
      if (numComparisons >= 30)
      {
      // Display a message box indicating game over
      QString winnerMessage;
      int compScore = score_ordi->text().split(":").back().trimmed().toInt();
      int playerScore = score_jouer->text().split(":").back().trimmed().toInt();

      if (compScore > playerScore)
      {
          winnerMessage = "Jeux Fini! ORDI Gagnant!";
      }
      else if (compScore < playerScore)
      {
          winnerMessage = "Jeux Fini! JOUER Gagnant!";
      }
      else
      {
          winnerMessage = "Jeux Fini! C'est paree!";
      }

      QMessageBox gameOverMessageBox;
      gameOverMessageBox.setWindowTitle("JEUX FINI");
      gameOverMessageBox.setText(winnerMessage);
      gameOverMessageBox.setStandardButtons(QMessageBox::Retry | QMessageBox::Abort);

      int result = gameOverMessageBox.exec();

      // Handle the user's choice
      if (result == QMessageBox::Retry)
      {
          numComparisons = 0;
          resetGame();
      }
      else if (result == QMessageBox::Abort)
      {
          // Quit the game
          QApplication::quit();
      }
      }
 }

 void Facile::resetGame()
 {
      // Reset all variables and UI elements to their initial state

      // Reset scores
      score_ordi->setText(" SCORE ORDI: 0 ");
      score_jouer->setText(" SCORE JOUER: 0 ");

      // Reset card buttons
      carte1->setStyleSheet("background-color: green;");
      carte2->setStyleSheet("background-color: green;");
      carte3->setStyleSheet("background-color: green;");


      carte4->setStyleSheet("background-color: green;");
      carte5->setStyleSheet("background-color: green;");
      carte6->setStyleSheet("background-color: green;");

      bouton_game1->setStyleSheet("background-color: green;");
      bouton_game2->setStyleSheet("background-color: green;");


      // Reset deck button
      bouton_deck->setStyleSheet("background-image: url(:/picture/back.gif);");

      // Reset player and computer buttons
      bouton_jouer->setStyleSheet("background-image: none;");
      bouton_ordi->setStyleSheet("background-image: none;");

      // Reset the deck
      deck.resetDeck();
 }

 void Facile::updateUIAfterScore()
 {
      bouton_ordi->setStyleSheet("background-color: green;");
      bouton_jouer->setStyleSheet("background-color: green;");
 }
