#ifndef CANDY_SHOP_HPP
#define CANDY_SHOP_HPP

#include <iomanip>
#include <iostream>
#include <string>

class Candy
{
  private:
    std::string brand_;
    std::string flavor_;
    double cost_;

  public:
    Candy() : Candy("Skittles", "Fruity", 1.00) { }

    Candy(const std::string &brand, const std::string &flavor, double cost)
      : brand_(brand), flavor_(flavor), cost_(cost) { }

    std::string getBrand() const { return brand_; }
    std::string getFlavor() const { return flavor_; }
    double getCost() const { return cost_; }

    void setBrand(const std::string &brand) { brand_ = brand; }
    void setFlavor(const std::string &flavor) { flavor_ = flavor; }
    void setCost(double cost) { cost_ = cost; }
};

// Write code for the `CandyShop` class here

class candy_shop{
public:
    candy_shop();

    int getSize() const;
    void addCandy(const std::string &brand, const std::string &flavor, double cost)
    {
        if(counter<10)
        {
            Candy c;
            c.setBrand(brand);
            c.setCost(cost);
            c.setCost(cost);
            candy[counter]=c;
            counter++;
        }
    }

    void printBag()
    {
        for (int i = 0; i < counter; i++) {
            std::cout << i+1<<"."<< "Brand : " << candy[i].getBrand()<<'\n';
            std::cout << i+1<<"."<<"Flavour : " << candy[i].getFlavor()<<'\n';
            std::cout << i+1<<"."<<'.'<< "Cost : " << candy[i].getCost()<<'\n';
        }
    }

    const Candy *getCandy() const;


private:
    Candy candy[10];
    int counter=0;



};
#endif
