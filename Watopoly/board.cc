#include "board.h"
#include "feeBuilding.h"
#include "event.h"
#include <stdlib.h>
#include <sstream>
#include <sys/types.h>
#include <unistd.h>
#include <memory>
#include <ctime>

using namespace std;

Board::Board(bool useX11): playerCount{0}, turn{0}, canCurPlayerRoll{true}, useX11{useX11} {
    init();
}

void Board::setDie(int d1, int d2) {
    die1 = d1;
    die2 = d2;
}

void Board::init() {
    // call functions to setup all grids on board
    // start point / collect OSAP
    theBoard[0] = std::unique_ptr<Cell>(new Event("Collect OSAP", 0, -200));
    // AL
    int t1[6] = {2,10,30,90,160,250};
    theBoard[1]= std::unique_ptr<Cell>(new Property(nullptr, 0, "AL", Block::Arts1, 40, 50, t1));
    // SLC
    theBoard[2] = std::unique_ptr<Cell>(new Event("SLC", 0, -200));
    // ML
    int  t2[6] = {4,20,60,180,320,450};
    theBoard[3]= std::unique_ptr<Cell>(new Property(nullptr, 0, "ML", Block::Arts1, 60, 50, t2));
    // Tuition
    theBoard[4] = std::unique_ptr<Cell>(new Event("Tuition", 4, -200));
    // MKV
    theBoard[5] = std::unique_ptr<Cell>(new FeeBuilding(nullptr, "MKV", Block::Res, 200));
    // ECH
    int t3[6] = {6,30,90,270,400,550};
    theBoard[6]= std::unique_ptr<Cell>(new Property(nullptr, 0, "ECH", Block::Arts2, 100, 50, t3));
    // NH
    theBoard[7] = std::unique_ptr<Cell>(new Event("Needles Hall", 7, -200));
    // PAS
    theBoard[8]= std::unique_ptr<Cell>(new Property(nullptr, 0, "PAS", Block::Arts2, 100, 50, t3));
    // HH
    int t4[6] = {8,40,100,300,450,600};
    theBoard[9]= std::unique_ptr<Cell>(new Property(nullptr, 0, "HH", Block::Arts2, 120, 50, t4));
    // DC Tims Line
    theBoard[10] = std::unique_ptr<Cell>(new Event("DC Tims Line", 10, -200));
    // RCH
    int t5[6] = {10,50,150,450,625,750};
    theBoard[11]= std::unique_ptr<Cell>(new Property(nullptr, 0, "RCH", Block::Eng, 140, 50, t5));
    // PAC
    theBoard[12] = std::unique_ptr<Cell>(new FeeBuilding(nullptr, "PAC", Block::Gym, 150));
    // DWE
    theBoard[13]= std::unique_ptr<Cell>(new Property(nullptr, 0, "DWE", Block::Eng, 140, 50, t5));
    // CPH
    int t6[6] = {12,60,180,500,700,900};
    theBoard[14]= std::unique_ptr<Cell>(new Property(nullptr, 0, "CPH", Block::Eng, 160, 50, t6));
    // UWP
    theBoard[15] = std::unique_ptr<Cell>(new FeeBuilding(nullptr, "UWP", Block::Res, 200));
    // LHI
    int t7[6]  ={14,70,200,550,750,950};
    theBoard[16]= std::unique_ptr<Cell>(new Property(nullptr, 0, "LHI", Block::Health, 180, 100, t7));
    // SLC
    theBoard[17] = std::unique_ptr<Cell>(new Event("SLC", 0, -200));
    // BMH
    theBoard[18]= std::unique_ptr<Cell>(new Property(nullptr, 0, "BMH", Block::Health, 180, 100, t7));
    // OPT
    int t8[6] = {16,80,220,600,800,1000};
    theBoard[19]= std::unique_ptr<Cell>(new Property(nullptr, 0, "OPT", Block::Health, 200, 100, t8));
    // Goose Nesting
    theBoard[20] = std::unique_ptr<Cell>(new Event("Goose Nesting", 20, 0));
    // EV1
    int t9[6] = {18,90,250,700,875,1050};
    theBoard[21]= std::unique_ptr<Cell>(new Property(nullptr, 0, "EV1", Block::Env, 220, 150, t9));
    // NH
    theBoard[22] = std::unique_ptr<Cell>(new Event("Needles Hall", 22, -200));
    // EV2
    theBoard[23]= std::unique_ptr<Cell>(new Property(nullptr, 0, "EV2", Block::Env, 220, 150, t9));
    // EV3
    int t10[6] = {20,100,300,750,925,1100};
    theBoard[24]= std::unique_ptr<Cell>(new Property(nullptr, 0, "EV3", Block::Env, 240, 150, t10));
    // V1
    theBoard[25] = std::unique_ptr<Cell>(new FeeBuilding(nullptr, "V1", Block::Res, 200));
    // PHYS
    int t11[6] = {22,110,330,800,975,1150};
    theBoard[26]= std::unique_ptr<Cell>(new Property(nullptr, 0, "PHYS", Block::Sci1, 260, 150, t11));
    // B1
    theBoard[27]= std::unique_ptr<Cell>(new Property(nullptr, 0, "B1", Block::Sci1, 260, 150, t11));
    // CIF
    theBoard[28] = std::unique_ptr<Cell>(new FeeBuilding(nullptr, "CIF", Block::Gym, 150));
    // B2
    int t12[6] = {24,120,360,850,1025,1200};
    theBoard[29]= std::unique_ptr<Cell>(new Property(nullptr, 0, "B2", Block::Sci1, 280, 150, t12));
    // Go to Tims
    theBoard[30] = std::unique_ptr<Cell>(new Event("Go to Tims", 10, 0));
    // EIT
    int t13[6] = {26,130,390,900,1100,1275};
    theBoard[31]= std::unique_ptr<Cell>(new Property(nullptr, 0, "EIT", Block::Sci2, 300, 200, t13));
    // ESC
    theBoard[32]= std::unique_ptr<Cell>(new Property(nullptr, 0, "ESC", Block::Sci2, 300, 200, t13));
    // SLC
    theBoard[33] = std::unique_ptr<Cell>(new Event("SLC", 0, -200));
    // C2
    int t14[6] = {28,150,450,1000,1200,1400};
    theBoard[34]= std::unique_ptr<Cell>(new Property(nullptr, 0, "C2", Block::Sci2, 320, 200, t14));
    // REV
    theBoard[35] = std::unique_ptr<Cell>(new FeeBuilding(nullptr, "REV", Block::Res, 200));
    // NH
    theBoard[36] = std::unique_ptr<Cell>(new Event("Needles Hall", 36, -200));
    // MC
    int t15[6] =  {35,175,500,1100,1300,1500};
    theBoard[37]= std::unique_ptr<Cell>(new Property(nullptr, 0, "MC", Block::Math, 350, 200, t15));
    // CO-OP Fee
    theBoard[38] = std::unique_ptr<Cell>(new Event("CO-OP Fee", 10, 150));
    // DC
    int t16[6] = {50,200,600,1400,1700,2000};
    theBoard[39]= std::unique_ptr<Cell>(new Property(nullptr, 0, "DC", Block::Math, 400, 200, t16)); 

    td = std::make_unique<TextDisplay>(std::cref(theBoard));
    if(useX11) {
        gd = std::make_unique<GraphicsDisplay>(td.get()->getMap());
    }
}

