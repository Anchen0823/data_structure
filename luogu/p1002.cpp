#include <iostream>
#include <vector>
using namespace std;

bool isValid(int n, int m, int a, int b, int x, int y) {    //a,b为马; x,y为目标
    if (x  < 0 || y < 0) return false;
    if (x > n || y > m) return false;
    if (x == (a-2) && y == (b-1)) return false; //p5
    if (x == (a-1) && y == (b-2)) return false; //p6
    if (x == (a+1) && y == (b-2)) return false; //p7
    if (x == (a+2) && y == (b-1)) return false; //p8
    if (x == (a+2) && y == (b+1)) return false; //p1
    if (x == (a+1) && y == (b+2)) return false; //p2
    if (x == (a-1) && y == (b+2)) return false; //p3
    if (x == (a-2) && y == (b+1)) return false; //p4
    if (x == a && y == b) return false;

    return true;
}

int main() {
    int n, m, a, b;
    cin >> n >> m >> a >> b;

    vector<vector<long>> dp(n+1, vector<long>(m+1, 0));

    if (isValid(n,m,a,b,0,0)) dp[0][0] = 1; //原点合法

    for (int i=0;i<=n;i++) {
        for (int j=0;j<=m;j++) {
            if (isValid(n,m,a,b,i,j)) {
                if (isValid(n,m,a,b,i-1,j)) {   //上方
                    dp[i][j] += dp[i-1][j];
                }
                if (isValid(n,m,a,b,i,j-1)) {   //左方
                    dp[i][j] += dp[i][j-1];
                }
            }
        }
    }

    cout << dp[n][m];
}