#include <fstream>
#include<string>
#include<iostream>
#include "Deck.h"
#include <algorithm>

// declaring namespace and global variables
using namespace std;

string shuf;

int draw = 0;

//create a watchdog counter to end routine at too many incorrect attempts
int watchdog = 0;   
Deck Cards;


// shuffle function to randomize the deck. Seeded by time
int ShuffleYN(){
     
    cout << "Would you like to shuffle? \'Y\'(yes) or \'N\'(no): ";
    cin >> shuf;
    
// Check input syntax in order to insure proper user input

    if(shuf == "Y" || shuf == "N" || shuf == "n" || shuf == "y") {
        watchdog = 0;
        
        return 0;
    };
    cout<< "Wrong Input" << endl;

// Too many failed attempts, exit program on failure. No more than 4 attempts
    if(watchdog >= 3) {
        cout << "Too many Wrong attempts. Ending..." << endl;
        exit(EXIT_FAILURE);
    };
    watchdog++;

// Loop to begining on improper input
    ShuffleYN();
};


// Routine prompts user for draw card amount. Verifies range is met and exits program at too many attempts.
int Draw_Amount(){   

    cout << "How many cards would you like to draw? (1-52): ";
    cin >> draw;

//clear the input buffer. Prevents error on input of string and ignores up to 50 characters in the line. Without this any time a
//a string is input it will instantly fail if the string has more characters than attempts.
    cin.clear();
    cin.ignore(50,'\n');

//Range check
    if(draw >= 1 && draw <=52) {
        watchdog = 0;
        cin.clear();
        cout << '\n';
        return 0;
    };
    cout<< "Wrong Input" << endl;
//Check number of attempts does not exceed 4
    if(watchdog >= 3) {
        cout << "Too many Wrong attempts. Ending..." << endl;
        exit(EXIT_FAILURE);
    };
    watchdog++;

// Loop this upon improper syntax
    Draw_Amount();
};

// Creates all 52 possible Suit and Value combinations using the object variables from Deck.h
int MakeCards(){

// Y is the index pointer for the 52 index array Cards.cards
    int y = 0;
    while(y<=51){
// i is the index pointer for the 13 possible values of cards
        for(int i=0; i<=12; i++){
// for each value type iterate the 4 different potential suits
            for(int x=0; x<=3; x++){
                Cards.cards[y] = Cards.Values[i] + " of " + Cards.Suits[x];
                y++;
            }
        }
    }
    y = 0;

}

int main(){

//  Counter for draw (could use draw and decrement but would prefer kept seperate)
    int y = 0;
 // call routines/ functions    
    MakeCards();

    Draw_Amount();  
    
    ShuffleYN();

// Shuffle function using random_shuffle seeded with the time. 
    if(shuf == "Y"){
        srand(time(0));
        random_shuffle(&Cards.cards[0], &Cards.cards[52]);
    };
// Draw and display each of the cards drawn starting from top of the deck (index 0)
    while(y < draw){
         cout <<"\n* " << Cards.cards[y] << "\n";
         y++;
    }
    cout << "\n";
    return 0;

    
};

