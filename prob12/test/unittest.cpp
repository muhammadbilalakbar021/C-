#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <random>
#include <cmath>
#include "gtest_ext.h"
#include "../super_enemy.hpp"

TEST(SuperEnemy, OutputFormat) {
  std::string unittest_output =
  "Enemy\n"
  "Coordinates: (0, 0)\n"
  "Health: 5\n"
  "Strength: 3\n"
  "Defense: 1\n\n"

  "Super Enemy\n"
  "Coordinates: (0, 0)\n"
  "Health: 7\n"
  "Strength: 5\n"
  "Defense: 3\n\n"

  "Enemy\n"
  "Coordinates: (5, 5)\n"
  "Health: 7\n"
  "Strength: 4\n"
  "Defense: 2\n\n"

  "Super Enemy\n"
  "Coordinates: (10, 10)\n"
  "Health: 12\n"
  "Strength: 8\n"
  "Defense: 5\n";

  ASSERT_EXECIO_EQ("main", "", unittest_output);
}

TEST(Enemy, PublicMethodsPresent) {
  Enemy e;
  e.getXpos();
  e.setXpos(1);
  e.getYpos();
  e.setYpos(1);
  e.getHealth();
  e.setHealth(1);
  e.getStrength();
  e.setStrength(1);
  e.getDefense();
  e.setDefense(1);
  e.moveUp();
  e.moveDown();
  e.moveRight();
  e.moveLeft();
  e.levelUp();
  std::string unittest_output =
  "Enemy\n"
  "Coordinates: (1, 1)\n"
  "Health: 3\n"
  "Strength: 2\n"
  "Defense: 2\n";
  ASSERT_SIO_EQ("", unittest_output, {
    e.display();
  });
}

TEST(Enemy, AccessorsAndMutators) {
  srand(time(NULL));
  Enemy your_enemy;
  int unittest_xpos = rand() % 10;
  int unittest_ypos = rand() % 10;
  int unittest_health = rand() % 10;
  int unittest_strength = rand() % 10;
  int unittest_defense = rand() % 10;
  your_enemy.setXpos(unittest_xpos);
  your_enemy.setYpos(unittest_ypos);
  your_enemy.setHealth(unittest_health);
  your_enemy.setStrength(unittest_strength);
  your_enemy.setDefense(unittest_defense);
  ASSERT_EQ(your_enemy.getXpos(), unittest_xpos);
  ASSERT_EQ(your_enemy.getYpos(), unittest_ypos);
  ASSERT_EQ(your_enemy.getHealth(), unittest_health);
  ASSERT_EQ(your_enemy.getStrength(), unittest_strength);
  ASSERT_EQ(your_enemy.getDefense(), unittest_defense);
}

TEST(Enemy, DefaultConstructor) {
  Enemy your_enemy;
  int unittest_xpos = 0;
  int unittest_ypos = 0;
  int unittest_health = 5;
  int unittest_strength = 3;
  int unittest_defense = 1;
  ASSERT_EQ(your_enemy.getXpos(), unittest_xpos);
  ASSERT_EQ(your_enemy.getYpos(), unittest_ypos);
  ASSERT_EQ(your_enemy.getHealth(), unittest_health);
  ASSERT_EQ(your_enemy.getStrength(), unittest_strength);
  ASSERT_EQ(your_enemy.getDefense(), unittest_defense);
}

TEST(Enemy, MoveUp) {
  Enemy your_enemy;
  for(int i = 0; i < 20; i++) {
    int unittest_ypos = rand() % 20;
    your_enemy.setYpos(unittest_ypos);
    your_enemy.moveUp();
    unittest_ypos++;
    ASSERT_EQ(your_enemy.getYpos(), unittest_ypos);
  }
}

TEST(Enemy, MoveDown) {
  Enemy your_enemy;
  for(int i = 0; i < 20; i++) {
    int unittest_ypos = rand() % 20;
    your_enemy.setYpos(unittest_ypos);
    your_enemy.moveDown();
    unittest_ypos--;
    ASSERT_EQ(your_enemy.getYpos(), unittest_ypos);
  }
}

TEST(Enemy, MoveRight) {
  Enemy your_enemy;
  for(int i = 0; i < 20; i++) {
    int unittest_xpos = rand() % 20;
    your_enemy.setXpos(unittest_xpos);
    your_enemy.moveRight();
    unittest_xpos++;
    ASSERT_EQ(your_enemy.getXpos(), unittest_xpos);
  }
}

TEST(Enemy, MoveLeft) {
  Enemy your_enemy;
  for(int i = 0; i < 20; i++) {
    int unittest_xpos = rand() % 20;
    your_enemy.setXpos(unittest_xpos);
    your_enemy.moveLeft();
    unittest_xpos--;
    ASSERT_EQ(your_enemy.getXpos(), unittest_xpos);
  }
}

TEST(Enemy, LevelUp) {
  Enemy your_enemy;
  int unittest_health = rand() % 20;
  int unittest_strength = rand() % 20;
  int unittest_defense = rand() % 20;
  your_enemy.setHealth(unittest_health);
  your_enemy.setStrength(unittest_strength);
  your_enemy.setDefense(unittest_defense);
  your_enemy.levelUp();
  unittest_health += 2;
  unittest_strength++;
  unittest_defense++;
  ASSERT_EQ(your_enemy.getHealth(), unittest_health);
  ASSERT_EQ(your_enemy.getStrength(), unittest_strength);
  ASSERT_EQ(your_enemy.getDefense(), unittest_defense);
}

