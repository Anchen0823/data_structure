#include <iostream>
int occ_num(int a[], int x, int len);

int main() {
    int arr[] = {1, 2, 3, 4, 2, 2, 5, 2, 6};
    int x = 2;
    int len = sizeof(arr) / sizeof(arr[0]);

    int count = occ_num(arr, x, len);

    std::cout << "整数 " << x << " 在数组中出现的次数为: " << count << std::endl;

    return 0;
}

int occ_num(int a[], int x, int len) {
    int count = 0;
    for (int i = 0; i < len; ++i) {
        if (a[i] == x) {
            ++count;
        }
    }
    return count;
}