#include <iostream>
#include <vector>
using namespace std;

void shiftDown(vector<int>& R, int low, int high) {
    int i = low;
    int j = 2*i+1;  // R[j]为R[i]左孩子
    int temp = R[i];

    while (j<=high) {
        if (j < high && R[j] < R[j+1]) {
            j++;    // 若右孩子较大把j指向右孩子
        }
        if (temp < R[j]) {
            R[i] = R[j];
            i = j; j = 2*i+1;   // 筛选原R[j]的子树
        } else {    // 孩子较小
            break;
        }
    }
    R[i] = temp;    // 把原R[i](temp)放入最终位置，即现在i所指处
}

void k_HeapSort(vector<int>& R, int n, int k) {
    int last;
    if (n%2 == 0) {
        last = n/2-1;
    } else {
        last = n/2;
    }

    for (int i=last;i>=0;i--) {
        shiftDown(R, i, n-1);
    }
    for (int i=1;i<=k;i++) { // k趟排序，选出前k最值
        swap(R[0], R[n-i]);
        shiftDown(R, 0, n-i-1);
    }
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> nums(n);
    for (int i=0;i<n;i++) {
        cin >> nums[i];
    }

    k_HeapSort(nums, n, k);
    for (int i = n-k;i<=n-1;i++) {
        cout << nums[i] << " ";
    }
}