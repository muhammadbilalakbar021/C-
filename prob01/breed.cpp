//
// Created by Waqas on 5/12/2019.
//

#include <string>
#include "breed.h"
//Non-Default Constructor
breed::breed(const std::string &species_, const std::string &name_, const std::string &color_) :
        species_(species_),
        name_(name_),
        color_(color_) {}

//Default Constructor
breed::breed() :
        species_("Dog"),
        name_("Pug"),
        color_("Fawn"){}


//Getter and Setter
const std::string &breed::getSpecies_() const {
    return species_;
}

void breed::setSpecies_(const std::string &species_) {
    breed::species_ = species_;
}

const std::string &breed::getName_() const {
    return name_;
}

void breed::setName_(const std::string &name_) {
    breed::name_ = name_;
}

const std::string &breed::getColor_() const {
    return color_;
}

void breed::setColor_(const std::string &color_) {
    breed::color_ = color_;
}



