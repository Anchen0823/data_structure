#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    int num;
    for (int i = 0; i<n; i++) {
        cin >> num;
        a[i] = (num);
    }
    for (int i = 0; i<n; i++) {
        cin >> num;
        b[i] = (num);
    }

    int cnt = 0, i=0, j=0, curr = 0;
    while (cnt < n && i < n && j < n) {
        if (a[i] < b[j]) {
            curr = a[i];
            i++;
            cnt++;
        } else if (a[i] > b[j]) {\
            curr = b[j];
            j++;
            cnt++;
        } else if (a[i] == b[j]) {
            curr = a[i];
            i++;
            j++;
            cnt += 2;
        }
    }
    cout << curr << " ";
    return 0;
}