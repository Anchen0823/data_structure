#include <iostream>
using namespace std;

class BaseClass {
public:
    void fn1() {cout << "BaseClass::fn1() called" << std::endl;};
    void fn2() {cout << "BaseClass::fn2() called" << std::endl;};
};

class DerivedClass : public BaseClass {
public:
    void fn1() {cout << "DerivedClass::fn1() called" << std::endl;}
    void fn2() {cout << "DerivedClass::fn2() called" << std::endl;}
};

int main() {
    DerivedClass obj;

    obj.fn1();
    obj.fn2();

    BaseClass* basePtr = &obj;
    basePtr->fn1();
    basePtr->fn2();

    DerivedClass* derivePtr = &obj;
    derivePtr->fn1();
    derivePtr->fn2();

    return 0;
}