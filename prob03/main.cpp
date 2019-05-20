#include <iostream>
#include <string>
#include <fstream>
#include <iostream>
using namespace std;
#include "department_budget.hpp"

int main()
{
  ifstream infile;
  std::string filename;
  std::string line;
  char data[100];

  std::cout << "Enter the name of the Spending Report you want to process: ";
  std::getline(std::cin, filename);

  department_budget db(filename);

  //infile.open(db.getFileName_());
  std::ifstream file(db.getFileName_());

  if (file.is_open())
  {
    getline(file, line);
    db.setName_(line);

    getline(file, line);
    db.setBudget_(std::stod(line));

    double temp=0.0;
    while (getline(file, line)) {
      temp=temp+std::stod(line);
      // using printf() in all tests for consistency
//      printf("%s", line.c_str());
    }
    db.setCurrent_balance_(db.getBudget_()+temp);

    if (db.getCurrent_balance_()>0)
    {
      cout <<   db.getName_();
      cout << "has $" << db.getCurrent_balance_() << "left on their budget";
    }
    else
    {
      cout <<   db.getName_() <<" has gone over budget!";
    }
  } else
  {
    cout << "Enter the name of the Spending Report you want to process: DNE.txt" << endl;
    cout << "Error with the spending report" << endl;
    cout << "Please choose a valid spending report" << endl;
  }




  // If the budget is not -1, then
  // If the Current balance of the department is less than 0
  // The program needs to say.
  // "<department_name> has gone over budget!"
  // else it should just print out
  // "<department_name>" has <current_balance> left on their budget.
  // else if the budget is -1, then we need to output an error message.
  // "Please choose a valid spending report\n";

  return 0;
}
