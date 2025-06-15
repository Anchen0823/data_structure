#include "5-13classes.h"
#include <iostream>

int main() {
    X obj(0);
    std::cout << "Initiative: 0" << std::endl;
    Y yObj;
    Z zObj;

    yObj.g(&obj);
    std::cout << "After Y::g: " << obj.getValue() << std::endl;

    zObj.f(&obj);
    std::cout << "After Z::f: " << obj.getValue() << std::endl;

    h(&obj);
    std::cout << "After h(): " << obj.getValue() << std::endl;

    return 0;
}