#include "textDisplay.h"
#include "cell.h"


using namespace std;

TextDisplay::TextDisplay(const std::unique_ptr<Cell> tb[40]) {
    for(int i = 0; i < 40; i++) {
    auto info = tb[i].get(); 
    string piece = "_";
    if(info->hasOwner()) {
        piece = "" + info->getOwner().getPiece();
    }
    std::map<string, string> infoMap = {
    {"name", info->getName() },
    {"hasOwner", to_string(info->hasOwner()) },
    {"playerIcons", info->getPlayers() },
    {"owner", ""  + piece },
    {"upgrades", to_string(info->getUpgradeCnt()) },
};
    td.emplace_back(infoMap);
    }
}

std::vector<std::map<string, string>> TextDisplay::getMap() {
    return td;
}

string TextDisplay::getOwnership(int idx) const {
    string ownershipLine = "";
    
    auto ownerNameIt = td[idx].find("owner");
        if (ownerNameIt != td[idx].end()) {
            ownershipLine+= ownerNameIt->second;
            ownershipLine+="]";
        }

    // depending on the number of upgrades
    int upgrades = 0;

    auto upgradeIt = td[idx].find("upgrades");
    if (upgradeIt != td[idx].end()) {
            upgrades = stoi(upgradeIt->second);
        }
    if(upgrades == 0) {
        ownershipLine+="      ";
        } else if(upgrades == 1) {
            ownershipLine+="W     ";
        } else if(upgrades== 2) {
            ownershipLine+="WW    ";
        } else if(upgrades == 3) {
            ownershipLine+="WWW   ";
        } else if(upgrades == 4) {
            ownershipLine+="WWWW  ";
        } else if(upgrades == 5) {
            ownershipLine+="WWWWC ";
        }
    return ownershipLine;
}

string TextDisplay::getIcons(int idx) const {
    auto it = td[idx].find("playerIcons");
    if (it != td[idx].end()) {
        return it->second;
    }
    return "      ";
}

string TextDisplay::getCellName(int idx) const {
        auto it = td[idx].find("name");
    if (it != td[idx].end()) {
        return it->second;
    }
    return "       ";
}

bool TextDisplay::getHasLine(int idx) const {
    auto it = td[idx].find("name");
    if (it != td[idx].end()) {
        string name = it->second;
            if(
        name !=  "CIF" &&
        name !=  "PAC" &&
        name !=  "Needles Hall" &&
        name !=  "SLC" &&
        name !=  "DC Tims Line" &&
        name !=  "Goose Nesting" &&
        name !=  "Go to Tims" &&
        name !=  "REV" &&
        name !=  "V1" &&
        name !=  "MKV" && 
        name !=  "UWP" && 
        name !=  "Collect OSAP" &&
        name !=  "Tuition" &&
        name !=  "CO-OP Fee"
    ) {
        return true;
    } 
    return false;
    }
    return false;
}

void TextDisplay::notify(Cell &c, char icon) {
    for(int i = 0; i < 40; i++) {
        auto it = td[i].find("name");
        if (it != td[i].end()) {
        if(it->second == c.getName()) {
            // cout << "notifying with owner " << c.getName() << endl;

            string piece = "_";
            if(c.hasOwner()) {
                piece = c.getOwner().getPiece();
                } else {
                    piece = "_";
                }
            td[i]["name"] =  c.getName();
            td[i]["hasOwner"] =  to_string(c.hasOwner());
            td[i]["playerIcons"] =  c.getPlayers();
            td[i]["owner"] =  piece;
            td[i]["upgrades"] =  to_string(c.getUpgradeCnt());

            // cout << "GOT THE CELL! " << td[i]["owner"] << " Owns" <<  td[i]["name"];
            }
        }
    }
};

SubscriptionType TextDisplay::subType() {
    return SubscriptionType::All;
}

void TextDisplay::printSpace(std::ostream& out, int line) const {
    const int spaceSplit = 16;
    const string logo[8] = {
        " _____________________________________________  ",
        "|                                             | ",
        "| #   #   #  #####  ###  ###   ###  #   #   # | ",
        "| #   #  # #   #   #   # #  # #   # #   #   # | ",
        "| # # #  ###   #   #   # ###  #   # #    # #  | ",
        "| # # #  # #   #   #   # #    #   # #     #   | ",
        "| #####  # #   #    ###  #     ###  ####  #   | ",
        "|_____________________________________________| "
    };
    if(line == 20) {
        for(int j = 0; j < spaceSplit; j++) {
            out << " ";
        }
        out << logo[0];
        for(int j = 0; j < spaceSplit; j++) {
            out << " ";
        }
        } else if(line == 21) {
                    for(int j = 0; j < spaceSplit; j++) {
            out << " ";
        }
        out << logo[1];
        for(int j = 0; j < spaceSplit; j++) {
            out << " ";
        }
        } else if(line == 22) {
            for(int j = 0; j < spaceSplit; j++) {
            out << " ";
        }
        out << logo[2];
        for(int j = 0; j < spaceSplit; j++) {
            out << " ";
        }
        }else if(line == 23) {
            for(int j = 0; j < spaceSplit; j++) {
            out << " ";
        }
        out << logo[3];
        for(int j = 0; j < spaceSplit; j++) {
            out << " ";
        }
        } else if(line == 24) {
            for(int j = 0; j < spaceSplit; j++) {
                out << " ";
            }
            out << logo[4];
            for(int j = 0; j < spaceSplit; j++) {
                out << " ";
            }
        } else if(line == 25) {
            for(int j = 0; j < spaceSplit; j++) {
                out << " ";
            }
            out << logo[5];
            for(int j = 0; j < spaceSplit; j++) {
                out << " ";
            }
        } else if(line == 26) {
            for(int j = 0; j < spaceSplit; j++) {
                out << " ";
            }
            out << logo[6];
        for(int j = 0; j < spaceSplit; j++) {
            out << " ";
        }
        }  else if(line == 27) {
                    for(int j = 0; j < spaceSplit; j++) {
            out << " ";
        }
        out << logo[7];
        for(int j = 0; j < spaceSplit; j++) {
            out << " ";
        }
        }  else {
        for(int j = 0; j < 80; j++) {
            out << " ";
            }
        }
}

