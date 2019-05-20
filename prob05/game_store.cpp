
#include "game_store.hpp"
#include <iostream>
using namespace std;

GameStore::GameStore():
name_("GamePause"){}

GameStore::GameStore(const std::string &name_):
    name_(name_){}

const std::__cxx11::basic_string<char> &GameStore::getName_() const {
    return name_;
}

void GameStore::setName_(const std::__cxx11::basic_string<char> &name_) {
    GameStore::name_ = name_;
}

Game GameStore::getGames_(int index) const {
    return games_[index];
}


int GameStore::getNum_games_() const {
    return num_games_;
}

void GameStore::setNum_games_(int num_games_) {
    GameStore::num_games_ = num_games_;
}


