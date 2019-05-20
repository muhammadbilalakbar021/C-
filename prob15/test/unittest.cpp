#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <random>
#include <cmath>
#include <string>
#include <fstream>
#include <list>
#include "gtest_ext.h"
#include "../car.hpp"

TEST(Car, accessor_mutator)
{
  Car your_car;
  your_car.setYear(1996);
  your_car.setName("testing_name");
  your_car.drive(64.5);
  ASSERT_EQ(your_car.getName(),"testing_name") << "your accessor name() was not returning correctly, or your mutators set_name() did not set the name correctly";
  ASSERT_EQ(your_car.getYear(), 1996) << "your accessor year() was not working correctly, or your mutator set_year() did not set the year correctly";
  ASSERT_EQ(your_car.getSpeed(), 64.5) << "your accessor speed() was not working correctly, or your mutator set_speed() did not set the year correctly";

}

TEST(Car, default_constructor) {
  Car your_car;
  ASSERT_EQ(your_car.getName(),"Steam automobile") <<"Either your constructor did not set name_ to the empty string or your accessor name() was not working correctly";
  ASSERT_EQ(your_car.getYear(), 1769) << "Either your constructor did not set year_ to 1769, or your accessor year() was not working correctly";
  ASSERT_EQ(your_car.getSpeed(), 0) << "Either your constructor did not set speed_ to 0, or your accessor speed() was not working correctly";
}

TEST(Car, non_default_constructor)
{
  srand(time(NULL));
  std::string unittest_name = generate_string(10);
  int unittest_year = rand()%2018;
  Car your_car(unittest_name,unittest_year);
  ASSERT_EQ(your_car.getName(),unittest_name) <<"Either your constructor did not set name_ to the first parameter, or your accessor name() was not working correctly";
  ASSERT_EQ(your_car.getYear(), unittest_year) << "Either your constructor did not set year_ to the second parameter, or your accessor year() was not working correctly";
  ASSERT_EQ(your_car.getSpeed(), 0) << "Either your constructor did not set speed_ to 0, or your accessor speed() was not working correctly";

}

TEST(Car, drive)
{
  srand(time(NULL));
  std::string unittest_name = generate_string(10);
  int unittest_year = rand()%2018;
  Car your_car(unittest_name,unittest_year);
  ASSERT_EQ(your_car.getName(),unittest_name) <<"Either your constructor did not set name_ to the first parameter, or your accessor name() was not working correctly";
  ASSERT_EQ(your_car.getYear(), unittest_year) << "Either your constructor did not set year_ to the second parameter, or your accessor year() was not working correctly";
  ASSERT_EQ(your_car.getSpeed(), 0) << "Either your constructor did not set _speed to 0, or your accessor speed() was not working correctly";

  double unittest_speed = rand()%100;
  your_car.drive(unittest_speed);
  ASSERT_EQ(your_car.getSpeed(), unittest_speed) << "Either drive() did not set the speed correctly, or your accessor speed() was not returning the speed value generated";
  ASSERT_EQ(your_car.isEmpty(), false) << "In the car class, is_empty should ALWAYS RETURN FALSE";
}

TEST(ElectricCar, non_default_constructor){
  srand(time(NULL));
  std::string unittest_name = generate_string(10);
  int unittest_year = rand()%2018;
  ElectricCar your_electric_car(unittest_name,unittest_year);
  ASSERT_EQ(your_electric_car.getName(),unittest_name) <<"Either your constructor did not set name_ to the first parameter, or your accessor name() was not working correctly";
  ASSERT_EQ(your_electric_car.getYear(), unittest_year) << "Either your constructor did not set year_ to the second parameter, or your accessor year() was not working correctly";
  ASSERT_EQ(your_electric_car.getSpeed(), 0) << "Either your constructor did not set _speed to 0, or your accessor speed() was not working correctly";
}
TEST(ElectricCar, drive_and_is_empty){
  srand(time(NULL));
  std::string unittest_name = generate_string(10);
  int unittest_year = rand()%2018;
  ElectricCar your_electric_car(unittest_name,unittest_year);
  ASSERT_EQ(your_electric_car.getName(),unittest_name) <<"Either your constructor did not set name_ to the first parameter, or your accessor name() was not working correctly";
  ASSERT_EQ(your_electric_car.getYear(), unittest_year) << "Either your constructor did not set year_ to the second parameter, or your accessor year() was not working correctly";
  ASSERT_EQ(your_electric_car.getSpeed(), 0) << "Either your constructor did not set _speed to 0, or your accessor speed() was not working correctly";
  ASSERT_DURATION_LE(3,{
    do{
      your_electric_car.drive(50);
    }while(!your_electric_car.isEmpty());
  } );
  ASSERT_EQ(your_electric_car.getSpeed(), 0);
  ASSERT_EQ(your_electric_car.isEmpty(), true) << "The test ran and drove the car until it was empty. is_empty should have returned true";
}

