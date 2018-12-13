
/* 
 * File:   main.cpp
 * Author: ie04
 *
 * Created on December 8, 2018, 3:22 PM
 */
#include "SDL.h"
#include <iostream>
int main(int argc, char** argv) {
    int error_catch;
    error_catch = SDL_Init(SDL_INIT_VIDEO);
    if(error_catch != 0){
        std::cout << "Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
    }

    return 0;
}

