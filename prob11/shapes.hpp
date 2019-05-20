#include <string>
#include <iostream>

class shape
{
private:
    int width_;
    int height_;


public:
    shape();
    shape(const int width_,const int height);


    int getWidth_() const;

    void setWidth_(int width_);

    int getHeight_() const;

    void setHeight_(int height_);
};

class Rectangle: public shape{

public:
    Rectangle();
    Rectangle(const int width_, const int height);

    int calcArea();

};

class Triangle: public shape{

public:
    Triangle();
    Triangle(const int width_, const int height);
    int calcArea();

};