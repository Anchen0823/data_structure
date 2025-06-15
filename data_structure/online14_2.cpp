#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    freopen("in.txt", "r", stdin);
    int n;
    cin >> n;

    int a, b, c, d;

    vector<int> A, B, C, D;
    for (int i=0;i<n;i++) {
        cin >> a >> b >> c >> d;
        A.push_back(a);
        B.push_back(b);
        C.push_back(c);
        D.push_back(d);
    }

    unordered_map<int, int> sumAB;
    for (int a : A) {
        for (int b : B) {
            sumAB[a+b]++;
        }
    }

    int cnt = 0;
    for (int c : C) {
        for (int d : D) {
            int target = -(c+d);
            if (sumAB.count(target)) {
                cnt += sumAB[target];
            }
        }
    }
    cout << cnt;
    return 0;
}