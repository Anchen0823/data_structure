#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n; cin >> n;
    vector<int> nums(n+1);
    for (int i=1;i<=n;i++) {
        cin >> nums[i];
    }

    for (int i=1;i*2<=n;i++) {
        if (nums[i] >= nums[2*i] && nums[i] >= nums[2*i+1]) {
            continue;
        } else {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
    return 0;
}