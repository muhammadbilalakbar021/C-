
#include "department_budget.hpp"
#include <fstream>
#include <iostream>
using namespace std;



ofstream outfile;
ifstream infile;
department_budget::department_budget(const std::string &fileName) :
fileName_(fileName){}


department_budget::department_budget():
        name_(nullptr),
        budget_(100.0),
        current_balance_(100.0){}

const std::string &department_budget::getName_() const {
    return name_;
}

void department_budget::setName_(const std::string &name_) {
    department_budget::name_ = name_;
}

double department_budget::getBudget_() const {
    return budget_;
}

void department_budget::setBudget_(double budget_) {
    department_budget::budget_ = budget_;
}

double department_budget::getCurrent_balance_() const {
    return current_balance_;
}

void department_budget::setCurrent_balance_(double current_balance_) {
    department_budget::current_balance_ = current_balance_;
}

const string &department_budget::getFileName_() const {
    return fileName_;
}

void department_budget::setFileName_(const string &fileName_) {
    department_budget::fileName_ = fileName_;
}
