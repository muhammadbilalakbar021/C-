#include "../game_store.hpp"
#include "gtest_ext.h"
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <random>

char unittest_ratings_arr[4] = {'E', 'T', 'M', 'U'};

TEST(GameStore, OutputFormat) {
  srand(time(NULL));
  std::ostringstream s;
  std::ostringstream input;

  int random_index = rand() % 4;
  char rating = unittest_ratings_arr[random_index];

  std::string random_name = generate_string(28);
  s << "Welcome to Game Store inventory system. ESRB rating edition\n";
  s << "What is the name of the store? ";
  input << random_name << "\n";
  std::ostringstream post_input_ostringstream;
  for (int i = 0; i < 5; i++) {
    random_name = generate_string(17);
    double random_price = rand() % 100;
    random_index = rand() % 4;
    char random_rating = unittest_ratings_arr[random_index];
    s << "What is the name of the game you are going to put into inventory? ";
    input << random_name << "\n";

    s << "What is the rating for " << random_name << "? ";
    input << random_rating << "\n";

    s << "What is the price for " << random_name << "? ";
    input << random_price << "\n";

    if (random_rating == rating) {
      post_input_ostringstream << random_name << " : $" << random_price << "\n";
    }
  }
  s << "What rating of game do you want to buy? ";
  input << rating << "\n";
  s << "Here are all the games with a rating of " << rating << "\n";

  std::string unittest_output = s.str() + post_input_ostringstream.str();
  std::string unittest_input = input.str();

  ASSERT_DURATION_LE(
      3, { ASSERT_EXECIO_EQ("main", unittest_input, unittest_output); });
}

TEST(Game, DefaultConstructor) {
  Game your_game;
  ASSERT_EQ(your_game.getTitle(), "");
  ASSERT_EQ(your_game.getPrice(), 0.0);
  ASSERT_EQ(your_game.getRating(), 'U');
}

TEST(Game, AccessorsAndMutators) {
  std::string random_name = generate_string(25);
  double random_integer = rand() % 100;
  int random_index = rand() % 4;
  Game your_game;

  your_game.setPrice(random_integer);
  your_game.setTitle(random_name);
  your_game.setRating(unittest_ratings_arr[random_index]);
  ASSERT_EQ(your_game.getTitle(), random_name);
  ASSERT_EQ(your_game.getPrice(), random_integer);
  ASSERT_EQ(your_game.getRating(), unittest_ratings_arr[random_index]);
}

TEST(GameStore, DefaultConstructor) {
  GameStore your_game_store;
  ASSERT_EQ(your_game_store.getNumGames(), 5);
  ASSERT_EQ(your_game_store.getName(), "GamePause");
  ASSERT_EQ(your_game_store.getGame(4).getTitle(), "");
  ASSERT_EQ(your_game_store.getGame(4).getPrice(), 0.0);
  ASSERT_EQ(your_game_store.getGame(4).getRating(), 'U');
}

TEST(GameStore, NonDefaultConstructor) {
  std::string random_name = generate_string(25);
  GameStore your_game_store(random_name);

  ASSERT_EQ(your_game_store.getNumGames(), 5);
  ASSERT_EQ(your_game_store.getName(), random_name);
}

TEST(GameStore, PrintGames) {
  std::ostringstream s;
  int random_index = rand() % 4;
  char rating = unittest_ratings_arr[random_index];
  GameStore your_game_store("Test Store");
  s << "Here are all the games with a rating of " << rating << "\n";

  for (int i = 0; i < 5; i++) {
    std::string random_name = generate_string(15);
    double random_price = rand() % 100;
    random_index = rand() % 4;
    char random_rating = unittest_ratings_arr[random_index];
    Game your_game(random_name, random_rating, random_price);
    if (random_rating == rating) {
      s << random_name << " : $" << random_price << "\n";
    }
    your_game_store.setGame(i, your_game);
  }
  std::string unittest_output = s.str();
  ASSERT_SIO_EQ("", unittest_output, { your_game_store.print(rating); });
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
