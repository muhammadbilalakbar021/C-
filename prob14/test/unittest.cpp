#include "../cash_debit_card.hpp"
#include "gtest_ext.h"
#include <gmock/gmock.h>
#include <gtest/gtest.h>

TEST(CashCard, OutputFormatNormal) {
  std::ostringstream test_output;
  std::ostringstream test_input;
  std::string name = generate_string(10);
  int choice;
  double amount_due, balance;
  test_output << "Enter the total price: $";
  test_input << 30.00 << "\n";
  test_output << "Enter your name: ";
  test_input << name << "\n";
  test_output << "Choose the card you will be paying with:\n";
  test_output << "1 - Cash Card\n";
  test_output << "2 - Debit Card\n";
  test_output << "Choice: ";
  test_input << 1 << "\n";
  test_output << "Enter the balance on your card: $";
  test_input << 80.00 << "\n";
  test_output << "The amount left on your card is $" << std::fixed
              << std::setprecision(2) << 50.00 << "\n";

  std::string unittest_output = test_output.str();
  std::string unittest_input = test_input.str();

  ASSERT_EXECIO_EQ("main", unittest_input, unittest_output);
}
TEST(CashCard, OutputFormatOverdraw) {
  std::ostringstream test_output;
  std::ostringstream test_input;
  std::string name = generate_string(10);
  int choice;
  double amount_due, balance;
  test_output << "Enter the total price: $";
  test_input << 30.00 << "\n";
  test_output << "Enter your name: ";
  test_input << name << "\n";
  test_output << "Choose the card you will be paying with:\n";
  test_output << "1 - Cash Card\n";
  test_output << "2 - Debit Card\n";
  test_output << "Choice: ";
  test_input << 1 << "\n";
  test_output << "Enter the balance on your card: $";
  test_input << 25.00 << "\n";
  test_output << "Insufficient funds\n";
  test_output << "The amount left on your card is $" << std::fixed
              << std::setprecision(2) << 25.00 << "\n";

  std::string unittest_output = test_output.str();
  std::string unittest_input = test_input.str();

  ASSERT_EXECIO_EQ("main", unittest_input, unittest_output);
}

TEST(DebitCard, OutputFormatNormal) {
  std::ostringstream test_output;
  std::ostringstream test_input;
  std::string name = generate_string(10);
  int choice;
  double amount_due, balance;
  test_output << "Enter the total price: $";
  test_input << 30.00 << "\n";
  test_output << "Enter your name: ";
  test_input << name << "\n";
  test_output << "Choose the card you will be paying with:\n";
  test_output << "1 - Cash Card\n";
  test_output << "2 - Debit Card\n";
  test_output << "Choice: ";
  test_input << 2 << "\n";
  test_output << "Enter the balance on your card: $";
  test_input << 80.00 << "\n";
  test_output << "The amount left on your card is $" << std::fixed
              << std::setprecision(2) << 50.00 << "\n";

  std::string unittest_output = test_output.str();
  std::string unittest_input = test_input.str();

  ASSERT_EXECIO_EQ("main", unittest_input, unittest_output);
}

TEST(DebitCard, OutputFormatOverdraw) {
  std::ostringstream test_output;
  std::ostringstream test_input;
  std::string name = generate_string(10);
  int choice;
  double amount_due, balance;
  test_output << "Enter the total price: $";
  test_input << 30.00 << "\n";
  test_output << "Enter your name: ";
  test_input << name << "\n";
  test_output << "Choose the card you will be paying with:\n";
  test_output << "1 - Cash Card\n";
  test_output << "2 - Debit Card\n";
  test_output << "Choice: ";
  test_input << 2 << "\n";
  test_output << "Enter the balance on your card: $";
  test_input << 25.00 << "\n";
  test_output << "Overdraft Fee of $30.00 Incurred\n";
  test_output << "The amount left on your card is $" << std::fixed
              << std::setprecision(2) << -35.00 << "\n";

  std::string unittest_output = test_output.str();
  std::string unittest_input = test_input.str();

  ASSERT_EXECIO_EQ("main", unittest_input, unittest_output);
}

TEST(CashCard, AccessorsAndMutators) {
  CashCard your_cash_card;
  your_cash_card.setBalance(100.00);
  your_cash_card.setName("testName");

  ASSERT_EQ(your_cash_card.getBalance(), 100.00);
  ASSERT_EQ(your_cash_card.getName(), "testName");
}

TEST(CashCard, DefaultConstructor) {
  CashCard your_cash_card;
  ASSERT_EQ(your_cash_card.getBalance(), 100.00);
  ASSERT_EQ(your_cash_card.getName(), "John Doe");
}

TEST(CashCard, NonDefaultConstructor) {
  std::string unittest_name = generate_string(12);
  double unittest_balance = 120.00;
  CashCard your_cash_card(unittest_balance, unittest_name);
  ASSERT_EQ(your_cash_card.getBalance(), unittest_balance);
  ASSERT_EQ(your_cash_card.getName(), unittest_name);
}

TEST(CashCard, Charge) {
  CashCard your_cash_card;
  your_cash_card.charge(30);

  ASSERT_EQ(your_cash_card.getBalance(), 70.00);

  your_cash_card.charge(30);

  ASSERT_EQ(your_cash_card.getBalance(), 40.00);
  ASSERT_SIO_EQ("", "Insufficient funds\n", { your_cash_card.charge(45.00); });
  ASSERT_EQ(your_cash_card.getBalance(), 40.00);
}

TEST(DebitCard, AccessorsAndMutators) {
  DebitCard your_debit_card;
  your_debit_card.setBalance(100.00);
  your_debit_card.setName("testName");

  ASSERT_EQ(your_debit_card.getBalance(), 100.00);
  ASSERT_EQ(your_debit_card.getName(), "testName");
}

TEST(DebitCard, DefaultConstructor) {
  DebitCard your_debit_card;

  ASSERT_EQ(your_debit_card.getBalance(), 100.00);
  ASSERT_EQ(your_debit_card.getName(), "John Doe");
}

TEST(DebitCard, NonDefaultConstructor) {
  std::string unittest_name = generate_string(12);
  DebitCard your_debit_card(120, unittest_name);

  ASSERT_EQ(your_debit_card.getBalance(), 120.00);
  ASSERT_EQ(your_debit_card.getName(), unittest_name);
}

TEST(DebitCard, Charge) {
  DebitCard your_debit_card;
  your_debit_card.charge(30);

  ASSERT_EQ(your_debit_card.getBalance(), 70.00);

  your_debit_card.charge(30);

  ASSERT_EQ(your_debit_card.getBalance(), 40.00);

  ASSERT_SIO_EQ("", "Overdraft Fee of $30.00 Incurred\n",
                { your_debit_card.charge(45.00); });

  double unittest_output = 40.00 - 45.00 - 30.00;
  ASSERT_EQ(your_debit_card.getBalance(), unittest_output);
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
