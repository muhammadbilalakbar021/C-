int main()
{
  std::string name;
  double balance;

  std::cout << "Welcome to the buffet! Please enter your name: ";
  std::getline(std::cin, name);
  std::cout << "Please enter the amount of money in your wallet: $";
  std::cin >> balance;

  // Create an instance to the `Wallet` object called `my_wallet` and use
  // its non-default constructor by passing in the values entered by the user

  // Create an instance to the `Buffet` object called `resturaunt` and use
  // its non-default constructor by passing in a dinner price of 18.50
  // and a lunch price of 13.00

  int option;
  std::cout << "Choose an option:\n";
  std::cout << "1 - Dinner - $" << std::fixed << std::setprecision(2)
            << resturaunt.dinnerPrice() << "\n";
  std::cout << "2 - Lunch - $" << std::fixed << std::setprecision(2)
            << resturaunt.lunchPrice() << "\n";
  std::cout << "Selection: ";
  std::cin >> option;

  if (option == 1) {
    // Charge the appropriate amount to the wallet
  }
  else if (option == 2) {
    // Charge the appropriate amount to the wallet
  }
  else {
    std::cout << "Invalid choice, try again\n";
  }

  std::string owner;
  double wallet_balance;

  // Use the `Wallet` object to retrieve the name of the owner and
  // store it in the variable `owner`

  // Use the `Wallet` object to retrieve the remaining balance and
  // store it in the variable `wallet_balance`

  std::cout << "Thank you for your purchase " << owner << ". You have $"
            << wallet_balance << " left on your account\n";

  return 0;
}
