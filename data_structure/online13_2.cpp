#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

const int INF = INT_MAX / 2;
const int MAXN = 105;

int n, m;
int graph[MAXN][MAXN];  // 存储直接边的成本
int minCost = INF;
bool visited[MAXN];
vector<int> path;

// DFS寻找从起点start到当前点u的简单环
void dfs(int u, int start, int cost) {
    // 如果回到起点且路径长度大于2（至少经过2个其他顶点）
    if (u == start && path.size() > 2) {
        minCost = min(minCost, cost);
        return;
    }
    
    // 如果已经访问过或者路径过长，剪枝
    if (visited[u] && u != start) return;
    
    visited[u] = true;
    path.push_back(u);
    
    for (int v = 1; v <= n; v++) {
        if (graph[u][v] != INF) {
            // 如果是起点，只有在形成有效环时才考虑
            if (v == start) {
                if (path.size() > 2) {
                    dfs(v, start, cost + graph[u][v]);
                }
            }
            // 对于其他点，如果未访问过则继续搜索
            else if (!visited[v]) {
                dfs(v, start, cost + graph[u][v]);
            }
        }
    }
    
    // 回溯
    visited[u] = false;
    path.pop_back();
}

int main() {
    freopen("in.txt", "r", stdin);
    cin >> n >> m;
    
    // 初始化邻接矩阵
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            graph[i][j] = INF;
        }
    }
    
    // 读取边信息
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a][b] = min(graph[a][b], c);
        graph[b][a] = min(graph[b][a], c); // 双向路
    }
    
    // 枚举所有可能的起点
    for (int i = 1; i <= n; i++) {
        fill(visited, visited + MAXN, false);
        path.clear();
        dfs(i, i, 0);
    }
    
    if (minCost == INF) {
        cout << "It's impossible." << endl;
    } else {
        cout << minCost << endl;
    }
    
    return 0;
}