Board::~Board() { }

bool Board::hasWinner() { return playerCount == 1;}

int Board::rollDie(int val) { 
    int randomNum = rand(); 
    return (randomNum % val) + 1;
}

int Board::getTurn() {return turn;}

void Board::nextTurn() {
    // 
    if(!theBoard[curPlayer().getPos()].get()->hasOwner() 
    && theBoard[curPlayer().getPos()].get()->getType() != "E") {
        cout <<"The current cell is undergoing auction because " << curPlayer().getName() << " did not buy it!"<< endl;
        auction(theBoard[curPlayer().getPos()].get()->getName());
    } else {
       if(turn == playerCount - 1) {
        turn = 0;
    } else{
        ++turn;
        }
    }
    toggleCanRoll();
}

void Board::addPlayer(Player &p) {
    playerList.emplace_back(p);
    playerCount++;

    // update cell players
    (*theBoard[p.getPos()]).notify(*theBoard[p.getPos()], p.getPiece());
    // update display
    td->notify(*theBoard[p.getPos()], p.getPiece());
    if(useX11) gd->notify(td.get()->getMap(), p.getPos());
}

void Board::loadGame(ifstream &in) {
    int numPlayer;
    in >> numPlayer;

    // throw rest of line
    string th;
    getline(in, th);
    // can load
    for(int i = 0; i < numPlayer; i++) {
        string line;
        getline(in, line);

        string name;
        char piece;
        int TC, money, position, waitTime;

        // set line for reading
        std::istringstream iss(line);
        iss >> name >>piece >> TC >> money >> position;
        bool inLine = false;
        if(iss >> inLine){
            if(inLine) iss>> waitTime;
        }
        Player temp(name, piece, money, position);

        if(inLine) {
            temp.changeCup(TC);
            temp.setTimsTime(waitTime);
            temp.toggleLine(true);
        }
    addPlayer(temp);
}
    for(int i = 0; i < 40; i++) {
        // non ownable prop not considered!
        if(theBoard[i].get()->getType() == "E") continue;
        string buildingLine, name, ownerName;
        int imp;

        getline(in, buildingLine);

        istringstream ibs{buildingLine};
        ibs >> name >> ownerName >> imp;
        // mortgage always defaults to false, set true
        if(imp == -1) theBoard[i].get()->toggleMortgage();
        if(imp > 0) theBoard[i].get()->setImp(imp);
        
            if(ownerName == "BANK") {
                    // do nothing because all buildings default to nullptr
                } else {
                    for(int j = 0; j < playerCount; j++) {
                        if(playerList[j].getName() == ownerName) {
                            theBoard[i].get()->setOwner(make_unique<Player>(playerList[j]));
                            theBoard[playerList[j].getPos()]->notify(*theBoard[i]);
                            td->notify(*theBoard[i]);
                            if(useX11) gd->notify(td.get()->getMap(), i);
                            break;
                        }
                     }
                }
            }
}

int Board::getPlayerCount() { return playerCount;}

Player Board::getPlayer(int idx) {return playerList[idx];}

Player Board::getPlayer(string name) {
    for(auto player : playerList) {
        if(player.getName() == name) return player;
    }
}

Player& Board::curPlayer() {return playerList[turn];}

