#include <iostream>
int long_to_yard(int);

int main()
{
    using namespace std;
    cout << "Enter the lenth in long: ";
    int _long;
    cin >> _long;
    int yards = long_to_yard(_long);
    cout << _long << " long = ";
    cout << yards << " yards.";
}

int long_to_yard(int sts)
{
    return 200 * sts;
}