#include <iostream>

short int divide(unsigned short, unsigned short);

int main() 
{
    using namespace std;
    unsigned short a, b;
    cin >> a >> b;
    short int ans = divide(a, b);
    cout << ans;
}

short int divide(unsigned short a, unsigned short b)
{
    if (b==0) return -1;
    return a / b;
}