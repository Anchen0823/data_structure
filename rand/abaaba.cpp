#include <iostream>
#include <cmath>

int main()
{
    using namespace std;

    double a = (double)acos(-1);  // 3.141592653589793238462643...
    cout << a << endl;
    printf("%.16lf\n", a);

    cout << 1e-999 << endl;
    
    return 0;
}