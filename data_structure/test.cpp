#include <iostream>
#include <vector>
#include <climits>
using namespace std;

    void shiftDown(vector<int>& nums, int low, int high) {
        int i = low;
        int j = 2*i+1;
        int temp = nums[i];

        while (j<=high) {
            if (j<high && nums[j] < nums[j+1]) {
                j++;
            }
            if (temp < nums[j]) {
                i = j; j = 2*i+1;
            } else {
                break;
            }
        }
        nums[i] = temp;
    }

    void k_HeapSort(vector<int>& nums, int n, int k) {
        int last;
        if (n%2 == 0) {
            last = n/2-1;
        } else {
            last = n/2;
        }
        for (int i=last;i>=0;i--) {
            shiftDown(nums, i, n-1);
        }
        for (int i=1;i<=k;i++) {
            swap(nums[0], nums[n-i]);
            shiftDown(nums, 0, n-i-1);
        }
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int Min = INT_MAX;
        int Max = -1;
        for (int num : nums) {
            Min = min(num, Min);
            Max = max(num, Max);
        }
        int len = Max-Min+1;

        vector<int> h(len);
        for (int num : nums) {
            h[num]++;
        }

        k_HeapSort(h, len, k);
        vector<int> result;
        for (int i=len-k;i<=len-1;i++) {
            result.push_back(h[i]);
        }
        return result;
    }

int main() {
    vector<int> nums = {1, 1, 2, 1, 2, 3};
    vector<int> result = topKFrequent(nums, 3);
    for (int num : result) {
        cout << num << " ";
    }
}