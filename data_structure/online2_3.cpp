#include <iostream>
using namespace std;

int main() {
    int K1, K2, N, num, K1_cnt=0, K2_cnt=0;
    cin >> K1 >> K2;
    if (K1 > K2) {
        cout << false;
        return 0;
    }
    cin >> N;
    for (int i=0;i<N;i++) {
        cin >> num;
        if (num < K1) {
            K1_cnt += 1;
        }
        else if (num >= K2 ) {
            K2_cnt +=1;
        }
    }

    cout << K1_cnt -1;
    cout << " ";
    cout << N - K2_cnt;

    return 0;
}