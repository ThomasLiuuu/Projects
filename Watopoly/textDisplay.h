#ifndef __TEXTDISPLAY_H__
#define __TEXTDISPLAY_H__
#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include <map>

#include "observer.h"
#include "player.h"
class Player;
class Cell;
class Board;

using namespace std;

class TextDisplay: public Observer {
    std::vector<std::map<string, string>> td;
  public:
    TextDisplay(const std::unique_ptr<Cell> tb[40]); // constructor
    void notify(Cell &c, char icon = '\0') override;
    SubscriptionType subType() override;
    ~TextDisplay(); // destructor
    string getOwnership(int idx) const;
    string getIcons(int idx) const;
    string getCellName(int idx) const;
    bool getHasLine(int idx) const;
    void printSpace(std::ostream& out, int line) const;

    // NEW
    std::vector<std::map<string, string>> getMap();

    friend std::ostream &operator<<(std::ostream &out, const TextDisplay &td);
};

#endif
