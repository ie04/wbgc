
/* 
 * File:   main.cpp
 * Author: ie04
 *
 * Created on December 8, 2018, 1:12 PM
 */

#include <iostream>
#include <string>
class basiclass{
    public:
        basiclass();
        basiclass(std::string, int);
        basiclass(basiclass &orig);
        ~basiclass();
    private:
        std::string name;
        int length;
};
void copyclass(basiclass tocp);
basiclass::basiclass(){
    std::cout << "Calling Constructor..." << std::endl;
    length = 0;
}
basiclass::basiclass(std::string newname, int newlength){
    std::cout << "Calling Constructor..." << std::endl;
    name = newname;
    length = newlength;
}
basiclass::basiclass(basiclass &orig){
    std::cout << "Calling Copy Constructor..." << std::endl;
}
basiclass::~basiclass(){
    std::cout << "Calling Destructor..." << std::endl;
}


void addtwoto(int *thisnumber);
int main(int argc, char** argv) {
    basiclass dudebro;
    copyclass(dudebro);
    return 0;
}
void copyclass(basiclass tocp){
    std::cout << "Successfully copied..." << std::endl;
}
