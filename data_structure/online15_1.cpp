#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

int main() {
    freopen("in.txt", "r", stdin);
    int n, m;
    cin >> n >> m;

    vector<int> nums(n);
    for (int i=0;i<n;i++) {
        cin >> nums[i];
    }

    int sum;
    vector<int> h(10000);
    for (int i=0;i<n;i++) {
        for (int j=i+1;j<n;j++) {
            sum = nums[i] + nums[j];
            h[sum]++;
        }
    }

    int count = 0;
    for (int i = h.size() - 1; i >= 0 && count < m; --i) {
        while (h[i] != 0) { 
            cout << i << " ";
            count++;
            h[i]--;
        }
    }
    cout << endl;

    return 0;
}