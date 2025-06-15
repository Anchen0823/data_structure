#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    int len = log10(n) + 1;
    cout << len << endl;

    cout << n << endl;

    string s = to_string(n);
    reverse(s.begin(), s.end());
    cout << s;
    
}