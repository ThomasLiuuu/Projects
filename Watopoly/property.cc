#include "property.h"

using namespace std;
  
Property::Property(unique_ptr<Player> p, int upgradeCount, string name, Block b, const int purchaseCost,const int improvementCost, int tuition[6]):
    Cell(b, name), owner{std::move(p)}, upgradeCount{upgradeCount}, purchaseCost{purchaseCost}, improvementCost{improvementCost} {
    for (int i = 0; i < 6; ++i) {
        this->tuition[i] = tuition[i];
    }
}

Property::~Property() {}

Player& Property::getOwner() const {
    auto res = owner.get();
    return *res;
}

bool Property::hasOwner() const {
    return owner != nullptr;
}
void Property::setOwner(unique_ptr<Player> p) {
    owner = std::move(p);
}

void Property::removeOwner() { 
    owner.reset();
}

int  Property::getUpgradeCnt() const {
    return upgradeCount;
}

int Property::getFee() const {
    return tuition[upgradeCount];
}

int Property::getPurCost() const {
    return purchaseCost;
}

int Property::getImpCost() {
    return improvementCost;
}

string Property::getType() const {
    return type;
}

bool Property::isMort() const {
    return isM;
}

void Property::toggleMortgage() {
    isM = !isM;
}

void Property::improve(bool upgrade) {
    if (!owner) return;
    if(upgrade) {
        ++upgradeCount;
    } else {
        --upgradeCount;
    }
}

void Property::setImp(int cnt) {
    upgradeCount = cnt;
};

ostream &operator<<(std::ostream &out, const Property &p) {
    return out;
}
