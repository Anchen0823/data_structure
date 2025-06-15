#include <iostream>
#include <vector>
#include <set>
#include <fstream>
using namespace std;

int findParent(vector<int>& parent, int x) {
    if (parent[x] != x) {
        parent[x] = findParent(parent, parent[x]);  // 路径压缩
    }
    return parent[x];
}

void unionSets(vector<int>& parent, int x, int y) {
    parent[findParent(parent, x)] = findParent(parent, y);
}

int minRoadsNeeded(int n, vector<pair<int, int>>& roads) {
    // 初始化并查集
    vector<int> parent(n + 1);
    for (int i = 1; i <= n; i++) {
        parent[i] = i;
    }
    
    // 合并所有已有道路连通的城镇
    for (auto& road : roads) {
        unionSets(parent, road.first, road.second);
    }
    
    // 计算连通分量数量
    set<int> components;
    for (int i = 1; i <= n; i++) {
        components.insert(findParent(parent, i));
    }
    
    // 连接所有分量所需的道路数量
    return components.size() - 1;
}

int main() {
    freopen("in.txt", "r", stdin);
    int n, m;
    cin >> n >> m;
    
    vector<pair<int, int>> roads;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        roads.push_back({a, b});
    }
    
    cout << minRoadsNeeded(n, roads) << endl;
    return 0;
}