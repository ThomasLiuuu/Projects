#ifndef __BOARD_H__
#define __BOARD_H__
#include <iostream>
#include <vector>
#include <memory>
#include <map>
#include <fstream>

#include "textDisplay.h"
#include "graphicsdisplay.h"
#include "property.h"
#include "player.h"
#include "cell.h"

class TextDisplay;
class Property;
class Player;
class Cell;

using namespace std;

class Board {
    unique_ptr<Cell> theBoard[40];  // The actual board.
    unique_ptr<TextDisplay> td; // The text display.
    unique_ptr<GraphicsDisplay> gd; // The text display.
    int playerCount; // number of player
    vector<Player> playerList; // player list
    int turn; // the index of playerList's turn
    bool canCurPlayerRoll; // tracks if current player can roll
    int totalTimsCup = 0; // total Tims Cup giving out
    bool useX11;

  public:
    Board(bool useX11); // constructor
    ~Board(); // destructor
    bool hasWinner(); // check if the game only have one player left, if so, the game ended, and the last player is the winner
    int rollDie(int val=6); // roll die
    void addPlayer(Player &p); // add one extra player to the game
    Player getPlayer(int idx); // return the player using idx
    Player getPlayer(string name); // return the player using the name
    Player& curPlayer(); // gets the current player given turn
    int die1 = 6;
    int die2 = 6;
    // Cell getCell(int pos); // return the cell at that position 
    // Cell getCell(string name); // overload for getting named cells
    string getType(int i); // return the type of cell on a board index

    int getPlayerCount(); // return the number of players
    int getTurn(); // get the player's turn
    void setDie(int d1, int d2);
    void nextTurn(); // check if all players rolled
    void loadGame(ifstream &in); // load previous stored game 
    void printAll(); // lists the property of all players
    void init(); // initialize the board
    void buyImp(string name); // buy improvement
    void sellImp(string name); // sell improvement
    void bankrupt(); // bankrupt
    void mort(string property); // mortgage property
    void unmort(string property); // unmortgage property
    void save(string filename); // save the game
    void move(); // move player
    void trade(string name, string give, string recieve); // trade with another player
    void toggleCanRoll(); // modify whether the player can still roll dice
    void buy(); // buy property
    //   piece       property, value
    map<char, map<string, int>> getAssets(); // return map of asset
    void playerAsset();
    void auction(string property); // start an aution
    void propGymRezFee(int grid, int dieSum); // when player who is not the owner landed on the cell, charge him fee

    friend std::ostream &operator<<(std::ostream &out, const Board &b);
};

#endif
