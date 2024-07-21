#include<iostream>
#include<vector>
#include<string>
#include <algorithm>
#include <iterator> // for ostream_iterator
#include <fstream>
#include <sstream>

#include "board.h"

using namespace std;

int main(int argc, char* argv[]) {
    try {
        // Raises an exception if cin.fail() or cin.eof() are true.
        cin.exceptions(ios::eofbit|ios::failbit);

        // NEW (seed once!)
        srand(time(NULL));

        string file = "";
	    bool test = false;
        bool load = false;
        bool useX11 = true;
        int die1 = 6;
        int die2 = 6;

        string command;  
    
	    for (int i=0; i < argc; i++){
		string arg = argv[i];
		if (arg=="-testing") {
			test=true;
           
            cout << "You are in testing mode!" << endl;
		}
		else if (arg=="-load") {
            load = true;
			if ((i+1)<argc){
				file = argv[i+1];
			}
            cout << "loading from: " << file << endl;
		} else if(arg=="--no-display") {
            useX11 = false;
        }
	}
        Board b{useX11};
        b.setDie(die1, die2);
        int numPlayer;

        if(load) {
            ifstream in{file};

            if(!in) {
                cout << "loading failed, game needs to be restarted" << endl;
                load = false;
            } else { b.loadGame(in); } 

            in.close();
        }
        
        if(!load) {
        cout << b;
        // start from scratch, enter players
        cout << "Enter the number of players: ";
        cin >> numPlayer;
        while(cin.fail()) {
            cout << "Number not accepted, has to be between 2-8 " << endl;
            cin >> numPlayer;
        }

        while(numPlayer < 2 || numPlayer > 8) {
            cout << "Re-Enter the number of players[2-8]:";
            cin >> numPlayer;
        }

        std::vector<char> pieceList {'G', 'B', 'D', 'P', 'S', '$', 'L', 'T'};

        for(int i = 0; i < numPlayer; i++) {
            cout << "These Pieces are Available:" << endl;
            std::copy(pieceList.begin(), pieceList.end(), ostream_iterator<char>(std::cout, " "));
            cout << endl;
            string name;
            char piece;

            cout << "Enter player " << i + 1 << "'s name: " ;
            cin >> name;

            cout << "Enter player " << i + 1 << "'s game piece: " ;
            cin >> piece;

            while(std::find(pieceList.begin(), pieceList.end(), piece) == pieceList.end()) {
            cout << "Piece already taken! [or invalid]" << endl;
            cout << "Re-Enter player " << i + 1 << "'s game piece: " ;
            cin >> piece;
            }
            

            auto el = std::find(pieceList.begin(), pieceList.end(), piece);
            pieceList.erase(el);

            Player temp{name, piece, 1500, 0};
            cout << b;
            b.addPlayer(temp);
        }
    }

        while(true) {
            if(b.getPlayerCount() <=1) {
                cout << "THERE IS A WINNER! =>";
                if(b.getPlayerCount() == 1) {
                    cout << b.getPlayer(0) << endl; 
                    b.printAll();
                    break;
                } 
                cout << "You have less than 1 player???" << endl;
                break;
            }
            cout << b;
            cout << "Enter the command: ";
            cin >> command;
            if(command == "roll") {
                if(b.curPlayer().getBalance() >= 0) {
                    int d1 = 6;
                    int d2 = 6;
                    if(test) {
                    string testdies;
                    getline( std::cin, testdies);
                    if ( !testdies.empty() ) {
                    std::istringstream stream( testdies );
                    if(stream >> d1 >> d2) {
                        while(d1 < 0) {
                            cout  << "The first die you inputted for testing is invalid!" << endl;
                            cout << "re-enter die 1: ";
                            cin >> d1;
                        }

                        while(d2 < 0) {
                            cout  << "The second die you inputted for testing is invalid!" << endl;
                            cout << "re-enter die 2: ";
                            cin >> d1;
                        }
                        }
                        b.setDie(d1, d2);
                    }
                    }
                    b.move();   
                } else {
                    cout <<"edge case where you did not roll but is bankrupt" <<endl;
                }
            } else if(command == "next") {
                if(b.curPlayer().getBalance() >= 0) {
                    b.nextTurn();
                    cout << "Player " << b.getTurn() << "'s turn!" << endl;
                } else {
                    cout << "you are currently in debt!" << endl;
                }
            } else if(command == "buy") {
                b.buy();
            } else if(command == "trade") {
                string name, give, receive;
                cin >> name >> give >> receive;

                b.trade(name, give, receive);

            } else if(command == "improve") {
                string property, operation;
                cin >> property >> operation;
                if(operation == "buy") {
                    cout << "Buying improvement:"<< endl;
                    b.buyImp(property);
                    } if(operation == "sell")  {
                    cout << "Selling improvement:"<< endl;
                    b.sellImp(property);
                    }
                else {
                   cout<< "incorrect operation. [buy / sell]" << endl;
                }
            } else if(command == "mortgage") {
                string property;
                cin >> property;
                cout << "Mortgaging:" << endl;
                b.mort(property);
            } else if(command == "unmortgage") {
                string property;
                cin >> property;
                cout << "Unmortgaging:" << endl;
                b.unmort(property);
            } else if(command == "bankrupt") {
                b.bankrupt();

            } else if(command == "assets") {
                b.playerAsset();

            } else if(command == "all") {
                b.printAll();

            } else if(command == "save") {
                string fn;
                cin >> fn;
                b.save(fn);

            } else {
                cerr << "Your command: "  << command << " does not match any!" <<endl;
            }
        }
    } catch (const ios_base::failure &fail) {
    // catch exception
    }
}
