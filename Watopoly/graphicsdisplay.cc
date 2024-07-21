#include "graphicsdisplay.h"
#include "cell.h"
using namespace std;
GraphicsDisplay::GraphicsDisplay(vector<std::map<string, string>> m): w{2000, 700}, gd{m} {
    for(int i = 0; i < 40; i++) {   
      drawCell(i);
    }
}

void GraphicsDisplay::drawCell(int i) {
    w.fillRectangle(boardPositions[i].first, boardPositions[i].second, 100, 60, Xwindow::Green);
        if(gd[i]["name"] == "AL" || gd[i]["name"] == "ML" ) {
            w.fillRectangle(boardPositions[i].first, boardPositions[i].second, 100, 10, Xwindow::Red);
            w.drawString(boardPositions[i].first + 5, boardPositions[i].second + 25, gd[i]["name"]);

        } else if(gd[i]["name"] == "ECH" || gd[i]["name"] == "PAS" || gd[i]["name"] == "HH") {
            w.fillRectangle(boardPositions[i].first, boardPositions[i].second, 100, 10, Xwindow::Magenta);
            w.drawString(boardPositions[i].first + 5, boardPositions[i].second + 25, gd[i]["name"]);
        } else if(gd[i]["name"] == "RCH" || gd[i]["name"] == "DWE" || gd[i]["name"] == "CPH") {
            w.fillRectangle(boardPositions[i].first, boardPositions[i].second, 100, 10, Xwindow::Black);
            w.drawString(boardPositions[i].first + 5, boardPositions[i].second + 25, gd[i]["name"]);
        } else if(gd[i]["name"] == "LHI" || gd[i]["name"] == "BMH" || gd[i]["name"] == "OPT") {
            w.fillRectangle(boardPositions[i].first, boardPositions[i].second, 100, 10, Xwindow::Lightblue);
            w.drawString(boardPositions[i].first + 5, boardPositions[i].second + 25, gd[i]["name"]);
        } else if(gd[i]["name"] == "EV1" || gd[i]["name"] == "EV2" || gd[i]["name"] == "EV3") {
            w.fillRectangle(boardPositions[i].first, boardPositions[i].second, 100, 10, Xwindow::Darkgreen);
            w.drawString(boardPositions[i].first + 5, boardPositions[i].second + 25, gd[i]["name"]);
        } else if(gd[i]["name"] == "PHYS" || gd[i]["name"] == "B1" || gd[i]["name"] == "B2") {
            w.fillRectangle(boardPositions[i].first, boardPositions[i].second, 100, 10, Xwindow::Yellow);
            w.drawString(boardPositions[i].first + 5, boardPositions[i].second + 25, gd[i]["name"]);    
        } else if(gd[i]["name"] == "EIT" || gd[i]["name"] == "ESC" || gd[i]["name"] == "C2") {
            w.fillRectangle(boardPositions[i].first, boardPositions[i].second, 100, 10, Xwindow::Darkblue);
            w.drawString(boardPositions[i].first + 5, boardPositions[i].second + 25, gd[i]["name"]);
        } else if(gd[i]["name"] == "MC" || gd[i]["name"] == "DC") {
            w.fillRectangle(boardPositions[i].first, boardPositions[i].second, 100, 10, Xwindow::Pink);
            w.drawString(boardPositions[i].first + 5, boardPositions[i].second + 25, gd[i]["name"]);
        } else {
            string name = gd[i]["name"];
            // a non block building
            w.drawString(boardPositions[i].first + 5, boardPositions[i].second + 10, name);  
        }
    for(int j = 0; j < gd[i]["playerIcons"].size(); j++) {
        if(gd[i]["playerIcons"][j] == 'G') {
            w.fillGoose(boardPositions[i].first + 5 + j * 11, boardPositions[i].second + 30);           
        } else if (gd[i]["playerIcons"][j] == 'B') {
            w.fillBus(boardPositions[i].first + 5 + j * 11, boardPositions[i].second + 30);           
        }  else if (gd[i]["playerIcons"][j] == 'D'){
            w.fillDount(boardPositions[i].first + 3 + j * 12, boardPositions[i].second + 30);           
        } else if (gd[i]["playerIcons"][j] == 'P'){
            w.fillProfessor(boardPositions[i].first + 3 + j * 12, boardPositions[i].second + 30);           
        } else if (gd[i]["playerIcons"][j] == 'S'){
            w.fillStudent( boardPositions[i].first + 5 + j * 11, boardPositions[i].second + 30);           
        } else if (gd[i]["playerIcons"][j] == '$'){
            w.fillMoney(boardPositions[i].first + 5 + j * 11, boardPositions[i].second + 30);           
        } else if (gd[i]["playerIcons"][j] == 'L'){
            w.fillLaptop(boardPositions[i].first + 5 + j * 11, boardPositions[i].second + 30);           
        } else if (gd[i]["playerIcons"][j] == 'T'){
            w.fillTie(boardPositions[i].first + 5 + j * 11, boardPositions[i].second + 30);           
        }
    }

    if(gd[i]["owner"] == "G") {
            w.fillGoose(boardPositions[i].first, boardPositions[i].second + 40);           
    } else if (gd[i]["owner"] == "B") {
        w.fillBus(boardPositions[i].first, boardPositions[i].second + 40);           
    }  else if (gd[i]["owner"] == "D"){
        w.fillDount(boardPositions[i].first, boardPositions[i].second + 40);           
    } else if (gd[i]["owner"] == "P"){
        w.fillProfessor(boardPositions[i].first, boardPositions[i].second + 40);           
    } else if (gd[i]["owner"] == "S"){
        w.fillStudent(boardPositions[i].first, boardPositions[i].second + 40);           
    } else if (gd[i]["owner"] == "$"){
        w.fillMoney(boardPositions[i].first, boardPositions[i].second + 40);           
    } else if (gd[i]["owner"] == "L"){
        w.fillLaptop(boardPositions[i].first, boardPositions[i].second + 40);           
    } else if (gd[i]["owner"] == "T"){
        w.fillTie(boardPositions[i].first, boardPositions[i].second + 40);           
        }

    if(gd[i]["upgrades"] == "0") {
        } else if(gd[i]["upgrades"]  == "1") {
        w.fillToilet(boardPositions[i].first + 6, boardPositions[i].second + 40);           
        } else if(gd[i]["upgrades"] == "2") {
        w.fillToilet(boardPositions[i].first + 6, boardPositions[i].second + 40);           
        w.fillToilet(boardPositions[i].first + 12, boardPositions[i].second + 40);           
        } else if(gd[i]["upgrades"]  == "3") {
        w.fillToilet(boardPositions[i].first + 6, boardPositions[i].second + 40);           
        w.fillToilet(boardPositions[i].first + 12, boardPositions[i].second + 40);           
        w.fillToilet(boardPositions[i].first + 18, boardPositions[i].second + 40);           

        } else if(gd[i]["upgrades"]  == "4") {
        w.fillToilet(boardPositions[i].first + 6, boardPositions[i].second + 40);           
        w.fillToilet(boardPositions[i].first + 12, boardPositions[i].second + 40);           
        w.fillToilet(boardPositions[i].first + 18, boardPositions[i].second + 40);           
        w.fillToilet(boardPositions[i].first + 24, boardPositions[i].second + 40);           

        } else if(gd[i]["upgrades"]  == "5") {
        w.fillToilet(boardPositions[i].first + 6, boardPositions[i].second + 40);           
        w.fillToilet(boardPositions[i].first + 12, boardPositions[i].second + 40);           
        w.fillToilet(boardPositions[i].first + 18, boardPositions[i].second + 40);           
        w.fillToilet(boardPositions[i].first + 24, boardPositions[i].second + 40);
        w.fillCafe(boardPositions[i].first + 30, boardPositions[i].second + 40);           
        }
}

GraphicsDisplay::~GraphicsDisplay() {}

void GraphicsDisplay::notify(vector<std::map<string, string>> m, int pos) {
    gd[pos] = m[pos];
    drawCell(pos); 
}

SubscriptionType GraphicsDisplay::subType() {
  return SubscriptionType::All;
}
