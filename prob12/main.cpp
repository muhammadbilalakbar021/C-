#include "super_enemy.hpp"
#include <iostream>

int main() {
  // Create an Enemy object

  Enemy enemy;
  // Create a SuperEnemy object
  SuperEnemy superEnemy;

  // Call the Enemy object's display method
  enemy.display();

  std::cout << "\n";

  // Call the SuperEnemy object's display method
  superEnemy.display();

  std::cout << "\n";

  // Have both objects call their respective moveUp and moveRight
  // methods 10 times
  for (int i = 0; i < 10; i++) {
    // place code here
    enemy.moveUp();
    enemy.moveRight();

    superEnemy.moveUp();
    superEnemy.moveRight();
  }

  // Have both objects call their respective moveDown and moveLeft
  // methods 5 times
  for (int i = 0; i < 5; i++) {
    // place code here
    enemy.moveDown();
    enemy.moveLeft();

    superEnemy.moveDown();
    superEnemy.moveLeft();
  }

  // Call the enemy object's levelUp method
  enemy.levelUp();

  // Call the SuperEnemy object's levelUp method
  superEnemy.levelUp();

  // Call the enemy object's display method
  enemy.display();

  std::cout << "\n";

  // Call the SuperEnemy object's display method

  superEnemy.display();
  return 0;
}