TEST(GasolineCar, non_default_constructor){
  srand(time(NULL));
  std::string unittest_name = generate_string(10);
  int unittest_year = rand()%2018;
  int random_tank = rand()%20;
  int unittest_mpg = rand()%30;
  GasolineCar your_gasoline_car(unittest_name,unittest_year,random_tank,unittest_mpg);
  ASSERT_EQ(your_gasoline_car.getName(),unittest_name) <<"Either your constructor did not set name_ to the first parameter, or your accessorr name() was not working correctly";
  ASSERT_EQ(your_gasoline_car.getYear(), unittest_year) << "Either your constructor did not set year_ to the second parameter, or your accessor year() was not working correctly";
  ASSERT_EQ(your_gasoline_car.getSpeed(), 0) << "Either your constructor did not set _speed to 0, or your accessor speed() was not working correctly";
}
TEST(GasolineCar, drive_and_is_empty){
  srand(time(NULL));
  std::string unittest_name = generate_string(10);
  int unittest_year = rand()%2018;
  int random_tank = rand()%20;
  int unittest_mpg = rand()%30;
  GasolineCar your_gasoline_car(unittest_name,unittest_year,random_tank,unittest_mpg);
  ASSERT_EQ(your_gasoline_car.getName(),unittest_name) <<"Either your constructor did not set name_ to the first parameter, or your accessor name() was not working correctly";
  ASSERT_EQ(your_gasoline_car.getYear(), unittest_year) << "Either your constructor did not set year_ to the second parameter, or your accessor year() was not working correctly";
  ASSERT_EQ(your_gasoline_car.getSpeed(), 0) << "Either your constructor did not set _speed to 0, or your accessor speed() was not working correctly";
  ASSERT_DURATION_LE(3,{
    do{
      your_gasoline_car.drive(50);
    }while(!your_gasoline_car.isEmpty());
  });
  ASSERT_EQ(your_gasoline_car.getSpeed(), 0);
  ASSERT_EQ(your_gasoline_car.isEmpty(), true) << "The test ran and drove the car until it was empty. is_empty should have returned true";
}

TEST(virtual_functions, virtual_functions_test_gasoline_car){
  Car *your_car;
  srand(time(NULL));
  std::string unittest_name = generate_string(10);
  int unittest_year = rand()%2018;
  int random_tank = 12;
  int unittest_mpg = 30;
  your_car = new GasolineCar(unittest_name,unittest_year,random_tank,unittest_mpg);
  int hourstaken =0;
  ASSERT_DURATION_LE(3,{
    do{
      your_car->drive(50);
      hourstaken++;
    }while(!your_car->isEmpty());
  });
  ASSERT_EQ(hourstaken, 8) << "Drive should subtract speed/mpg from the tank in a gasoline car. So if I drove until the tank was empty I should go for about 8 hours.";
  delete your_car;
}

TEST(virtual_functions, virtual_functions_test_electric_car){
  Car *your_car;
  srand(time(NULL));
  std::string unittest_name = generate_string(10);
  int unittest_year = rand()%2018;
  your_car = new ElectricCar(unittest_name,unittest_year);
  int hourstaken =0;
  ASSERT_DURATION_LE(3,{
    do{
      your_car->drive(50);
      hourstaken++;
    }while(!your_car->isEmpty());
  });
  ASSERT_EQ(hourstaken, 8) << "Drive should subtract a percentage from the battery in a gasoline car. So if I drove until the tank was empty I should go for about 8 hours.";
  delete your_car;
}


TEST(main_output, GasolineCar)
{
  std::ostringstream test_output;
  std::ostringstream test_input;
  std::string name = generate_string(15);
  test_output << "Ubiquitous on-board driving management software test: - Gas/battery level sensor - \n";
  test_output << "What type of car is being tested?\n";
  test_output << "1 - Gasoline Car\n";
  test_output << "2 - Electric Car\n";
  test_output << "0 - Exit\n";
  test_input<< 1<<"\n";

  test_output << "What is the name of the car? ";
  test_input << name<<"\n";
  test_output << "What year is the car? ";
  int year = rand()%22+1996;
  test_input << year<<"\n";
  test_output << "How many gallons of gas can this car store? ";
  test_input << "12\n";
  test_output << "How much MPG does this car have? ";
  test_input << "30" <<"\n";

  test_output << "How fast do you want to drive this car per hour? ";
  test_input << 50 << "\n";
  test_output << "It took " << name <<", "<< "8 hour(s) of driving to empty the tank\n";
  std::string unittest_input = test_input.str(), unittest_output = test_output.str();
  ASSERT_EXECIO_EQ("main", test_input.str(), test_output.str());
}

TEST(main_output, ElectricCar)
{
  std::ostringstream test_output;
  std::ostringstream test_input;
  std::string name = generate_string(15);
  test_output << "Ubiquitous on-board driving management software test: - Gas/battery level sensor - \n";
  test_output << "What type of car is being tested?\n";
  test_output << "1 - Gasoline Car\n";
  test_output << "2 - Electric Car\n";
  test_output << "0 - Exit\n";
  test_input<< 2<<"\n";

  test_output << "What is the name of the car? ";
  test_input << name<<"\n";
  test_output << "What year is the car? ";
  int year = rand()%22+1996;
  test_input << year<<"\n";

  test_output << "How fast do you want to drive this car per hour? ";
  test_input << 60 << "\n";
  test_output << "It took " << name <<", "<< "7 hour(s) of driving to empty the battery\n";
  std::string unittest_input = test_input.str(), unittest_output = test_output.str();
  ASSERT_EXECIO_EQ("main", test_input.str(), test_output.str());
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
