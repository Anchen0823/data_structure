#include <iostream>
using namespace std;

class Circle {
public:
    Circle(double r) : radius(r) {}
    double getArea();
private:
    double radius;
};

double Circle::getArea()
{
    const double pi = 3.1415926;
    return pi * radius * radius;
}

int main() {
    Circle C(2);
    double area = C.getArea();
    cout << area;
}