void Board::move() {
    if(canCurPlayerRoll) {
        int r1 = rollDie(die1);
        int r2 = rollDie(die2);

    if(!curPlayer().inLine()) std::cout << "Rolled a " << r1 << " and a " << r2 << endl;

    if(curPlayer().inLine()){

        // in DC Tims line
        curPlayer().setTimsTime(curPlayer().getTimsTime() + 1);
        std::cout << "You are in the DC Tims Line" << endl;
        std::cout << "Enter 1 if you want to roll double" << endl;
        std::cout << "Enter 2 if you want to pay $50" << endl;
        std::cout << "Enter 3 if you want to use Roll Up the Rim cup" << endl;
        std::cout << "Choice: ";
        int choice;
        std::cin >> choice;
        while (choice != 1 && choice != 2 && choice != 3 ) {
            std::cout << "Please enter 1, 2 or 3: ";
            std::cin >> choice;
        }
        if (choice == 1) { // if try to roll doubles
        std::cout << "Rolled a " << r1 << " and a " << r2 << endl;
            if (r1 == r2) {
                curPlayer().toggleLine(false);
                curPlayer().setTimsTime(0);
                cout << "Doubles! You have left the line!" << endl;
            } else {
                std::cout << "You didn't roll doubles" << endl;
            }
        } else if (choice == 2) { // pay $50
                curPlayer().give(50);
                curPlayer().toggleLine(false);
                curPlayer().setTimsTime(0);
                cout << "You have paid to leave the line!" << endl;
        } else { // use Roll Up the Rim Cup
        if(curPlayer().getRimCup() > 0) {
            curPlayer().changeCup(-1); // take a cup away
            totalTimsCup--;
            curPlayer().toggleLine(false);
            curPlayer().setTimsTime(0);
            cout << "You have left the Tims line by using your cup!" << endl;

        } else {
            std::cout << "You do not have cups to use!" << endl;
        }
    }
        // stuck here at 3 turns
        if(curPlayer().getTimsTime() >= 3) {
        std::cout << "Please choose between option 2 or 3: ";
        std::cin >> choice;
        while (choice != 2 && choice != 3) {
            std::cout << "Please enter 2 or 3: ";
            std::cin >> choice;
        }
        if (choice == 2) { // pay $50
            curPlayer().give(50); // (could bankrupt)
            curPlayer().toggleLine(false);
            curPlayer().setTimsTime(0);
            cout << "You have paid $50 to leave the line!" << endl;
            if(curPlayer().getBalance() > 0) curPlayer().move(r1  + r2);
        } else { // use Roll Up the Rim Cup
           if(curPlayer().getRimCup() > 0) {
            curPlayer().changeCup(-1);
            curPlayer().move(r1 + r2);
            cout << "You have left the Tims line by using your cup" << endl;
           } else {
            curPlayer().give(50); // (could bankrupt)
            curPlayer().toggleLine(false);
            curPlayer().setTimsTime(0);
            cout << "You are forced to pay $50 because this is your last turn and you have no cups!" << endl;
            if(curPlayer().getBalance() > 0) curPlayer().move(r1  + r2);

           }
        }
    }
    } else {
        // notify the board
        theBoard[curPlayer().getPos()]->notify(*theBoard[curPlayer().getPos()], curPlayer().getPiece());
        td->notify(*theBoard[curPlayer().getPos()],curPlayer().getPiece());
        if(useX11) gd->notify(td.get()->getMap(), curPlayer().getPos());


        curPlayer().move(r1 + r2);

        int pos = curPlayer().getPos();
        if (theBoard[pos].get()->hasOwner()) {
            propGymRezFee(pos, r1 + r2);
        }

        // update to new position
        theBoard[curPlayer().getPos()]->notify(*theBoard[curPlayer().getPos()], curPlayer().getPiece());
        td->notify(*theBoard[curPlayer().getPos()], curPlayer().getPiece());
        if(useX11) gd->notify(td.get()->getMap(), curPlayer().getPos());

        toggleCanRoll();
    }
 
    if (curPlayer().getPos() == 2 || curPlayer().getPos() == 17 || curPlayer().getPos() == 33) { // SLC
        if (totalTimsCup != 4) { // if there is less than 4 rim cup given out
            int rimProb = rollDie(100);
            if (rimProb != 1) { // 99% the time
                int prob = rollDie(24);
                if (1 <= prob && prob <= 3) {
                    curPlayer().move(-3);
                } else if (4 <= prob && prob <= 7) {
                    curPlayer().move(-2);
                } else if (8 <= prob && prob <= 11) {
                    curPlayer().move(-1);
                } else if (12 <= prob && prob <= 14) {
                    curPlayer().move(1);
                } else if (15 <= prob && prob <= 18) {
                    curPlayer().move(2);
                } else if (19 <= prob && prob <= 22) {
                    curPlayer().move(3);
                } else if (prob == 23) { // go to DC Tims
                    curPlayer().setPos(10);
                    curPlayer().toggleLine(true);
                } else if (prob == 24) {
                    curPlayer().setPos(0);
                    curPlayer().give(200); // (could bankrupt)
                }
            } else { // 1% the time
                curPlayer().changeCup(1);
                totalTimsCup += 1;
            }
        } else {
            int prob = rollDie(24);
            if (1 <= prob && prob <= 3) {
                curPlayer().move(-3);
            } else if (4 <= prob && prob <= 7) {
                curPlayer().move(-2);
            } else if (8 <= prob && prob <= 11) {
                curPlayer().move(-1);
            } else if (12 <= prob && prob <= 14) {
                curPlayer().move(1);
            } else if (15 <= prob && prob <= 18) {
                curPlayer().move(2);
            } else if (19 <= prob && prob <= 22) {
                curPlayer().move(3);
            } else if (prob == 23) { // go to DC Tims
            curPlayer().setPos(10);
            curPlayer().toggleLine(true);
            } else if (prob == 24) {
                curPlayer().setPos(0);
            }
        }
    } else if (curPlayer().getPos() == 7 || curPlayer().getPos() == 22 || curPlayer().getPos() == 36) { // NH
        if (totalTimsCup < 4) { // if there is less than 4 rim cup given out
            int rimProb = rollDie(100);
            if (rimProb != 1) { // 99% the time
                int prob = rollDie(18);
                if (prob == 1) { // (could bankrupt)
                    curPlayer().give(200);
                } else if (2 <= prob && prob <= 3) {
                    curPlayer().give(100);
                } else if (4 <= prob && prob <= 6) {
                    curPlayer().give(50);
                } else if (7 <= prob && prob <= 12) {
                    curPlayer().receive(25);
                } else if (13 <= prob && prob <= 15) {
                    curPlayer().receive(50);
                } else if (16 <= prob && prob <= 17) {
                    curPlayer().receive(100);
                } else if (prob == 18) {
                    curPlayer().receive(200);
                }
            } else { // 1% the time
                curPlayer().changeCup(1);
                totalTimsCup += 1;
            }
        } else {
            int prob = rollDie(18);
            if (prob == 1) { // (could bankrupt)
                curPlayer().give(200);
            } else if (2 <= prob && prob <= 3) {
                curPlayer().give(100);
            } else if (4 <= prob && prob <= 6) {
                curPlayer().give(50);
            } else if (7 <= prob && prob <= 12) {
                curPlayer().receive(25);
            } else if (13 <= prob && prob <= 15) {
                curPlayer().receive(50);
            } else if (16 <= prob && prob <= 17) {
                curPlayer().receive(100);
            } else if (prob == 18) {
                curPlayer().receive(200);
            }
        }
    } else if (curPlayer().getPos() == 38) { // CO-OP Fee (could bankrupt)
            curPlayer().give(150);
    } else if (curPlayer().getPos() == 20) { // Goose Nesting 
        std::cout << "You are attacked by a flock of nesting geese! " << endl;
    } else if (curPlayer().getPos() == 4) { // Tuition
        std::cout << "You have two methods to pay the tuition " << endl;
        std::cout << "Enter 1 if you want to pay $300 tuition" << endl;
        std::cout << "Enter 2 if you want to pay 10% of your total worth" << endl;
        std::cout << "Method: ";
        int method;
        std::cin >> method;
        while (method != 1 && method != 2) {
        std::cout << "Please enter 1 or 2: ";
            std::cin >> method;
        }
        if (method == 1) { // pay $300, (could bankrupt)
                curPlayer().give(300);
        } else { // pay 10%
        auto playerAssets = getAssets()[curPlayer().getPiece()];
        int totalAssets = 0;

        for (auto const& as : playerAssets) {
            totalAssets+=as.second;
        }   
        // does not consider balance (potential bankrupt)
        curPlayer().give(totalAssets*0.1);
    }
    } else if (curPlayer().getPos() == 30) { // go to DC Tims
        curPlayer().setPos(10);
        curPlayer().toggleLine(true);
    }
    

    } else {
        std::cout << "You cannot roll on this turn!" << endl;
    }
}

