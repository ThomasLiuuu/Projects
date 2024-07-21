#ifndef __FEEBUILDING_H__
#define __FEEBUILDING_H__
#include <iostream>
#include <vector>
#include <memory>

#include "cell.h"
#include "player.h"

using namespace std;

class FeeBuilding: public Cell {
    const string type = "FB"; // 
    unique_ptr<Player> owner; // owner of the feed building
    const int purchaseCost; // pruchase cost of the building 
    int fee;
    bool isM = false;
  public:
    FeeBuilding(unique_ptr<Player> p, string name, Block b, const int purchaseCost); // constructor
    ~FeeBuilding(); // destructor
    Player& getOwner() const override; // return owner of the building
    string getType() const override; // 
    bool hasOwner() const override; // whether the building has owner

    bool isMort() const override;

    void setOwner(unique_ptr<Player> p); // set up the owner of the building
    void removeOwner(); // remove the owner 
    int getPurCost() const override; // return pruchase cost
    int getFee() const override; // return fee
    int getUpgradeCnt() const override; // return improvement cost
    void toggleMortgage() override;
    void setImp(int cnt) override {};


    friend std::ostream &operator<<(std::ostream &out, const FeeBuilding &f);
};


#endif
