#ifndef __CELL_H__
#define __CELL_H__

#include<iostream>
#include<vector>
#include <memory>
#include "observer.h"

using namespace std;

enum class Block { Arts1, Arts2, Eng, Health, Env, Sci1, Sci2, Math, Event, Res, Gym};

class Cell: public Observer {
    Block block; // which block the cell is 
    string name; // name of building at the cell
    std::vector<char>playerIcons; // which players is currently on the cell
  public:
    Cell(const Block b, string name); // constructor
    virtual ~Cell(); // destructor
    string getName() const; // return the name
    SubscriptionType subType() override;
    virtual bool isMort() const  = 0;
    virtual void toggleMortgage() = 0;
    string getPlayers() const; // return the players at the cell
    void notify(Cell &c, char icon='\0') override; // observe how many player in the cell right now, and update the line that shows what players on the cell
    virtual Player& getOwner() const = 0; // return owner of the cell
    virtual bool hasOwner() const = 0; // check whether the cell is owned by someone
    virtual void setOwner(unique_ptr<Player> p) = 0; // set up the owner of the cell
    virtual string getType() const = 0; // 
    virtual int getPurCost() const = 0; // return the purchase cost
    virtual int getFee() const = 0; // return the fee
    virtual int getUpgradeCnt() const = 0; // return improvement cost
    virtual void setImp(int cnt) = 0; // return improvement cost
    Block getBlock();
    
    friend std::ostream &operator<<(std::ostream &out, const Cell &c);
};

#endif
