#include "cell.h"
#include "player.h"
#include <iostream>
#include <algorithm>
#include<vector>

using namespace std;

class Player;

Cell::Cell(const Block b, string name): block{b}, name{name} {}

Cell::~Cell(){}

string Cell::getName() const {
    return name;
}

string Cell::getPlayers() const {
    string res = "";
    for (size_t i = 0; i < playerIcons.size(); i++) { 
        res+=playerIcons[i];
    } 
    return res;
}

void Cell::notify(Cell &c, char icon) {
    // put player into the cell
    if(icon != '\0') { 
    if(std::find(playerIcons.begin(), playerIcons.end(), icon) == playerIcons.end()) {
        // add if it doesn't exist
        playerIcons.push_back(icon);
    } else {
        // delete if it exists
        auto el = std::find(playerIcons.begin(), playerIcons.end(), icon);
        playerIcons.erase(el);
        }
    }
}

 SubscriptionType Cell::subType() {
    return SubscriptionType::All;
 };

string Cell::getType() const {
    return "";
}

Block Cell::getBlock() {
    return block;
}


std::ostream &operator<<(std::ostream &out, const Cell &c) {
    out << c << endl;
    return out;
}
