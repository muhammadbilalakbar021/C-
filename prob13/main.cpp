#include "weapons.hpp"
#include <random>
#include <iomanip>
#include <iostream>
#include <string>

int main()
{
  srand(time(nullptr));
  std::string e_name;
  int e_health;

  std::cout << "Please enter the name of an enemy: ";
  std::getline(std::cin, e_name);
  std::cout << "Please enter the enemy's health: ";
  std::cin >> e_health;

  // create an enemy object using the name and health provided by the user.

  Enemy enemy(e_name,e_health);

  Weapon* weapon1 = new Dagger();
  Weapon* weapon2 = new ShortSword();

  // Call the enemy object's receiveAttack method and pass the first weapon as
  // the argument
  enemy.receiveAttack(weapon1);

  // Call the enemy object's receiveAttack method and pass the second weapon as
  // the argument
  enemy.receiveAttack(weapon2);

  if(enemy.getHealth_()<=0)
  {
    cout << enemy.getName_() << "has been slain!";
  }

  return 0;
}