void Board::toggleCanRoll() {
    canCurPlayerRoll = !canCurPlayerRoll;
}

void Board::buy() {
    if(theBoard[curPlayer().getPos()]->hasOwner()) {
        std::cout << "The building you are trying to purchase has an owner!" << endl;
    } else {
        if(theBoard[curPlayer().getPos()]->getType() == "E") {
            std::cout << "The cell you are trying to buy cannot have owners." << endl;
        } else {
            const int fee = theBoard[curPlayer().getPos()]->getPurCost();
            if(curPlayer().getBalance() >= fee) {
                // pay fee
                curPlayer().give(fee);
                // assign owner
                std::unique_ptr<Player> newOwner = make_unique<Player>(curPlayer());
                theBoard[curPlayer().getPos()]->setOwner(std::move(newOwner));

                cout << theBoard[curPlayer().getPos()]->getOwner().getName() << " now owns " << theBoard[curPlayer().getPos()]->getName() << endl;
                // cout << curPlayer().getBalance() << endl;
                td->notify(*theBoard[curPlayer().getPos()], curPlayer().getPiece());
                if(useX11) gd->notify(td.get()->getMap(), curPlayer().getPos());

            } else {
                cout << "Your " << curPlayer().getBalance() << " is insufficient!"; 
            }
        }
    }
}

