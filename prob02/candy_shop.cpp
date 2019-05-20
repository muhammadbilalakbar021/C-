#include "candy_shop.hpp"

candy_shop::candy_shop():
        counter(0){}
candy_shop cs;

int candy_shop::getSize() const {
    return counter;
}

const Candy *candy_shop::getCandy() const {
    return candy;
}

