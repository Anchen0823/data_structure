#include <iostream>
using namespace std;

int fib(int n)
{
    if (n==1 || n==2) {
        return 1;
    }
    else return fib(n-1) + fib(n-2);
}

int main()
{
    int N;
    cin >> N;
    for (int i=1;i<=N;i++) {
        cout << fib(i) << " ";
    }
}