void Board::trade(string name, string give, string recieve) {
    int gTest, rTest;
    bool foundRecipient = false;
    bool valid = true;
    istringstream g{give};
    istringstream r{recieve};

    std::cout << "Proposing a trade. Giving: " << give << " Rec: " << recieve << endl;

    if(g >> gTest && r >> rTest) {
        // means they are trading money! This in valid
        std::cout << "You are not making a valid trade [cannot trade money around]" << endl;
        valid = false;
    }

    if(g >> gTest) {
        if(gTest < 0) {
            valid = false;
            std::cout << "Cannot give a negative integer amount" << endl;
        }
        if(curPlayer().getBalance() < gTest) {
            valid = false;
            std::cout << "Insuficcient balance amount" << endl;
        }
    }

    if(r >> rTest) {
        if(rTest < 0) {
            valid = false;
            std::cout << "Cannot recieve a negative integer amount" << endl;}

         for(int i = 0; i < playerCount; i++) {
            if(playerList[i].getName() == name) {
                foundRecipient = true;
                if(rTest > playerList[i].getBalance()) {
                    valid = false;
                    std::cout << "Other party cannot pay the fee!" << endl;
                }
                break;
            }
          }
       

    }

    // have a confirm/approve input
    string agreement;
    std::cout << name << ", do you agree to the trade? [Y to agree, no otherwise]: ";
    std::cin >> agreement;

    if(agreement != "Y") {
        std::cout << "Trade declined" << endl;
        valid = false;
    }

    // validate that name exists
    for(auto p: playerList) {if(p.getName() == name) foundRecipient = true;}

    // once the reciever is found
    if(foundRecipient && valid) {
    // find / give
    int giveMoney;
    istringstream iss{give};

    if(iss>> giveMoney) {
        // its an int value
        curPlayer().give(giveMoney);
        for(auto &p: playerList) { if(p.getName() == name) p.receive(giveMoney);}
        std::cout << "A sum of " << giveMoney << " was given to " << name <<endl;
        
    } else {
        bool found = false;
        for(auto &p: theBoard) {
            if(p->getName() == give) found = true;
            if(p->getName() == give && p->getOwner().getPiece() == curPlayer().getPiece()) {
                if(p->getType() == "FB") {
                    FeeBuilding* fb = dynamic_cast<FeeBuilding*>(p.get());
                    FeeBuilding& tempFB = *fb;
                    tempFB.removeOwner();
                    for(auto player: playerList) {
                        if(player.getName() == name) p->setOwner(make_unique<Player>(player));
                    }
                    std::cout << name << " gave Fee property " << give<<endl;
                    std::cout << p->getOwner().getName() << " now owns it" << endl;
                    td->notify(*p, curPlayer().getPiece());
                    if(useX11) gd->notify(td.get()->getMap(), curPlayer().getPos());

                    break;
                } else {
                    Property* tp = dynamic_cast<Property*>(p.get());
                    Property& tempP = *tp;
                    if(tempP.getUpgradeCnt() == 0) {
                    tempP.removeOwner();
                    for(auto player: playerList) {
                        if(player.getName() == name) p->setOwner(make_unique<Player>(player));
                    }
                    std::cout << name << " gave Tuition property " << give<<endl;
                    std::cout << p->getOwner().getName() << " now owns it" << endl;
                    td->notify(*p, curPlayer().getPiece());
                    if(useX11) gd->notify(td.get()->getMap(), curPlayer().getPos());
                    break;
                } else {
                    std::cout << "cannot give property with upgrades!" << endl;
                    }
                }
            } else {
                std::cout << "You do now own the asset you are trying to give!" << endl;
            }
        }
        if(!found) std::cout << "The asset (likely property) named is not found" << endl;
    }

    // what is recieved!
    int recMoney;
    istringstream recStr{recieve};

    if(recStr>> recMoney) {
        // its an int value
        curPlayer().receive(recMoney);
        for(auto &p: playerList) {
            if(p.getName() == name) p.give(recMoney);
        }
        std::cout << "A sum of " << giveMoney << " was given by " << name <<endl;
    } else {
        bool found = false;
        char otherPlayerPiece;
        for(auto p: playerList) {
            if(p.getName() == name) {
                otherPlayerPiece = p.getPiece(); break;
                }
        }
        for(auto &p: theBoard) {
            // test for comparison cout << p->getName() << "-vs- rec:" << recieve << endl;
            if(p->getName() == recieve) found = true;
            // the piece is owned by the other player
            if(p->getName() == recieve && p->hasOwner() && p->getOwner().getPiece() == otherPlayerPiece) {
                if(FeeBuilding* t = dynamic_cast<FeeBuilding*>(p.get())) {
                    FeeBuilding& tempFB  = *t;
                    tempFB.removeOwner();
                    p->setOwner(make_unique<Player>(curPlayer()));
                    std::cout << name << " gave Fee property" << recieve <<endl;
                    std::cout << p->getOwner().getName() << " now owns it" << endl;
                        td->notify(*p, curPlayer().getPiece());
                        if(useX11) gd->notify(td.get()->getMap(), curPlayer().getPos());
                    break;
                } else {
                    Property* tp = dynamic_cast<Property*>(p.get());
                    Property& tempP = *tp;
                    if(tempP.getUpgradeCnt() == 0) {
                    tempP.removeOwner();
                    p->setOwner(make_unique<Player>(curPlayer()));
                    std::cout << name << " gave Tuition property" << recieve<<endl;
                    std::cout << p->getOwner().getName() << " now owns it" << endl;
                    td->notify(*p, curPlayer().getPiece());
                    if(useX11) gd->notify(td.get()->getMap(), curPlayer().getPos());
                    break;
                    } else {
                        std::cout << "cannot give property with upgrades!" << endl;
                    }
                }
            } else if(found && p->hasOwner() && p->getOwner().getPiece() != otherPlayerPiece ) {
                    std::cout << "The other player[name] does not own " << recieve <<", cannot give!" << endl;
                    break;
            }
        }
        if(!found) std::cout << "The asset (likely property) named is not found" << endl;   
        }

    } else {
        std::cout << name << " is not a valid identifier for a player!" << endl;   
    }
}
    
