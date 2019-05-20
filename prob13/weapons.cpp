
#include "weapons.hpp"

Weapon::Weapon(int attack_min_, int attack_max_, const std::__cxx11::basic_string<char> &name_) : attack_min_(
        attack_min_), attack_max_(attack_max_), name_(name_) {};

Weapon::Weapon():
    attack_min_(1),
    attack_max_(2),
    name_("weapon"){};

int Weapon::getAttack_min_() const {
    return attack_min_;
}

void Weapon::setAttack_min_(int attack_min_) {
    Weapon::attack_min_ = attack_min_;
}

int Weapon::getAttack_max_() const {
    return attack_max_;
}

void Weapon::setAttack_max_(int attack_max_) {
    Weapon::attack_max_ = attack_max_;
}

const string &Weapon::getName_() const {
    return name_;
}

void Weapon::setName_(const string &name_) {
    Weapon::name_ = name_;
}

//Dagger Class

Dagger::Dagger(int attack_min_, int attack_max_, const string &name_, double crit_, double crit_dice_) : Weapon(
        attack_min_, attack_max_, name_), crit_(crit_), crit_dice_(crit_dice_) {};

Dagger::Dagger():
Weapon(2,3,"Dagger"),crit_(3.0),crit_dice_(18){}

double Dagger::getCrit_() const {
    return crit_;
}

void Dagger::setCrit_(double crit_) {
    Dagger::crit_ = crit_;
}

double Dagger::getCrit_dice_() const {
    return crit_dice_;
}

void Dagger::setCrit_dice_(double crit_dice_) {
    Dagger::crit_dice_ = crit_dice_;
};

//Sword Class
ShortSword::ShortSword(int attack_min_, int attack_max_, const string &name_, int multiplier_) : Weapon(attack_min_,
                                                                                                        attack_max_,
                                                                                                        name_),
                                                                                                 multiplier_(
                                                                                                         multiplier_) {};
ShortSword::ShortSword():
Weapon(6,7,"shortsword"),multiplier_(4){}

int ShortSword::getMultiplier_() const {
    return multiplier_;
}

void ShortSword::setMultiplier_(int multiplier_) {
    ShortSword::multiplier_ = multiplier_;
}

Enemy::Enemy(const string &name_, const int &health_) : name_(name_), health_(health_) { };

Enemy::Enemy():
name_("Dragon"),
health_(500){}

const string &Enemy::getName_() const {
    return name_;
}

void Enemy::setName_(const string &name_) {
    Enemy::name_ = name_;
}

int Enemy::getHealth_() const {
    return health_;
}

void Enemy::setHealth_(int health_) {
    Enemy::health_ = health_;
}
