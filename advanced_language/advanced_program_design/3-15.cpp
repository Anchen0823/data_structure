#include <iostream>

using namespace std;

int getPowwer(int, int);
double getPower(double, int);

int main()
{
    int a, m;
    double b;
    cin >> a >> b >> m;
    cout << getPower(a, m) << endl;
    cout << getPower(b, m);

    return 0;
}

int getPower(int x, int y)
{
    if (y<0) return 0;
    long ans =1;
    while (y--) {
        ans *= x;
    }
    return ans;
}

double getPower(double x, int y)
{
    if (y<0) return 0;
    double ans =1;
    while (y--) {
        ans *= x;
    }
    return ans;
}