#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int m, n;
    cin >> m >> n;

    vector<int> numbers(m);
    for (int i =0;i<m;i++) {
        cin >> numbers[i];
    }

    sort(numbers.begin(), numbers.end());
    int s=0;
    for (int i=0;i<n;i++) {
        s += numbers[i];
    }
    cout << s;
}