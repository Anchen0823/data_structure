#include <iostream>
using namespace std;
void function_1();
void function_2();

int main()
{
    function_1();
    function_1();
    function_2();
    function_2();
}

void function_1()
{
    cout << "Three blind mice" << endl;
}

void function_2()
{
    cout << "See how they run" << endl;
}