void Board::buyImp(string name) {
    bool found = false;
    int cellPos = 0;
    bool ownsGroup = true;

    // defaults to an event which cannot be owned!
    Block blockGroup = Block::Event;

    for(auto &c: theBoard) {
        if(c->getName() == name) {
            blockGroup = c->getBlock();
        }
    }

    for(auto &c: theBoard) {
        if(c->getBlock() == blockGroup &&
          (!c->hasOwner() || c->getOwner().getPiece() != curPlayer().getPiece())) {
            ownsGroup = false;
        }
    }

    if(ownsGroup){
    for(auto& c: theBoard) {
        if(c->getName() == name) {
            found = true;

            // try to buy improvement
            if(c->getType() == "P") {
                Property* prop = dynamic_cast<Property*>(c.get());
            if (prop) {
                std::cout << "Trying to upgrade: " << name << std::endl;
                // Now we can safely use derivedPtr to call methods of the Derived class
                if(prop->hasOwner() && prop->getOwner().getPiece() != curPlayer().getPiece()) {
                    std::cout << "You do not own the building!" << endl;
                }
                else if(prop->getImpCost() > curPlayer().getBalance()) {
                    std::cout << "Insufficient funds" <<endl;
                } else if(prop->getUpgradeCnt() == 5) {
                    std::cout << "The building already has maximum upgrades!" << endl;
                } else {
                    // transaction passes
                    int cost = prop->getImpCost();
                    curPlayer().give(cost);
                    prop->improve(true);
                    std::cout << "The building has been upgraded!" << endl;
                    td->notify(*theBoard[cellPos], curPlayer().getPiece());
                    if(useX11) gd->notify(td.get()->getMap(), cellPos);
                }
            } else { std::cout << "Unexpected error occured" << std::endl;}
            }
            else { std::cout << "The property " << name << " cannot be upgraded!" <<endl;}
        break;
        }
        cellPos++;
    }
    } else {
        std::cout << "You do not own all groups within the Monopoly block!" << endl;
    }
    if(!found) std::cout << "The property " << name << " was not found!" <<endl;
}

void Board::sellImp(string name) {
    bool found = false;
    int cellPos = 0;
    for(auto& c: theBoard) {
        if(c->getName() == name) {
            found = true;
            // try to buy improvement
            if(c->getType() == "P") {
                Property* prop = dynamic_cast<Property*>(c.get());
                if (prop) {
                    std::cout << "Trying to downgrade: " << name << std::endl;
                if(prop->hasOwner() && prop->getOwner().getPiece() != curPlayer().getPiece()) {
                    std::cout << "You do not own the building!" << endl;
                }
                else if(prop->getUpgradeCnt() == 0) {
                        std::cout << "The building has no upgrades!" << endl;
                    } else {
                        // transaction passes
                        int cost = prop->getImpCost();
                        // RECALL ITS HALF THE COST
                        curPlayer().receive(cost/2);
                        prop->improve(false);
                        std::cout << "The building has been downgraded!" << endl;
                        td->notify(*theBoard[cellPos], curPlayer().getPiece());
                        if(useX11) gd->notify(td.get()->getMap(), cellPos);
                    }
                } else { std::cout << "Unexpected error occured" << std::endl; }
            } else { std::cout << "The property " << name << " cannot be downgraded!" <<endl; }
        break;
        }
        cellPos++;
    }
    if(!found) std::cout << "The property " << name << " was not found!" <<endl;
}

void Board::bankrupt() {
    const int loc = curPlayer().getPos();
    if(curPlayer().getBalance() < 0) {
    std::cout << "Player: " << curPlayer().getName() << " ["<< curPlayer().getPiece() <<"] is now bankrupt" << endl;

    // auction off here
    if(theBoard[loc].get()->hasOwner()) {
        int ownerPos;
        for(int i = 0; i < playerCount; i++) {
            if(playerList[i].getPiece() == theBoard[loc].get()->getOwner().getPiece()) { 
                ownerPos = i; break;
                std::cout <<playerList[i].getPiece() << " Owns the property" << endl;
                }
        }
        // give to owner.
        auto playerAssetNames = getAssets()[curPlayer().getPiece()];
        for(auto &as: playerAssetNames) {
            std::cout << "Transfering ownership of: "<< as.first<< endl;
            if(as.first != "Money") {
                for (int i = 0; i < 40; ++i) {
                    if (theBoard[i].get()->getName() == as.first) {
                        theBoard[i].get()->setOwner(make_unique<Player>(playerList[ownerPos]));
                        // pay off mortgage for 50%
                        if(theBoard[i].get()->isMort()) {
                            string pay;
                            cout << "You have seized a mortgaged property! enter YES to pay off principle (50%) [NO otherwise]:";
                            cin >> pay;

                            while(pay != "NO" && pay!="YES") {
                                cout << "enter [NO or YES]";
                                cin >> pay;
                            }
                            if(pay == "YES") {
                                playerList[ownerPos].give(theBoard[i].get()->getPurCost() *0.5);
                                cout << "You have paid the principle!" << endl;
                                theBoard[i].get()->toggleMortgage();
                            }
                        }
                    }
                }
            } else {
                playerList[ownerPos].receive(as.second);
            }
        }
    } else {
        // auction off all assets
        auto playerAssetNames = getAssets()[curPlayer().getPiece()];

        for(auto &as: playerAssetNames) {
            if(as.first != "Money") {
                // auction off!
                auction(as.first);
            }
        }
    }

    // delete the player
    std::cout << "Player: " << curPlayer().getPiece()  <<" has been removed" <<endl;
    playerList.erase(playerList.begin() + turn); // erase the player!
    --playerCount;
    if(turn > playerCount) turn = 0;
    std::cout << "It is now " << curPlayer().getPiece() <<"'s turn!" << endl;
    canCurPlayerRoll = true;
 } else {
    std::cout << "You still have balance: $"<< curPlayer().getBalance() << endl;
}
// implicitly removes player and goes to the next player
}

