#include <vector>
#include <iostream>
#include <fstream>
using namespace std;

class Solution {
public:
    vector<vector<int>> generateresult(int n) {
        vector<vector<int>> result(n, vector<int>(n, 0));
        fillSpiral(result, 1, 0, n);
        return result;
    }
    
private:
    void fillSpiral(vector<vector<int>>& result, int value, int start, int size) {
        if (size <= 0) return;
        
        if (size == 1) {
            result[start][start] = value;
            return;
        }
        
        // 填充上边
        for (int i = 0; i < size - 1; i++) {
            result[start][start + i] = value++;
        }
        
        // 填充右边
        for (int i = 0; i < size - 1; i++) {
            result[start + i][start + size - 1] = value++;
        }
        
        // 填充下边
        for (int i = 0; i < size - 1; i++) {
            result[start + size - 1][start + size - 1 - i] = value++;
        }
        
        // 填充左边
        for (int i = 0; i < size - 1; i++) {
            result[start + size - 1 - i][start] = value++;
        }
        
        // 递归填充内层螺旋
        fillSpiral(result, value, start + 1, size - 2);
    }
};

int main() {
    freopen("in.txt", "r", stdin);
    int n;
    cin >> n;
    Solution s;
    vector<vector<int>> result = s.generateresult(n);

    std::cout << "[\n";  // 开头

    for (size_t i = 0; i < result.size(); i++) {
        std::cout << "[";  // 每行开头

        for (size_t j = 0; j < result[i].size(); j++) {
            std::cout << result[i][j];
            if (j != result[i].size() - 1) {
                std::cout << ",";  // 元素间加逗号
            }
        }

        std::cout << "]";  // 行尾
        if (i != result.size() - 1) {
            std::cout << ", ";  // 如果不是最后一行，加逗号
        }
        std::cout << "\n";  // 换行
    }

    std::cout << "]\n";  // 结尾

    return 0;

}