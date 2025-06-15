#include <iostream>
void print(int, int);

int main()
{
    using namespace std;
    cout << "Enter the number of hours: ";
    int hours;
    cin >> hours;
    cout << "Enter the number of minutes: ";
    int minutes;
    cin >> minutes;
    print(hours, minutes);
}

void print(int hours, int minutes)
{
    using namespace std;
    cout << "Time: " << hours << ":" << minutes << endl;
}