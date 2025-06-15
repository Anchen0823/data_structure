#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;

    int Min = 999999;
    int ans=0;
    int num;
    for (int i=0;i<N;i++) {
        cin >> num;
        if (num <= Min) {
            Min = num;
            ans = i+1;
        }
    }

    cout << ans;

}