#include <iostream>
#include <vector>
#include <utility>
#include <fstream>
using namespace std;

int partition(vector<pair<int,int>>& R, int start, int end) {
    pair<int, int> base = R[start]; // 使用pair作为基准
    int i = start, j = end;
    while (i < j) {
        while (i < j && 
               (R[j].first > base.first || 
                (R[j].first == base.first && R[j].second >= base.second))) {
            j--;
        }
        while (i < j && 
               (R[i].first < base.first || 
                (R[i].first == base.first && R[i].second <= base.second))) {
            i++;
        }
        if (i < j) {
            swap(R[i], R[j]);
        }
    }
    swap(R[start], R[i]);
    return i;
}

void _QuickSort(vector<pair<int, int>>& R, int start, int end) {
    if (start < end) {
        int i = partition(R, start, end);
        _QuickSort(R, start, i-1);
        _QuickSort(R, i+1, end);
    }
}

void QuickSort(vector<pair<int, int>>& R, int n) {
    _QuickSort(R, 0, n-1);
}

int longestDecreasingLength(vector<pair<int, int>>& R) {
    int n = R.size();
    vector<int> dp(n, 1);

    for (int i=1;i<n;i++) {
        for (int j = 0;j<i;j++) {
            if (R[i].second < R[j].second) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    int m = 0;
    for (int num : dp) {
        m = num > m ? num : m;
    }
    return m;
}

int main() {
    freopen("in.txt", "r", stdin);
    int n; cin >> n;
    vector<pair<int, int>> sticks;
    int l, w;
    for (int i = 0;i < n;i++) {
        cin >> l >> w;
        pair<int, int> p(l, w);
        sticks.push_back(p);
    }

    QuickSort(sticks, n);

    int res = longestDecreasingLength(sticks);
    cout << res << endl;
}