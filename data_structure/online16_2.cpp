#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

int partion(vector<int>& nums, int begin, int end) {
    int base = nums[begin];
    int i = begin, j = end;
    while (i<j) {
        while (i<j && nums[j] > base) {
            j--;
        }
        while (i<j && nums[i] <= base) {
            i++;
        }
        if (i<j) {
            swap(nums[i], nums[j]);
        }
        
    }
    swap(nums[begin], nums[i]);
    return i;
}

void _QuickSort(vector<int>& nums, int begin, int end) {
    if (begin < end) {
        int index = partion(nums, begin, end);
        _QuickSort(nums, begin, index - 1);
        _QuickSort(nums, index + 1, end);
    }
}

void QuickSort(vector<int>& nums) {
    _QuickSort(nums, 0, nums.size()-1);
}

int main() {
    freopen("in.txt", "r", stdin);
    ofstream file("out.txt");

    vector<int> nums;
    int num;
    while (cin >> num) {
        nums.push_back(num);
    }

    QuickSort(nums);
    for (int num : nums) {
        file << num << " ";
    }
}