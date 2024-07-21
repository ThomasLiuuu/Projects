#include "event.h"

Event::Event(string name, const int boardPos, int fee): Cell(Block::Event, name),boardPos{boardPos}, fee{fee} {}

Event::~Event(){}

int Event::getFee() const{
    return fee;
}

Player& Event::getOwner() const {
    auto res = owner.get();
    return *res;
}

bool Event::hasOwner() const {
    return owner != nullptr;
}
 void Event::setOwner(unique_ptr<Player> p) {
    // nothing happens 
 }

 int Event::getPurCost() const {
    // nothing happens 
    return 0;
 }

int Event::getUpgradeCnt() const {
    // nothing happens 
    return 0;
 }

string Event::getType() const {
    return type;
}

void Event::getMove(Player &p) {
    
}

void Event::toggleMortgage() {
    isM = !isM;
}
bool Event::isMort() const {
    return isM;
}


std::ostream &operator<<(std::ostream &out, const Event &e) {

    return out;
}
