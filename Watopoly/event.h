#ifndef __EVENT_H__
#define __EVENT_H__
#include <iostream>
#include <vector>

#include "player.h"
#include "cell.h"

using namespace std;

class Event: public Cell {
    string name; // name of the event
    unique_ptr<Player> owner = nullptr; // event should never have owner
    Block b = Block::Event; // 
    const string type = "E"; // 
    int fee; // fee 
    const int boardPos; //
    bool isM = false;
  public:
    Event(string name, const int boardPos, int fee); // constructor
    ~Event(); // destructor
    int getFee() const override; // decorate on this positive ones are payments, negative ones are 
    void getMove(Player &p); // get move of the player
    void setOwner(unique_ptr<Player> p) override; // set owner 
    Player& getOwner() const override; // return owner
    string getType() const override; // 
    int getPurCost() const override; // return purchase cost
    bool hasOwner() const override; // check whether has owner
    int getUpgradeCnt() const override; // return improvement cost
    void toggleMortgage() override; // switch mortgage status
    bool isMort() const override;
    void setImp(int cnt) override {};
    
    friend std::ostream &operator<<(std::ostream &out, const Event &e);
};


#endif
