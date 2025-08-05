#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    if (n < 9) {
        cout << 0 << endl;
        return 0;
    }
    
    int match[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
    vector<int> nums(4001, 0);
    
    nums[0] = 6;
    for (int i = 1; i <= 4000; i++) {
        int x = i;
        int sum = 0;
        while (x) {
            sum += match[x % 10];
            x /= 10;
        }
        nums[i] = sum;
    }
    
    int total = 0;
    for (int A = 0; A <= 2000; A++) {
        for (int B = 0; B <= 2000; B++) {
            int C = A + B;
            if (C > 4000) continue;
            if (nums[A] + nums[B] + nums[C] + 4 == n) {
                total++;
            }
        }
    }
    
    cout << total << endl;
    return 0;
}