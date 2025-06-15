#include <iostream>
#include <fstream>
using namespace std;

int main() {
    freopen("in.txt", "r", stdin);

    int m, n, x, y;
    cin >> m >> n >> x >> y;

    int* data = new int[m*n];
    for (int i=0;i<m;i++) {
        for (int j=0;j<n;j++) {
            int num;
            cin >> num;
            data[i*n + j] = num;
        }
    }

    //遍历
    int result = 0;
    for (int i=0;i<=m-x;i++) {
        for (int j=0;j<=n-y;j++) {
            //取子矩阵
            int s = 0;
            for (int p=i;p<i+x;p++) {
                for (int q=j;q<j+y;q++) {
                    s += data[p*n + q];
                }
            }
            if (s > result) {result = s;}
        }
    }

    cout << result;
}