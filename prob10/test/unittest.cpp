#include "../buffet.hpp"
#include "gtest_ext.h"
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <random>

TEST(Buffet, OutputFormat) {
  std::ostringstream test_output;
  std::ostringstream test_input;

  std::string name = generate_string(15);

  double f = (double)rand() / RAND_MAX;
  double wallet_input = 18.0 + f * (100.0 - 18.0);

  test_output << "Welcome to the buffet! Please enter your name: ";
  test_input << name << "\n";

  test_output << "Please enter the amount of money in your wallet: $";
  test_input << wallet_input << "\n";

  test_output << "Choose an option:\n";
  test_output << "1 - Dinner - "
              << "$18.50"
              << "\n";
  test_output << "2 - Lunch - "
              << "$13.00"
              << "\n";
  test_output << "Selection: ";
  int option = rand() % 2 + 1;
  test_input << option << "\n";
  double balance = wallet_input;
  if (option == 1) {
    balance -= 18.50;
  } else if (option == 2) {
    balance -= 13.00;
  } else {
    test_output << "Invalid choice, try again\n";
  }

  std::string balance_format = to_string_double(balance);

  test_output << "Thank you for your purchase " << name << ". You have $"
              << balance_format << " left on your account\n";

  std::string unittest_output = test_output.str();
  std::string unittest_input = test_input.str();

  ASSERT_EXECIO_EQ("main", unittest_input, unittest_output);
}

TEST(Buffet, DefaultConstructor) {
  Buffet your_buffet;
  ASSERT_EQ(your_buffet.getDinnerPrice(), 18.00);
  ASSERT_EQ(your_buffet.getLunchPrice(), 12.00);
}

TEST(Buffet, NonDefaultConstructor) {
  Buffet your_buffet(20.00, 14.00);
  ASSERT_EQ(your_buffet.getDinnerPrice(), 20.00);
  ASSERT_EQ(your_buffet.getLunchPrice(), 14.00);
}

TEST(Buffet, ChargeWallet) {
  srand(time(NULL));

  std::string name = generate_string(20);

  double f = (double)rand() / RAND_MAX;
  double wallet_input = 18.0 + f * (100.0 - 18.0);

  Wallet your_wallet(name, wallet_input);
  double balance = your_wallet.getBalance();

  Buffet your_buffet;

  your_buffet.chargeLunch(&your_wallet);

  double unittest_output = balance - 12.00;

  ASSERT_EQ(your_wallet.getBalance(), unittest_output);

  balance = your_wallet.getBalance();

  your_buffet.chargeDinner(&your_wallet);

  unittest_output = balance - 18.00;

  ASSERT_EQ(your_wallet.getBalance(), unittest_output);
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
