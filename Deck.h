// Creating a header file
#ifndef Deck_H
#define Deck_H

// Creating a class to use in other files
using namespace std;
class Deck{
    public:
        static string Suits[4] ;
        static string Values[13];
        string cards [52];

};

//Defining the values and suits possible for a deck.
string Deck::Suits[] = {"Diamonds", "Clubs", "Spades", "Hearts"};
string Deck::Values[] =  {"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King"};

#endif