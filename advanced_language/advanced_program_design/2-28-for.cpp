#include <iostream>
using namespace std;

bool isPrime(int);

int main()
{
    for (int i=2;i<=100;i++) {
        if (isPrime(i)) cout << i << " ";
    }
    return 0;
}

bool isPrime(int n)
{
    if (n == 1) return false;
    else if (n == 2) return true;
    else {
        for (int i=2;i*i<=n;i++) {
            if (n % i == 0) return false;
        }
        return true;
    }
}