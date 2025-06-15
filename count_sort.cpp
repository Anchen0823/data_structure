#include <iostream>
#include <vector>
#include <climits>
using namespace std;

void countSort(vector<int>& nums) {
    int MIN = INT_MAX;
    int MAX = INT_MIN;
    int n = nums.size();
    int* sorted_nums = new int[n];

    for (int i = 0; i < n; i++) {
        MIN = min(MIN, nums[i]);
        MAX = max(MAX, nums[i]);
    }

    int k = MAX - MIN + 1;
    int* count = new int[k]();
    
    for (int i = 0; i < n; i++) {
        count[nums[i] - MIN]++;
    }

    for (int i = 1; i < k; i++) {
        count[i] += count[i - 1];
    }

    for (int i = n - 1; i >= 0; i--) {
        sorted_nums[--count[nums[i] - MIN]] = nums[i];
    }

    // 把排序结果写回原数组
    for (int i = 0; i < n; i++) {
        nums[i] = sorted_nums[i];
    }

    delete[] sorted_nums;
    delete[] count;
}

int main() {
    vector<int> nums = {1, 2, 5, 7, 9, 2, 3, 6};
    countSort(nums);
    for (int num : nums) {
        cout << num << " ";
    }
    return 0;
}