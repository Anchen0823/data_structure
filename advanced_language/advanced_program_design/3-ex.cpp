#include <iostream>
using namespace std;

double tax(double);

int main()
{
    double m;
    cin >> m;
    cout << tax(m);
}

double tax(double m)
{
    if (m <= 1200) return 0;
    double rest = m - 1200;
    if (rest <= 1000) return 0.05 * rest;
    else if (rest <= 3000) return 0.1 * rest;
    else if (rest <= 5000) return 0.15 * rest;
    else if (rest <= 10000) return 0.2 * rest;
    else if (rest > 10000) return 0.3 * rest;
}