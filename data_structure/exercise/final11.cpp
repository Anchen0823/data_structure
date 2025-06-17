#include <iostream>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    int* nums = new int[n];
    for (int i=0;i<n;i++) {
        cin >> nums[i];
    }

    int l = 0, r = n-1;
    int cnt = 0;
    while (l<r) {
        int mid = (l+r)/2;
        if (nums[mid] < k) {
            l = mid + 1;
            cnt++;
        } else {
            r = mid;
            cnt++;
        }
    }
    cout << cnt;
}