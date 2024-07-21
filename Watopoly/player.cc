#include "player.h"

#include<iostream>
#include<sstream>

Player::Player(string name, char gamePiece, int balance, int position):
    name{name}, gamePiece{gamePiece}, balance{balance}, position{position} {}

Player::~Player() {}

int Player::getBalance() {
    return balance;
}

bool Player::inLine(){
    return sentToDCTims;
}

void Player::move(int shift) {
   position+=shift;
    if(position > 39) {
        position-=39;
        // collects osap
        balance+=200;
    } else if (position < 0) {
        position += 39;
        balance += 200; // collect OSAP
    }
}

void Player::setPos( int pos) {
    position = pos;
}

void Player::changeCup(int num) {
    rimCup+=num;
}

string Player::getName() {
    return name;
}

char Player::getPiece() {
    return gamePiece;
}

int Player::getPos() {
    return position;
}

void Player::give(int g) {
    balance-=g;
}

void Player::receive(int r) {    
    balance+=r;
}

void Player::toggleLine(bool val) {
    sentToDCTims = val;
}

void Player::setTimsTime(int val) {
    DCTimsTime = val;
}

int Player::getTimsTime() {
    return DCTimsTime;
}

int Player::getRimCup() {return rimCup;}

std::ostream &operator<<(std::ostream &out, const Player &p) {
    out << "Player " << p.name << endl;
    out << "\tOwned balance: " << p.balance << endl;
    return out;
}
