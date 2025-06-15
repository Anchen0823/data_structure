#include <iostream>
#include <vector>
#include <stack>
using namespace std;

long long maximumTripletValue(vector<int>& nums) {
    long long result = 0;
    long long temp;
    int len = nums.size();
    for (int i=0;i<len-2;i++) {
        long n1 = nums[i];
        for (int j=i;j<len-1;j++) {
            long n2 = nums[j];
            for (int k=j;k<len;k++) {
                long n3 = nums[k];
                temp = (n1 - n2) * n3;
                if (temp > result) {
                    result = temp;
                }
            }
        }
    }
    return result;
}

int main() {
    vector<int> nums = {10, 13, 6, 2};
    cout << maximumTripletValue(nums);
}