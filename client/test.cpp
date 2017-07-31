#include "husky-controll.h"
#include <iostream>
using namespace control;


int main() {
    controlInit("127.0.0.1:38080");
    if(Forward()){
        std::cout << "Yes";
    }
}