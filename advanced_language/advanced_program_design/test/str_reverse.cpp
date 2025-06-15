#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    string line;
    getline(cin, line);
    reverse(line.begin(), line.end());
    cout << line;
}