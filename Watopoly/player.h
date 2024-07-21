#ifndef __PLAYER_H__
#define __PLAYER_H__
#include <iostream>
#include <vector>

using namespace std;

class Player {
    string name; // name of the player
    char gamePiece; // in game name
    int balance; // balance the player holds
    int position; // position of the player on the board
    int DCTimsTime = 0;
    int rimCup = 0;
    bool sentToDCTims = false;
  public:
    Player(string name, char gamePiece, int balance, int position); // constructor
    ~Player(); // destructor
    int getBalance(); // return balanace the player has
    void move(int shift); // move the player
    void setPos(int pos);
    string getName(); // return the name of the player
    char getPiece(); // get game piece of player
    int getPos(); // return position of the player
    void give(int g); // give away money
    void receive(int r); // receive money
    bool inLine(); 
    void toggleLine(bool val);
    void changeCup(int num);
    void setTimsTime(int val);
    int getTimsTime();
    int getRimCup();
    

    friend std::ostream &operator<<(std::ostream &out, const Player &p);
};

#endif
