#include <iostream>
#include <vector>
using namespace std;

void moveZeroes(vector<int>& nums) {
    int i=0;
    int j=nums.size() - 1;
    while (i != j) {
        if (nums[i] == 0) {
            for (int k=i+1;k<=j;k++) {
                nums[k-1] = nums[k]; 
            }
            nums[j] = 0;
            j--;
            if (j == i) break;

        }
    if (nums[i] != 0) i++;
    }
}

int main() {
    vector<int> nums = {0, 0, 0, 1, 0, 11, 0, 0, 111};
    moveZeroes(nums);
}