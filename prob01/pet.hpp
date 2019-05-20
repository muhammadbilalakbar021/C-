
#ifndef PROB01_PET_H
#define PROB01_PET_H

#include <string>
#include "breed.h"

class Pet : public breed {
public:
    Pet(const std::string &breed_, double weight_);

    Pet() : breed(){
    };

    const std::string &getBreed_() const;

    void setBreed_(const std::string &breed_);

    const double &getWeight_() const;

    void setWeight_(const double &weight_);

    void Print();

private:
    std::string breed_;
    double weight_;
};


#endif //LAB11_PET_H