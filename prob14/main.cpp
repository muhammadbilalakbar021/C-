#include "cash_debit_card.hpp"
#include <iomanip>
#include <iostream>
#include <string>

int main()
{
  std::string name;
  int choice;
  double amount_due, balance;

  std::cout << "Enter the total price: $";
  std::cin >> amount_due;
  std::cin.ignore();
  std::cout << "Enter your name: ";
  std::getline(std::cin, name);
  std::cout << "Choose the card you will be paying with:\n";
  std::cout << "1 - Cash Card\n";
  std::cout << "2 - Debit Card\n";
  std::cout << "Choice: ";
  std::cin >> choice;
  std::cout << "Enter the balance on your card: $";
  std::cin >> balance;

  if (choice == 1) {
    // Create an instance of the `CashCard` object using the non-default
    // constructor and passing in the values entered by the user

    // Charge the card by calling the respective function

    std::cout << "The amount left on your card is $" << std::setprecision(2)
              << std::fixed << card.getBalance() << "\n";
  }
  else if (choice == 2) {
    // Create an instance of the `DebitCard` object using the non-default
    // constructor and passing in the values entered by the user

    // Charge the card by calling the respective function

    std::cout << "The amount left on your card is $" << std::setprecision(2)
              << std::fixed << card.getBalance() << "\n";
  }
  else {
    std::cout << "Error - Invalid Option, please try again.\n";
  }

  return 0;
}
