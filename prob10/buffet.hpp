#ifndef BUFFET_HPP
#define BUFFET_HPP

#include <string>

class Wallet
{
  private:
    std::string owner_;
    double balance_;

  public:
    Wallet() : Wallet("", 0.0) {}

    Wallet(const std::string &owner, double balance)
      : owner_(owner), balance_(balance) {}

    double getBalance() const { return balance_; }
    std::string getOwner() const { return owner_; }

    void makePurchase(double purchase) { balance_ -= purchase; }
};

// Create the `Buffet` class below...

#endif
