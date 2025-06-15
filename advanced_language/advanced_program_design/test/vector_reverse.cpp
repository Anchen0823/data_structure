#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    bool flag=false;
    vector<int> numbers(n);
    for (int i=0;i<n;i++) {
        cin >> numbers[i];
    }
    for (int i=0;i<n;i++) {
        if (numbers[i]==m) {
            cout << i;
            flag=true;
            break;
        }
    }
    if (flag == false) cout << -1;
}