void Board::printAll() {
    auto state = getAssets();
    for (auto const& playerSym : state) {
        std::cout << playerSym.first << ":" << endl; 
        int acc = 0;
        for (auto const& as : playerSym.second) {
            acc+=as.second;
            std::cout << as.first << " valued at: " << as.second << endl; 
        }
        std::cout << endl;
        std::cout << " Net Worth [" << playerSym.first <<"]: " << acc << endl;
        std::cout << "---------------------------------"<< endl;
    }
}

void Board::playerAsset() {
    if(curPlayer().getPos() != 4) {
    auto state = getAssets();
    int acc = 0;
    std::cout << "Assets of: " << curPlayer().getName() << " - [" << curPlayer().getPiece() << "]:" << endl;

    for (auto const& as : state[curPlayer().getPiece()]) {
        acc+=as.second;
        std::cout << as.first << " valued at: " << as.second << endl;
        }
        std::cout << endl;
        std::cout << " Net Worth: " << acc << endl;
    } else {
        std::cout << "You cannot see assets when paying tuiton"<< endl;
    }
}

void Board::mort(string property) {
    bool isFound = false;
    bool noOwner = true;
    for(int i = 0; i < 40; i++) {
        auto p = theBoard[i].get();
            // check if it is property
            if(p->getName() == property &&  (p->getType() == "P" || p->getType() == "FB")){
            isFound = true;
            if(p->hasOwner()) {
                noOwner = false;
            if(p->getOwner().getPiece() == curPlayer().getPiece()){
                // player owns the property but has upgrades
                if(p->getUpgradeCnt() !=0) {
                    std::cout << "cannot mortgage because of improvements" << endl;
                } else {
                    if(!p->isMort()) {
                        // get money and toggle mortgage
                        curPlayer().receive(p->getPurCost() /2);
                        p->toggleMortgage();
                        
                        isFound = true;
                        std::cout << "Mortgaged the property!" << endl;
                        break;
                    } else { std::cout << "Already mortgaged!" << endl;}
                }
            } else {
                std::cout << "You do not Own this property" << endl;
                break;
                }
            } else {
                std::cout << "This property has no owners" << endl;
                break;
                }
            } 
        }
        if(!isFound) cout << "The property named: " << property << " is not found" << endl;
        if(noOwner) cout << "This property has no owners" << endl;
    }

void Board::unmort(string property) {
    bool isFound = false;
    bool noOwner = true;    
    for(int i = 0; i < 40; i++) {
        auto p = theBoard[i].get();
            // check if it is property
            if(p->getName() == property &&  (p->getType() == "P" || p->getType() == "FB")){
            isFound = true;
            if(p->hasOwner()) {
                noOwner = false;
            if(p->getOwner().getPiece() == curPlayer().getPiece()){
                isFound = true;
                    if(p->isMort()) {
                        // give money and toggle mortgage
                        if(curPlayer().getBalance() < p->getPurCost() * 0.6) {
                            cout << "Balance of " << curPlayer().getBalance() << " is insufficient" << endl;
                        } else {
                            curPlayer().give(p->getPurCost() * 0.6);
                            p->toggleMortgage();
                            cout << "Property now unmortgaged!" << endl;
                            break;
                        }
                    } else {
                        cout << "Not mortgaged!" << endl;
                        break;
                    }
            } else {
                cout << "You do not Own this property" << endl;
                break;
                }
                }
            } 
        }
        if(!isFound) cout << "The property named: " << property << " is not found" << endl;
        if(noOwner) cout << "This property has no owners" << endl;
    }

map<char, map<string, int>> Board::getAssets() {
    map<char, map<string, int>> res;

    for(size_t i = 0; i <  playerList.size(); i++) {
        map<string, int> temp;
        temp.insert(make_pair("Money", playerList[i].getBalance()));
        res.insert(std::make_pair(playerList[i].getPiece(), temp));
    }

    for(auto &asset: theBoard) {
        // can own
        auto as = asset.get();
        if(as->getType() !="E") {
            if(as->hasOwner()) {
                if(as->getType() == "P"){
                Property* tempP = dynamic_cast<Property*>(as);
                int value = tempP->getPurCost() + (tempP->getUpgradeCnt() * tempP->getImpCost());
                res[as->getOwner().getPiece()].insert(make_pair(as->getName(), value));
                } else {
                FeeBuilding* tempF = dynamic_cast<FeeBuilding*>(as);
                int value = tempF->getPurCost();
                res[as->getOwner().getPiece()].insert(make_pair(as->getName(), value));
                }
            }
        }
    }
    return res;
}