TEST(Enemy, Display) {
  Enemy your_enemy;
  int unittest_xpos = rand() % 20;
  int unittest_ypos = rand() % 20;
  int unittest_health = rand() % 20;
  int unittest_strength = rand() % 20;
  int unittest_defense = rand() % 20;
  your_enemy.setXpos(unittest_xpos);
  your_enemy.setYpos(unittest_ypos);
  your_enemy.setHealth(unittest_health);
  your_enemy.setStrength(unittest_strength);
  your_enemy.setDefense(unittest_defense);
  std::string unittest_output =
  "Enemy\n"
  "Coordinates: (" + std::to_string(unittest_xpos) + ", "
  + std::to_string(unittest_ypos) + ")\n"
  "Health: " + std::to_string(unittest_health) + "\n"
  "Strength: " + std::to_string(unittest_strength) + "\n"
  "Defense: " + std::to_string(unittest_defense) + "\n";
  ASSERT_SIO_EQ("", unittest_output, {
    your_enemy.display();
  });
}

TEST(SuperEnemy, PublicMethodsPresent) {
  SuperEnemy se;
  se.moveUp();
  se.moveDown();
  se.moveRight();
  se.moveLeft();
  se.levelUp();
  std::string unittest_output =
  "Super Enemy\n"
  "Coordinates: (0, 0)\n"
  "Health: 12\n"
  "Strength: 8\n"
  "Defense: 5\n";
  ASSERT_SIO_EQ("", unittest_output, {
    se.display();
  });
}

TEST(SuperEnemy, MoveUp) {
  SuperEnemy your_SuperEnemy;
  for(int i = 0; i < 20; i++) {
    int unittest_ypos = rand() % 20;
    your_SuperEnemy.setYpos(unittest_ypos);
    your_SuperEnemy.moveUp();
    unittest_ypos += 2;
    ASSERT_EQ(your_SuperEnemy.getYpos(), unittest_ypos);
  }
}

TEST(SuperEnemy, MoveDown) {
  SuperEnemy your_SuperEnemy;
  for(int i = 0; i < 20; i++) {
    int unittest_ypos = rand() % 20;
    your_SuperEnemy.setYpos(unittest_ypos);
    your_SuperEnemy.moveDown();
    unittest_ypos -= 2;
    ASSERT_EQ(your_SuperEnemy.getYpos(), unittest_ypos);
  }
}

TEST(SuperEnemy, MoveRight) {
  SuperEnemy your_SuperEnemy;
  for(int i = 0; i < 20; i++) {
    int unittest_xpos = rand() % 20;
    your_SuperEnemy.setXpos(unittest_xpos);
    your_SuperEnemy.moveRight();
    unittest_xpos += 2;
    ASSERT_EQ(your_SuperEnemy.getXpos(), unittest_xpos);
  }
}

TEST(SuperEnemy, MoveLeft) {
  SuperEnemy your_SuperEnemy;
  for(int i = 0; i < 20; i++) {
    int unittest_xpos = rand() % 20;
    your_SuperEnemy.setXpos(unittest_xpos);
    your_SuperEnemy.moveLeft();
    unittest_xpos -= 2;
    ASSERT_EQ(your_SuperEnemy.getXpos(), unittest_xpos);
  }
}

TEST(SuperEnemy, LevelUp) {
  SuperEnemy your_SuperEnemy;
  int unittest_health = rand() % 20;
  int unittest_strength = rand() % 20;
  int unittest_defense = rand() % 20;
  your_SuperEnemy.setHealth(unittest_health);
  your_SuperEnemy.setStrength(unittest_strength);
  your_SuperEnemy.setDefense(unittest_defense);
  your_SuperEnemy.levelUp();
  unittest_health += 5;
  unittest_strength += 3;
  unittest_defense += 2;
  ASSERT_EQ(your_SuperEnemy.getHealth(), unittest_health);
  ASSERT_EQ(your_SuperEnemy.getStrength(), unittest_strength);
  ASSERT_EQ(your_SuperEnemy.getDefense(), unittest_defense);
}

TEST(SuperEnemy, Display) {
  SuperEnemy your_SuperEnemy;
  int unittest_xpos = rand() % 20;
  int unittest_ypos = rand() % 20;
  int unittest_health = rand() % 20;
  int unittest_strength = rand() % 20;
  int unittest_defense = rand() % 20;
  your_SuperEnemy.setXpos(unittest_xpos);
  your_SuperEnemy.setYpos(unittest_ypos);
  your_SuperEnemy.setHealth(unittest_health);
  your_SuperEnemy.setStrength(unittest_strength);
  your_SuperEnemy.setDefense(unittest_defense);
  std::string unittest_output =
  "Super Enemy\n"
  "Coordinates: (" + std::to_string(unittest_xpos) + ", "
  + std::to_string(unittest_ypos) + ")\n"
  "Health: " + std::to_string(unittest_health) + "\n"
  "Strength: " + std::to_string(unittest_strength) + "\n"
  "Defense: " + std::to_string(unittest_defense) + "\n";
  ASSERT_SIO_EQ("", unittest_output, {
    your_SuperEnemy.display();
  });
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
