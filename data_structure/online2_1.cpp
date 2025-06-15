#include <iostream>
#include <set>
#include <sstream>
#include <string>
using namespace std;

int main() {
    freopen("in.txt", "r", stdin); // 从in.txt读取输入数据

    int n, m;
    cin >> n >> m;
    cin.ignore(); // 忽略第一行后的换行符

    set<int> combinedSet;

    // 读取并处理集合A的元素
    string lineA;
    getline(cin, lineA);
    istringstream issA(lineA);
    for (int i = 0; i < n; ++i) {
        int num;
        issA >> num;
        combinedSet.insert(num);
    }

    // 读取并处理集合B的元素
    string lineB;
    getline(cin, lineB);
    istringstream issB(lineB);
    for (int i = 0; i < m; ++i) {
        int num;
        issB >> num;
        combinedSet.insert(num);
    }

    // 输出合并后的集合
    if (!combinedSet.empty()) {
        auto it = combinedSet.begin();
        cout << *it;
        ++it;
        for (; it != combinedSet.end(); ++it) {
            cout << " " << *it;
        }
    }
    cout << endl;

    return 0;
}