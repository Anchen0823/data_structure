#include <iostream>
using namespace std;

double p(int, double);

int main()
{
    int n;
    double x;
    cin >> n >> x;
    cout << p(n, x);

    return 0;
}

double p(int n, double x)
{
    if (n==0) return 1;
    if (n==1) return x;
    return 
        (((2 * n - 1)* x * p(n - 1, x)) - (n - 1) * p(n - 2, x)) / n;
}