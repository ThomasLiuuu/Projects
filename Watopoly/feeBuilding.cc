#include "feeBuilding.h"  

using namespace std; 
   
FeeBuilding::FeeBuilding(unique_ptr<Player> p, string name, Block b, const int purchaseCost): Cell(b, name), owner{move(p)}, purchaseCost{purchaseCost} {}

FeeBuilding::~FeeBuilding() {}

Player& FeeBuilding::getOwner() const {
    auto res = owner.get();
    return *res;
}
bool FeeBuilding::hasOwner() const {
    return owner != nullptr;
}

int FeeBuilding::getPurCost() const {
    return purchaseCost;
}

int FeeBuilding::getUpgradeCnt() const {
    return 0;
}

void FeeBuilding::setOwner(unique_ptr<Player> p) {
    owner = std::move(p);
}

void FeeBuilding::removeOwner() {
    owner.reset();
}

int FeeBuilding::getFee() const {
    return fee;
}

bool FeeBuilding::isMort() const {
    return isM;
}

void FeeBuilding::toggleMortgage() {
    isM = !isM;
}

string FeeBuilding::getType() const {return type;}

ostream &operator<<(std::ostream &out, const FeeBuilding &f) {
    return out;
}
