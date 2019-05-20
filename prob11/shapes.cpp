#include "shapes.hpp"

//Getter And Setter for Shape Class
shape::shape(int width_, int height_) :
width_(width_), height_(height_) {}

shape::shape():
width_(5),height_(10){};

int shape::getWidth_() const {
    return width_;
}

void shape::setWidth_(int w) {
    shape::width_ = w;
}

int shape::getHeight_() const {
    return height_;
}

void shape::setHeight_(int height_) {
    shape::height_ = height_;
}



//Rectangle Class
Rectangle::Rectangle(const int width_, const int height) : shape(width_, height) {}

Rectangle::Rectangle():
shape(1,1){}

int Rectangle::calcArea() {
    return getHeight_()*getWidth_();
}

//Tri class

Triangle::Triangle() :
shape(1,1){}

Triangle::Triangle(const int width_, const int height) : shape(width_, height) {}

int Triangle::calcArea() {
    return getHeight_()*getWidth_();
}