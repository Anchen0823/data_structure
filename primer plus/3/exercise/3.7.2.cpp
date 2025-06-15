#include <iostream>
int feet_to_inch(int);
double inch_to_meter(int);
double pound_to_kilo(int);
double bmi(double, double);

int main()
{
    using namespace std;
    int feet, inches, pounds;
    double meters, kilos, BMI;

    cout << "Enter the feet of your height: ";
    cin >> feet;
    cout << "Enter the inches of your height: ";
    cin >> inches;
    cout << "Enter your weight in pounds: ";
    cin >> pounds;

    inches += feet_to_inch(feet);
    cout << "Your height is " << inches << " inches." << endl;

    meters = inch_to_meter(inches);
    kilos = pound_to_kilo(pounds);

    BMI = bmi(meters, kilos);
    cout << "Your BMI is " << BMI << ".";
}

int feet_to_inch(int inches)
{
    const int inch_per_feet = 12;
    return inch_per_feet * inches;
}

double inch_to_meter(int inches)
{
    const float meter_per_inch = 0.0254;
    return meter_per_inch * inches;
}

double pound_to_kilo(int pounds)
{
    const float pound_per_kilo = 2.2046;
    return pounds / pound_per_kilo;
}

double bmi(double meters, double kilos)
{
    return kilos / (meters * meters);
}