#include "../milktea.hpp"
#include "gtest_ext.h"
#include <gmock/gmock.h>
#include <gtest/gtest.h>
#include <random>

TEST(MilkTea, OutputFormat) {
  std::string unittest_output = "Topping: Pudding\n"
                                "Cost: $1.00\n"
                                "Topping: Pudding\n"
                                "Cost: $1.00\n"
                                "Flavor: Honey Milk Tea\n"
                                "Topping: Aloe\n"
                                "Cost: $1.50\n";

  ASSERT_EXECIO_EQ("main", "", unittest_output);
}

TEST(MilkTea, PublicMethodPresent) {
  Topping *your_topping1, your_topping2;
  your_topping1 = &your_topping2;

  MilkTea your_milktea1;
  MilkTea your_milktea2("Name", your_topping1);

  your_milktea2.getFlavor();
  your_milktea2.setFlavor("F");
  your_milktea2.getTopping();
  your_milktea2.setTopping(your_topping1);

  std::string unittest_output = "Flavor: F Milk Tea\n"
                                "Topping: Boba\n"
                                "Cost: $0.50\n";

  ASSERT_SIO_EQ("", unittest_output, { your_milktea2.printMilkTea(); });
}

TEST(MilkTea, AccessorsAndMutators) {
  std::string unittest_name = "Grass Jelly";
  double unittest_cost = 0.75;

  Topping your_topping1(unittest_name, unittest_cost), *your_topping2;
  your_topping2 = &your_topping1;

  MilkTea your_milktea;

  std::string unittest_flavor = generate_string(10);
  your_milktea.setFlavor(unittest_flavor);

  ASSERT_EQ(your_milktea.getFlavor(), unittest_flavor);

  your_milktea.setTopping(your_topping2);
  Topping your_topping = your_milktea.getTopping();

  ASSERT_EQ(your_topping.getName(), unittest_name);
  ASSERT_EQ(your_topping.getCost(), unittest_cost);
}

TEST(MilkTea, DefaultConstructor) {
  MilkTea your_milktea;

  std::string unittest_output = "Classic";

  ASSERT_EQ(your_milktea.getFlavor(), unittest_output);
}

TEST(MilkTea, NonDefaultConstructor) {
  std::string unittest_name = "Sea Salt";
  double unittest_cost = 0.25;

  Topping your_topping1(unittest_name, unittest_cost), *your_topping2;
  your_topping2 = &your_topping1;

  std::string unittest_flavor = "Flavor";

  MilkTea your_milktea(unittest_flavor, your_topping2);

  Topping your_topping = your_milktea.getTopping();

  ASSERT_EQ(your_milktea.getFlavor(), unittest_flavor);
  ASSERT_EQ(your_topping.getName(), unittest_name);
  ASSERT_EQ(your_topping.getCost(), unittest_cost);
}

TEST(MilkTea, PrintMilkTea) {
  srand(time(NULL));
  for (int i = 0; i < 20; i++) {
    std::string unittest_random_name = generate_string(10);

    double f = (double)rand() / RAND_MAX;
    double unittest_random_cost = 0.0 + f * (3.00 - 0.0);

    Topping your_topping1(unittest_random_name, unittest_random_cost),
        *your_topping2;
    your_topping2 = &your_topping1;

    std::string unittest_random_flavor = generate_string(10);

    MilkTea your_milktea(unittest_random_flavor, your_topping2);

    std::ostringstream ss;
    ss << "Flavor: " << unittest_random_flavor << " Milk Tea\n";
    ss << "Topping: " << unittest_random_name << "\n";
    ss << "Cost: $" << std::fixed << std::setprecision(2)
       << unittest_random_cost << "\n";

    std::string unittest_output = ss.str();

    ASSERT_SIO_EQ("", unittest_output, { your_milktea.printMilkTea(); });
  }
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
