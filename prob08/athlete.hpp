#ifndef ATHLETE_HPP
#define ATHLETE_HPP

class Person
{
private:
  std::string name_;

public:
  std::string getName() const { return name_; }
  void setName(const std::string& n) { name_ = n; }

  Person(const std::string& n) : name_(n) { }
};

// Create the `AthleticShoe` class below...

// Create the `Athlete` class below...

#endif
