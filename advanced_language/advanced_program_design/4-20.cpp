#include <iostream>
using namespace std;

class Complex {
public:
    // 使用虚数构造
    Complex(double r, double i) : real(r), imag(i) {}

    // 使用实数构造
    Complex(double r) : real(r), imag(0) {}

    Complex add(Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }

    void show() const {
        cout << real;
        if (imag >= 0) cout << "+";
        cout << imag << "i" << endl;
    }
private:
    double real;
    double imag;
};

int main() {
    Complex c1(3, 5);
    Complex c2 = 4.5;

    c1 = c1.add(c2);
    c1.show();

    return 0;
}