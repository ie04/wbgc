
/* 
 * File:   main.cpp
 * Author: ie04
 *
 * Created on December 8, 2018, 12:07 PM
 */

#include <iostream>
#include "rectangle.h"
int main(int argc, char** argv) {
    int width, height;
    std::cout << "Enter Width: ";
    std::cin >> width;
    std::cout << "Enter height: ";
    std::cin >> height;
    
    rectangle dude(width,height);
    dude.drawrect();
    return 0;
}

