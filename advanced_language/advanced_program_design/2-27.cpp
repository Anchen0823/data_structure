#include <iostream>
using namespace std;

int main()
{
    int score;
    cout << "你考试考了多少分？(0~100)" << endl;
    cin >> score;

    if (score >= 85) cout << "优" << endl;
    else if (75 <= score < 85) cout << "良" << endl;
    else if (60 <= score < 75) cout << "中" << endl;
    else if (score < 60) cout << "差" << endl;

    return 0;
}