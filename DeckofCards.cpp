#include <fstream>
#include<string>
#include<iostream>
#include "Deck.h"
#include <algorithm>
#include <cstdlib>

using namespace std;

string shuf;

int draw = 0;
int watchdog = 0;   
Deck Cards;

int ShuffleYN(){
     
    cout << "Would you like to shuffle? \'Y\'(yes) or \'N\'(no): ";
    
    cin.clear();

    cin >> shuf;
    if(shuf == "Y" || shuf == "N") {
        watchdog = 0;
        cin.clear();
        return 0;
    };
    cout<< "Wrong Input" << endl;
    if(watchdog >= 3) {
        cout << "Too many Wrong attempts. Ending..." << endl;
        exit(EXIT_FAILURE);
    };
    watchdog++;
    ShuffleYN();
};

int Draw_Amount(){   

    cout << "How many cards would you like to draw? (1-52): ";
    cin.clear();
    cin >> draw;
    if(draw >= 1 && draw <=52) {
        watchdog = 0;
        cin.clear();
        cout << '\n';
        return 0;
    };
    cout<< "Wrong Input" << endl;
    if(watchdog >= 3) {
        cout << "Too many Wrong attempts. Ending..." << endl;
        exit(EXIT_FAILURE);
    };
    watchdog++;
    Draw_Amount();
};

int MakeCards(){
    int y = 0;
    while(y<=51){
        for(int i=0; i<=12; i++){
            for(int x=0; x<=3; x++){
                Cards.cards[y] = Cards.Values[i] + " of " + Cards.Suits[x];
                y++;
            }
        }
    }
    y = 0;

}

int main(){
    
    int y = 0;
    
    MakeCards();

    Draw_Amount();  
    
    ShuffleYN();
    
    if(shuf == "Y"){
        srand(time(0));
        random_shuffle(&Cards.cards[0], &Cards.cards[52]);
    };
    while(y < draw){
         cout <<"\n* " << Cards.cards[y] << "\n";
         y++;
    }
    cout << "\n";
    return 0;

    
};

