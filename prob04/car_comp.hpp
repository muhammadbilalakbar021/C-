#ifndef CAR_COMP_HPP
#define CAR_COMP_HPP

#include <string>

// Class that represents dates

class Date
{
  private:
    int day_;
    int month_;
    int year_;

  public:
    Date() : day_(1), month_(1), year_(1885) { }

    Date(int day, int month, int year) : day_(day), month_(month), year_(year) { }

    int getDay() const { return day_; }
    int getMonth() const { return month_; }
    int getYear() const { return year_; }

    void setDay(int day) { day_ = day; }
    void setMonth(int month) { month_ = month; }
    void setYear(int year) { year_ = year; }
};

// Class used to identify cars

class Identifier
{
  private:
    std::string name_;
    int id_;
    std::string license_plate_;

  public:
    Identifier() : name_("Ford"), id_(1), license_plate_("123456") { }

    Identifier(const std::string &name, int id, const std::string &license_plate)
      : name_(name), id_(id), license_plate_(license_plate) { }

    std::string getLicensePlate() const { return license_plate_; }
    std::string getName() const { return name_; }
    int getId() const { return id_; }

    void setLicensePlate(const std::string &license_plate) { license_plate_ = license_plate; }
    void setName(const std::string &name) { name_ = name; }
    void setId(int id) { id_ = id; }
};

// Write code for the `Car` class here
class Car{
private:
    Identifier identity_;
    Date release_date_;

public:
    Car();

    Car(const Identifier &identity_, const Date &release_date_);

    Car(const Identifier &identity_);

    Car(const Date &release_date_);

    void print();

    const Identifier &getIdentity_() const;

    void setIdentity_(const Identifier &identity_);

    const Date &getRelease_date_() const;

    void setRelease_date_(const Date &release_date_);
};


#endif
