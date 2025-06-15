#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
    srand(time(0));
    int Guess_Value = (rand() % (100-1+1)) + 1; // 生成1-100随机数
    int guess = 0;

    while (guess != Guess_Value) {
        cout << "Enter your guess: ";
        cin >> guess;
        if (guess < Guess_Value) cout << "Too small!" << endl;
        else if (guess > Guess_Value) cout << "Too big!" << endl;
    }
    cout << "It's right!";

    return 0;
}