TextDisplay::~TextDisplay(){}

std::ostream &operator<<(std::ostream &out, const TextDisplay &dis) {
    // top line
    for(int i = 0; i < 100; i++) {
        out << "_";
    }
    out << endl;

    // print top row
    for(int i = 20; i < 31; i++) {
        const string name = dis.getCellName(i);

        if(dis.getHasLine(i)) {
            out << "|        ";
        } else {
            if(name.size() > 7) {
                const string cur = name.substr(0, name.rfind(' '));
                out << "|" << cur;
                if(cur.size() <= 8) {
                    for(size_t i = 0; i < 8 - cur.size(); i++) {
                        out << " ";
                    }
                }
            } else {
                out << "|" << name;
                if(name.size() <= 8){
                    for(size_t i = 0; i < 8 - name.size(); i++) {
                        out << " ";
                    }
                }
            } 
        }
        if(i == 30) out << "|";
    }
    out <<endl;

    // second row
    for(int i = 20; i < 31; i++){
        const string name = dis.getCellName(i);
        if(dis.getHasLine(i)) {
            out << "|--------";
        } else {
            if(name.size() > 7) {
                const string cur = name.substr(name.rfind(' ') + 1);
                out << "|" << cur;
                if(cur.size() <= 8) {
                    for(size_t i = 0; i < 8 - cur.size(); i++) {
                        out << " ";
                    }
                }
            } else {
                out << "|        ";
            } 
        }
        if(i == 30) out << "|";
    }
    out << endl;

    // third row
    for(int i = 20; i < 31; i++) {
    // third row
        const string name = dis.getCellName(i);
        if(dis.getHasLine(i)) {
            out << "|" << name;
            if(name.size() <= 8) {
                for(size_t i = 0; i < 8 - name.size(); i++) {
                    out << " ";
                }
            }
        }  else {
        out << "|        ";
        }
        if(i == 30) out << "|";
    }
    out << endl;

    // fourth row
    for(int i = 20; i < 31; i++) {
        out << "|" << dis.getIcons(i);
        for(size_t j = 0; j < 8 - dis.getIcons(i).length(); j++) {
            out << " ";
        }
        if(i == 30) out << "|";
    }
    out << endl;
    for(int i = 20; i < 31; i++) {
        out << "|" << dis.getOwnership(i);
        if(i == 30) out << "|";
    }
    out << endl;

    for(int i = 20; i < 31; i++) {
        out << "|________";
        if(i == 30) out << "|";
    }
    out << endl;

    int logoLine = 0;
    // the two vertical parts
    for(int i = 0; i < 9; i++) {
        const int lIdx = 19 - i;
        const int rIdx = 31 + i;
        const string nameL = dis.getCellName(lIdx);
        const string nameR = dis.getCellName(rIdx);
 
        //first line
        if(dis.getHasLine(lIdx)) {
            out << "|        |";
        } else {
            if(nameL.size() > 7) {
                const string cur = nameL.substr(0, nameL.rfind(' '));
                out << "|" << cur;
                if(cur.size() <= 8){
                    for(size_t i = 0; i < 8 - cur.size(); i++) {
                        out << " ";
                    }
                out <<"|";
                }
            } else {
                out << "|" << nameL;
                if(nameL.size() <= 8){
                    for(size_t i = 0; i < 8 - nameL.size(); i++) {
                        out << " ";
                    }
                }
                out << "|";
            } 
        }
        dis.printSpace(out, logoLine);
        if(dis.getHasLine(rIdx)) {
            out << "|        |";
        } else {
            if(nameR.size() > 7) {
                const string cur = nameR.substr(0, nameR.rfind(' '));
                out << "|" << cur;
                if(cur.size() <= 8){
                    for(size_t i = 0; i < 8 - cur.size(); i++) {
                        out << " ";
                    }
                out <<"|";
                }
            } else {
                out << "|" << nameR;
                if(nameR.size() <= 8){
                    for(size_t i = 0; i < 8 - nameR.size(); i++) {
                        out << " ";
                    }
                }
                out << "|";
            } 
        }
        ++logoLine;
        out << endl;
        // second line
        if(dis.getHasLine(lIdx)) {
            out << "|--------";
        } else {
            if(nameL.size() > 7) {
                const string cur = nameL.substr(nameL.rfind(' ') + 1);
                out << "|" << cur;
                if(cur.size() <= 8){
                    for(size_t i = 0; i < 8 - cur.size(); i++) {
                        out << " ";
                    }
                }
                out << "|";
            } else {
                out << "|        ";
            } 
        }
        out << "|";
        dis.printSpace(out, logoLine);
        if(dis.getHasLine(rIdx)) {
            out << "|--------|";
        } else {
            if(nameR.size() > 7) {
                const string cur = nameR.substr(nameR.rfind(' ') + 1);
                out << "|" << cur;
                if(cur.size() <= 8){
                    for(size_t i = 0; i < 8 - cur.size(); i++) {
                        out << " ";
                    }
                }
                out << "|";
            } else {
                out << "|        |";
            } 
        }
        ++logoLine;
        out << endl;

        // third line
    if(dis.getHasLine(lIdx)) {
        out << "|" << nameL;
        if(nameL.size() <= 8) {
            for(size_t i = 0; i < 8 - nameL.size(); i++) {
                out << " ";
            }
        }
        out << "|";
        } else {
            out << "|        |";
        }
    dis.printSpace(out, logoLine);
    if(dis.getHasLine(rIdx)) {
        out << "|" << nameR;
        if(nameR.size() <= 8) {
            for(size_t i = 0; i < 8 - nameR.size(); i++) {
                out << " ";
            }
        }
        out << "|";
    } else {
        out << "|        |";
    }
    ++logoLine;
    out << endl;

    // second last line (where players will go)
    out << "|" <<  dis.getIcons(lIdx);
    for(size_t i = 0; i  < 8 - dis.getIcons(lIdx).length(); i++) {
        out << " ";
    }
    out <<"|";
    dis.printSpace(out, logoLine);
        out << "|" << dis.getIcons(rIdx);
        for(size_t i = 0; i  < 8 - dis.getIcons(rIdx).length(); i++) {
            out << " ";
        }
        out <<"|" << endl;
        ++logoLine;

        // Last Line
        out << "|" << dis.getOwnership(lIdx) << "|";
        dis.printSpace(out, logoLine);
        out << "|" << dis.getOwnership(rIdx) << "|" << endl;
        ++logoLine;
        out << "|________|";
        if(i == 8) {
            for(int j = 0; j < 80; j++) {
                out << "_";
            }
        } else {
           dis.printSpace(out, logoLine);
        }
        out << "|________|" << endl;
    ++logoLine;
    }

    // print bottom row
    for(int i = 10; i >=0; i--) {
        const string name = dis.getCellName(i);
        if(dis.getHasLine(i)) {
            out << "|        ";
        } else {
            if(name.size() > 7) {
                const string cur = name.substr(0, name.rfind(' '));
                out << "|" << cur;
                if(cur.size() <= 8){
                    for(size_t i = 0; i < 8 - cur.size(); i++) {
                        out << " ";
                    }
                }
            } else {
                out << "|" << name;
                if(name.size() <= 8){
                    for(size_t i = 0; i < 8 - name.size(); i++) {
                        out << " ";
                    }
                }
            } 
        }
        if(i == 0) out << "|";
    }
    out <<endl;


    for(int i = 10; i >=0; i--){
        const string name = dis.getCellName(i);
        if(dis.getHasLine(i)) {
            out << "|--------";
        } else {
            if(name.size() > 7) {
                const string cur = name.substr(name.rfind(' ') + 1);
                out << "|" << cur;
                if(cur.size() <= 8){
                    for(size_t i = 0; i < 8 - cur.size(); i++) {
                        out << " ";
                    }
                }
            } else {
            out << "|        ";
            } 
        }
        if(i == 0) out << "|";
    }
    out << endl;

    for(int i = 10; i >=0; i--) {
        const string name = dis.getCellName(i);
        if(dis.getHasLine(i)) {
            out << "|" << name;
            if(name.size() <= 8) {
                for(size_t i = 0; i < 8 - name.size(); i++) {
                    out << " ";
                }
            }
        } else {
        out << "|        ";
        }
        if(i == 0) out << "|";
    }
    out << endl;
    for(int i = 10; i >=0; i--) {
                out << "|" <<  dis.getIcons(i);
        for(size_t j = 0; j  < 8 - dis.getIcons(i).length(); j++) {
            out << " ";
        }
        if(i == 0) out << "|";
    }
    out << endl;
    for(int i = 10; i >=0; i--) {
        out << "|" << dis.getOwnership(i);
        if(i == 0) out << "|";
    }
    out << endl;

    for(int i = 10; i>=0; i--) {
        out << "|________";
        if(i == 0) out << "|";
    }
    out << endl;

    return out;
}