void Board::save(string filename) {
    // go through players
    // Open a file named "example.txt" for writing
    std::ofstream output(filename);

    // Check if the file opened successfully
    if (!output) {
        cout << "Error: cannot open file!" << std::endl;
    } else {
        output << playerList.size() << endl;
    for(size_t i = 0; i < playerList.size(); i++) {
        output << playerList[i].getName() << " " <<
            playerList[i].getPiece()  << " " <<
            playerList[i].getRimCup()<< " " << 
            playerList[i].getBalance()   << " " << 
            playerList[i].getPos()   << " ";
            // if player is in tims line!
            if(playerList[i].inLine()) {
                 output << 1 << " " << playerList[i].getTimsTime();
            } else {
                output << 0;
            }
            
            output <<  endl;
        }
    for(int i = 0; i < 40; i++) {
        if(theBoard[i].get()->getType() != "E") {
        output << theBoard[i].get()->getName()<< " ";
        if(theBoard[i].get()->hasOwner()) {
            output << theBoard[i].get()->getOwner().getPiece()  << " ";
        } else {
            output << "BANK"  << " ";
        }
    if (theBoard[i].get()->getType() == "FB") {
            if(theBoard[i].get()->isMort()) {
                output << -1 << " ";
            } else {
                output << 0 << " ";
            }
        } else {
            if(theBoard[i].get()->isMort()) {
                output << -1 << " ";
            } else {
                output << theBoard[i].get()->getUpgradeCnt() << " ";
            }
        }
        // endline
        output <<  endl;
        }


    }
    // Close the file
    output.close();

    std::cout << "Data has been written" << std::endl;
    }
}

void Board::auction(string property) {
    int price = 0; // start auction at 0
    for (int i = 0; i < 40; ++i) {
        if (theBoard[i].get()->getName() == property) { 
            // find position of the property on the board
            if(theBoard[i].get()->isMort()) theBoard[i].get()->toggleMortgage(); 
            // ensure that a property is no longer mortgaged
        }
    }
    cout << "Current bid for " << property << " is $" << price << endl;
    vector<char> participation;
    for (size_t i = 0; i < playerList.size(); ++i) { 
        // initial the participation list, assume all players participate in auction
        participation.emplace_back(playerList[i].getPiece());
    }
    while (participation.size() > 1) {
        int numOfPart = participation.size();
        for (int i = 0; i < numOfPart;) {
            if(participation.size() == 1 || i == numOfPart) break;
            cout << "Participants: ";
            for(int i = 0; i < numOfPart; i++) {
                cout <<participation[i] << " ";
            }
            cout <<endl;
            cout << "Current bid for " << property << " is $" << price << endl;
            cout << participation[i] << ", do you want to raise the current bid or withdraw from auction?" << endl;
            cout << "Enter 1 to raise the current bid. Enter 2 to withdraw from auction" << endl;
            cout << "Choice: ";
            int choice;
            cin >> choice;
            while (choice != 1 && choice != 2) {
                cout << "Must enter 1 or 2: ";
                cin >> choice;
            }
            if (choice == 1) { // raise price
                int raise;
                cout << "Enter amount to raise bid by: " << endl;
                cin >> raise;
                while(raise < 1) {
                    cout << "Must raise property prices by positive integer!" << endl;
                    cin >>raise;
                }
                cout << "Raise by: " << raise << endl;
                price += raise;
                ++i;
            } else { // withdraw, remove the player
                std::cout << participation[i]  << " has withdrawn!" <<endl;
                participation.erase(participation.begin() + i);
                numOfPart = participation.size(); // update size
            }
        }
    }

    cout << "The final price for " << property << " after auction is $" << price << endl;
    for (size_t i = 0; i < playerList.size(); ++i) {
        if (playerList[i].getPiece() == participation[0]) {
                // pay fee
                cout << playerList[i].getName() << " has taken ownership!" << endl;
                playerList[i].give(price);
                if(playerList[i].getBalance() < 0) 

                theBoard[i]->setOwner(make_unique<Player>(playerList[i]));
        }
    }
}

void Board::propGymRezFee(int grid, int dieSum) {
    // property is not mortgaged
    if(!theBoard[grid].get()->isMort()) {
    if (theBoard[grid].get()->getType() == "P") { // property
        int fee = theBoard[grid].get()->getFee();
        curPlayer().give(fee);
        theBoard[grid].get()->getOwner().receive(fee);
    } else if (theBoard[grid].get()->getType() == "FB") {
        if (grid == 5 || grid == 15 || grid == 25 || grid == 35) { // residence
            char owner = theBoard[grid].get()->getOwner().getPiece();
            int fee = 25;
            int start = 5;
            for (int i = 0; i < 4; ++i) {
                if (theBoard[start + i * 5].get()->getOwner().getPiece() == owner) {
                    fee *= 2;
                }
            }
            fee = fee / 2;
            curPlayer().give(fee);
            theBoard[grid].get()->getOwner().receive(fee);
        } else if (grid == 12 || grid == 28) { // gym
            char owner = theBoard[grid].get()->getOwner().getPiece();
            int fee = 0;
            if (theBoard[12].get()->getOwner().getPiece() == owner && theBoard[28].get()->getOwner().getPiece() == owner) {
                fee = 12 * dieSum;
            } else {
                fee = 4 * dieSum;
            }
            curPlayer().give(fee);
            theBoard[grid].get()->getOwner().receive(fee);
        }
    }
    } else {
        cout << "You landed on a mortgaged property, no tuition!" << endl;
    }
}

std::ostream &operator<<(std::ostream &out, const Board &b) {
    if(b.td){
    out << *b.td << std::endl;
    } else {
        cout << "invalid display";
    }
    return out;
}
