    #include <iostream>

#include "game_store.hpp"

int main()
{
  std::string name;
  int num_games;

  std::string game_name;
  char game_rating;
  double game_price;

  std::cout << "Welcome to Game Store inventory system. ESRB rating edition\n";
  std::cout << "What is the name of the store? ";
  std::getline(std::cin, name);

  // Make the `GameStore` object here using the non-default constructor
  GameStore gameStore;

  for (int i = 0; i < 5; i++) {
    std::cout << "What is the name of the game you are going to put into inventory? ";
    std::getline(std::cin, game_name);

    std::cout << "What is the rating for " << game_name << "? ";
    std::cin >> game_rating;

    std::cout << "What is the price for " << game_name << "? ";
    std::cin >> game_price;

    std::cin.ignore();

    // Create a `Game` object using the non-default constructor and
    // pass in the values obtained through the user input

    Game game;
    game.setTitle(game_name);
    game.setRating(game_rating);
    game.setPrice(game_price);

    gameStore.addGame(game);

    // Call the right function so we SET the `Game` object we just made to an
    // index in our GameStore's list of games.

  }

  char search_criteria;
  std::cout << "What rating of game do you want to buy? ";
  std::cin >> search_criteria;

    gameStore.print(search_criteria);


  // Call the function that prints out the games with a rating we are
  // "searching" for.

  return 0;
}
