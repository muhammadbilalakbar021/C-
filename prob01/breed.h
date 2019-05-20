//
// Created by Waqas on 5/12/2019.
//

#ifndef PROB01_BREED_H
#define PROB01_BREED_H

#include <string>

class breed {
public:
    breed();

    breed(const std::string &species_, const std::string &name_, const std::string &color_);

    const std::string &getSpecies_() const;

    void setSpecies_(const std::string &species_);

    const std::string &getName_() const;

    void setName_(const std::string &name_);

    const std::string &getColor_() const;

    void setColor_(const std::string &color_);

private :
    std:: string  species_;
    std:: string  name_;
    std:: string  color_;
};



#endif //LAB11_BREED_H
