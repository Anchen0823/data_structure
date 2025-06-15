#include <iostream>
#include <vector>
using namespace std;

const int MAXN = 10005;
vector<int> tree[MAXN]; // 邻接表表示树
int depth[MAXN];        // 节点深度
int parent[MAXN];       // 节点的父节点
bool hasParent[MAXN];   // 标记节点是否有父节点

// DFS计算每个节点的深度和父节点
void dfs(int node, int par, int dep) {
    parent[node] = par;
    depth[node] = dep;
    
    for (int child : tree[node]) {
        if (child != par) { // 避免回溯到父节点
            dfs(child, node, dep + 1);
        }
    }
}

// 找到两个节点的最近公共祖先
int findLCA(int u, int v) {
    // 让深度较大的节点先向上跳
    if (depth[u] < depth[v]) {
        swap(u, v);
    }
    
    // 调整至相同深度
    while (depth[u] > depth[v]) {
        u = parent[u];
    }
    
    // 如果此时u==v，说明v是u的祖先
    if (u == v) {
        return u;
    }
    
    // 同时向上跳，直到找到公共祖先
    while (u != v) {
        u = parent[u];
        v = parent[v];
    }
    
    return u;
}

int main() {
    freopen("in.txt", "r", stdin);
    int n;
    cin >> n;
    
    // 初始化hasParent数组
    for (int i = 1; i <= n; i++) {
        hasParent[i] = false;
    }
    
    // 读取树的边
    for (int i = 0; i < n - 1; i++) {
        int parent_node, child_node;
        cin >> parent_node >> child_node;
        
        // 建立双向连接
        tree[parent_node].push_back(child_node);
        tree[child_node].push_back(parent_node);
        
        // 标记child_node有父节点
        hasParent[child_node] = true;
    }
    
    // 找出根节点
    int root = 1;
    for (int i = 1; i <= n; i++) {
        if (!hasParent[i]) {
            root = i;
            break;
        }
    }
    
    // 执行DFS，计算每个节点的深度和父节点
    dfs(root, -1, 0);
    
    // 读取需要查询LCA的两个节点
    int u, v;
    cin >> u >> v;
    
    // 计算并输出LCA
    int lca = findLCA(u, v);
    cout << lca << endl;
    
    return 0;
}