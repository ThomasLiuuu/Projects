#ifndef GRAPHICSDISPLAY_H
#define GRAPHICSDISPLAY_H
#include <vector>
#include <map>
#include <memory>
#include <string>

#include "observer.h"
#include "window.h" 
#include "player.h"

using namespace std;

class Player;
class Cell;

class GraphicsDisplay : public Observer {
public:
    GraphicsDisplay(std::vector<std::map<string, string>> td); 
    ~GraphicsDisplay();     
    void notify(Cell &c, char icon){};
    SubscriptionType subType();

    void notify(vector<std::map<string, string>> m, int pos);
    void drawCell(int i);

private:
    std::vector<std::pair<int, int>> boardPositions = {
        std::make_pair(1050, 540), // OSAP
        std::make_pair(950, 540), // AL
        std::make_pair(850, 540), // SLC
        std::make_pair(750, 540), // ML
        std::make_pair(650, 540), // TUITION
        std::make_pair(550, 540), // MKV
        std::make_pair(450, 540), // ECH
        std::make_pair(350, 540), // NEEDLES
        std::make_pair(250, 540), // PAS
        std::make_pair(150, 540), // HH

        // Left column
        std::make_pair(50, 540), // TIMS
        std::make_pair(50, 480), // RCH
        std::make_pair(50, 420), // PAC
        std::make_pair(50, 360), // DWE
        std::make_pair(50, 300), // CPH
        std::make_pair(50, 240), // UWP
        std::make_pair(50, 180), // LHI
        std::make_pair(50, 120), // SLC
        std::make_pair(50, 60), // BMH
        std::make_pair(50, 0),  // OPT

        // Top row
        std::make_pair(50, 0),  // NESTING
        std::make_pair(150, 0),  // EV1
        std::make_pair(250, 0),  // NH
        std::make_pair(350, 0),  // EV2
        std::make_pair(450, 0),   // EV3
        std::make_pair(550, 0),  // V1
        std::make_pair(650, 0),   // PHYS
        std::make_pair(750, 0),   // B1
        std::make_pair(850, 0),   // CIF
        std::make_pair(950, 0),   // B2

        // right column
        std::make_pair(1050, 0),  // DC
        std::make_pair(1050, 60), // COOP
        std::make_pair(1050, 120), // MC
        std::make_pair(1050, 180), // NH
        std::make_pair(1050, 240), // REV
        std::make_pair(1050, 300), // C2
        std::make_pair(1050, 360), // SLC
        std::make_pair(1050, 420), // ESC
        std::make_pair(1050, 480), // EIT
        std::make_pair(1050, 540), // GO TO TIMS
    };
    std::vector<std::map<string, string>> gd;
    Xwindow w;
};

#endif
