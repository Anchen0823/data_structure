#include <iostream>
#include <cmath>

int main()
{
    using namespace std;

    double area;
    cout << "Enter the floor area, in square meter, of your home: ";
    cin >> area;
    double side;
    side = sqrt(area);
    cout << "That's the equivalent of a square " << side
         << " meters to the side." << endl;
    cout << "How fascinating!";
    
    return 0;
}