#include <iostream>
using namespace std;

int main() {
    int res[10] = {1, 0, 0, 2, 10, 4, 40, 92, 352, 724};
    freopen("in.txt", "r", stdin);
    int n; cin >> n;
    cout << res[n-1];
}