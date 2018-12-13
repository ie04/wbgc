
/* 
 * File:   rectangle.cpp
 * Author: ie04
 * 
 * Created on December 8, 2018, 12:08 PM
 */

#include "rectangle.h"
#include <iostream>
rectangle::rectangle() {
    width = 0;
    height = 0;
}
rectangle::rectangle(int newwidth, int newheight) {
    width = newwidth;
    height = newheight;
}
rectangle::~rectangle() {
}
void rectangle::drawrect() const {
    drawrect(width, height);
}
void rectangle::drawrect(int width, int height) const{
    for(int i=0;i<height;i++){
        for(int j=0;j<width;j++)
            std::cout << "*";
        std::cout << std::endl;
    }
}