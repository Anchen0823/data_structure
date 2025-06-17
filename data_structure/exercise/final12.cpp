#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int* nums = new int[n];
    int* result = new int[n];
    for (int i=0;i<n;i++) {
        cin >> nums[i];
    }

    int k;
    cin >> k;

    bool found = false;
    int l = 0, r = n-1;
    int cnt = -1;
    while (l<=r) {
        int mid = l + (r-l)/2;
        result[++cnt] = nums[mid];
        if (nums[mid] < k) {
            l = mid + 1;
        } else if (nums[mid] > k) {
            r = mid - 1;
        } else if (nums[mid] == k) {
            found = true;
            break;
        }
        
    }

    if (!found) {
        cout << "Not Found";
        return 0;
    }
    for (int i=0;i<=cnt;i++) {
        cout << result[i] << " ";
    }
}