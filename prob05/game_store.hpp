#ifndef GAME_STORE_HPP
#define GAME_STORE_HPP

#include <string>
#include <iostream>
using namespace std;

class Game
{
  private:
    std::string title_;
    char rating_;
    double price_;

  public:
    Game() : Game("", 'U', 0.0) { }

    Game(const std::string &title, char rating, double price)
      : title_(title), rating_(rating), price_(price) { }

    std::string getTitle() const { return title_; }
    char getRating() const { return rating_; }
    double getPrice() const { return price_; }

    void setTitle(const std::string &title) { title_ = title; }
    void setRating(char rating) { rating_ = rating; }
    void setPrice(double price) { price_ = price; }
};

// Write code for the `GameStore` class here

class GameStore{

private:
    std::string name_;
    Game games_[5];
    int num_games_=0;

public:
    GameStore();

    GameStore(const std::string &name_);

    const std::string &getName_() const;

    void setName_(const std::string &name_);

    Game getGames_(int index) const ;

    void addGame(const Game &game_)
    {
        games_[num_games_]=game_;
        num_games_++;
    }

    int getNum_games_() const;

    void setNum_games_(int num_games_);

    void print(char c)
    {

        int a=getNum_games_();

        for (int i = 0; i <a ; i++) {
            if (getGames_(i).getRating()==c)
            {
                cout << getGames_(i).getTitle() << " : $" << getGames_(i).getPrice()<< endl;
            }

        }
    }

};

#endif
