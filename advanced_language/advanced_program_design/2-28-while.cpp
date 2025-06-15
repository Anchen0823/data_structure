#include <iostream>
using namespace std;

bool isPrime(int);

 int main()
 {
    int i=2;
    while (i <=100) {
        if (isPrime(i)) {
            cout << i << " ";
        }
        i++;
    }
    return 0;
 }

 bool isPrime(int n)
{
    if (n == 1) return false;
    else if (n == 2) return true;
    else{
        int i = 2;
        while (i * i <= n) {
            if (n % i == 0) {
                return false;
            }
            i++;
        }
        return true;
    }
 }