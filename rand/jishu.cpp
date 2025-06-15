#include <iostream>
#include <cmath>
unsigned long long factorialRecursive(int);

int main()
{
    using namespace std;
    cout << "输入n: ";
    int n;
    long double s=0;
    cin >> n;

    for (int i=1;i<=n;++i)
    {
        s += pow(2, i) * i / factorialRecursive(i+2);
    }

    cout << "结果为: " << s;
    return 0;
}

unsigned long long factorialRecursive(int n)
{
    unsigned long long result = 1;
    for (int i=1;i<=n;++i)
    {
        result *= i;
    }
    return result;
}