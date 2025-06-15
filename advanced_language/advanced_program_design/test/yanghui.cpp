#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;
void printYanghuiTriangle(int n) {
    const int width = 4;
    vector<vector<int>> triangle(n+1);

    for (int i=0;i<=n;i++) {
        triangle[i].resize(i+1, 1);
        for (int j=1;j<i;j++) {
            triangle[i][j] = triangle[i-1][j-1] + triangle[i-1][j];
        }
    }
    
    for (const auto& row : triangle) {
        for (int i=0;i<=n-int(row.size());i++) {
            cout << "  ";
        }
        for (int num : row) {
            cout << setw(width) << setfill(' ') << num;
        }
        cout << endl;
    }
}
int main() {
    int n;
    cin >> n;
    printYanghuiTriangle(n);
}