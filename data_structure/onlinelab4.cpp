#include <iostream>
#include <vector>
#include <string>

using namespace std;

// 检查子串 s[l...r] 是否是连续非递减的
bool isConsecutiveNonDecreasing(const string &s, int l, int r) {
    for (int i = l + 1; i <= r; ++i) {
        // 当前字符必须等于前一个字符或者比前一个字符大1
        if (s[i] != s[i-1] && s[i] != s[i-1] + 1) {
            return false;
        }
    }
    return true;
}

// 计算给定字符串中好串的数量
int countGoodSubstrings(const string &s) {
    int n = s.size();
    if (n == 0) return 0; // 空字符串没有子串
    
    // dp[i][j] 表示子串 s[i...j] 是否是好串
    vector<vector<bool>> dp(n, vector<bool>(n, false));
    int count = 0; // 记录好串的数量
    
    // 所有单字符子串都是好串
    for (int i = 0; i < n; ++i) {
        dp[i][i] = true;
        count++;
    }
    
    // 检查长度大于1的子串
    for (int len = 2; len <= n; ++len) {
        for (int i = 0; i <= n - len; ++i) {
            int j = i + len - 1; // 子串的结束位置
            
            if (len == 2) {
                // 长度为2的子串默认是好串
                dp[i][j] = true;
            } else {
                bool found = false;
                // 尝试所有可能的拆分点k
                for (int k = i; k < j; ++k) {
                    // 检查拆分后的两部分是否都是好串
                    if (dp[i][k] && dp[k+1][j]) {
                        // 检查左部分是否为连续非递减或单字符
                        bool leftValid = (k == i) || isConsecutiveNonDecreasing(s, i, k);
                        // 检查右部分是否为连续非递减或单字符
                        bool rightValid = (k+1 == j) || isConsecutiveNonDecreasing(s, k+1, j);
                        if (leftValid && rightValid) {
                            found = true;
                            break;
                        }
                    }
                }
                dp[i][j] = found;
            }
            
            if (dp[i][j]) {
                count++;
            }
        }
    }
    
    return count;
}

int main() {
    string s;
    cin >> s; // 读取输入字符串
    cout << countGoodSubstrings(s) << endl; // 输出好串的数量
    return 0;
}