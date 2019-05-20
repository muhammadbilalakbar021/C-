#include "super_enemy.hpp"
#include <iostream>
using namespace std;

Enemy::Enemy(int xpos_, int ypos_, int health_, int strength_, int defense_) : xpos_(xpos_), ypos_(ypos_),
                                                                               health_(health_), strength_(strength_),
                                                                               defense_(defense_) {};

Enemy::Enemy():
        xpos_(0), ypos_(0),
        health_(5), strength_(3),
        defense_(1){}

int Enemy::getXpos_() const {
    return xpos_;
}

void Enemy::setXpos_(int xpos_) {
    Enemy::xpos_ = xpos_;
}

int Enemy::getYpos_() const {
    return ypos_;
}

void Enemy::setYpos_(int ypos_) {
    Enemy::ypos_ = ypos_;
}

int Enemy::getHealth_() const {
    return health_;
}

void Enemy::setHealth_(int health_) {
    Enemy::health_ = health_;
}

int Enemy::getStrength_() const {
    return strength_;
}

void Enemy::setStrength_(int strength_) {
    Enemy::strength_ = strength_;
}

int Enemy::getDefense_() const {
    return defense_;
}

void Enemy::setDefense_(int defense_) {
    Enemy::defense_ = defense_;
}

void Enemy::moveUp()
{
    ypos_++;
}

void Enemy::moveDown()
{
    ypos_--;
}

void Enemy::moveRight()
{
    xpos_++;
}

void Enemy::moveLeft()
{
    xpos_--;
}

void Enemy::levelUp()
{
    health_=health_+2;
    strength_=strength_+1;
    defense_=defense_+1;
}

void Enemy::display()
{
    cout << "Enemy" <<endl;
    cout <<"Coordinates:  ("<< getXpos_()<<" , "<<getYpos_()<<")"<<endl;
    cout <<"Health: "<< getHealth_()<<endl;
    cout <<"Strength: "<< getStrength_()<<endl;
    cout <<"Defense: "<< getDefense_()<<endl;
}
//Super Enemy

SuperEnemy::SuperEnemy():
Enemy(0, 0, 7, 5, 3){}

SuperEnemy::SuperEnemy(int xpos_, int ypos_, int health_, int strength_, int defense_) : Enemy(xpos_, ypos_, health_,
                                                                                               strength_, defense_) {};
void SuperEnemy::moveUp()
{
    setYpos_(getYpos_()+2);
}

void SuperEnemy::moveDown()
{
    setYpos_(getYpos_()-2);
}

void SuperEnemy::moveRight()
{
    setXpos_(getXpos_()+2);
}

void SuperEnemy::moveLeft()
{
    setXpos_(getXpos_()-2);
}

void SuperEnemy::levelUp()
{
    setHealth_(getHealth_()+5);
    setStrength_(getStrength_()+3);
    setDefense_(getDefense_()+2);
}

void SuperEnemy::display()
{
    cout << "Super Enemy" <<endl;
    cout <<"Coordinates:  ("<< SuperEnemy::getXpos_()<<" , "<<SuperEnemy::getYpos_()<<")"<<endl;
    cout <<"Health: "<< SuperEnemy::getHealth_()<<endl;
    cout <<"Strength: "<< SuperEnemy::getStrength_()<<endl;
    cout <<"Defense: "<< SuperEnemy::getDefense_()<<endl;
}

