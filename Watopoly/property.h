#ifndef __PROPERTY_H__
#define __PROPERTY_H__

#include <iostream>
#include <vector>
#include <memory>

#include "cell.h"
#include "player.h"

enum class Block;

using namespace std;

class Property: public Cell {
    const string type = "P";
    unique_ptr<Player> owner; // owner of the property
    int upgradeCount; // improvement count
    const int improvementCost; // improvement cost
    const int purchaseCost; // purchase cost
    int tuition[6]; // list of tuitions
    bool isM = false;// whether the property is mortgaged
  public:
    Property(unique_ptr<Player> p, int upgradeCount, string name, Block b, const int purchaseCost,const int improvementCost, int tuition[6]); // constructor
    ~Property(); // destructor
    Player& getOwner() const override; // return owner of the property
    string getType() const override; // returns the type of cell
    void setOwner(unique_ptr<Player> p) override; // set owner of the property
    void removeOwner(); // remove owner
    int getFee() const override; // return fee
    int getUpgradeCnt() const override; // track number of upgrades
    int getPurCost() const override; // return purchase cost
    int getImpCost(); // return improvement cost
    void improve(bool upgrade); // improve the property
    bool isMort() const override; // checks to see if mortgaged
    bool hasOwner() const override;
    void toggleMortgage() override; // change mortgaged status
    void setImp(int cnt) override;

    friend std::ostream &operator<<(std::ostream &out, const Property &p);
};

#endif
