#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAXV = 1005;

struct ArcNode {
    int adjVex;
    int weight;
    ArcNode* nextArc;
};

struct HeadNode {
    string info;
    ArcNode* fisrtArc;
};

class AdjGraph {
public:
    HeadNode adjList[MAXV];
    int n, e;

    AdjGraph() : n(0), e(0) {
        for (int i=0;i<MAXV;i++) {
            adjList[i].fisrtArc = nullptr;
        }
    }

    void addEdge(int u, int v, int w=1) {
        ArcNode* newArc = new ArcNode;
        newArc->adjVex = v;
        newArc->weight = w;
        newArc->nextArc = adjList[u].fisrtArc;
        adjList[u].fisrtArc = newArc;
    }
};

class Solution {
public:
    vector<int> dist;   // dist[v]表示到v的最短路径
    vector<int> dp;     // dp[v]表示到v的最短路径数
    AdjGraph& graph;

    Solution(AdjGraph& g) : graph(g) {
        dist.resize(MAXV, -1);
        dp.resize(MAXV, 0);
    }

    // bfs
    void countPaths(int start) {
        dist.resize(MAXV, -1);
        dp.resize(MAXV, 0);
        queue<int> q;
        dist[start] = 0;
        dp[start] = 1;
        q.push(start);

        while (!q.empty()) {
            int u = q.front(); q.pop();

            ArcNode* curr = graph.adjList[u].fisrtArc;
            while (curr) {
                int v = curr->adjVex;

                if (dist[v] == -1) {    // 未被访问
                    dist[v] = dist[u] + 1;
                    dp[v] = dp[u];
                    q.push(v);
                } else if (dist[v] == dist[u] + 1) {    // 已被访问且当前为另一条最短路径
                    dp[v] += dp[u];
                }

                curr = curr->nextArc;
            }
        }
    }

    int getPaths(int start, int end) {
        countPaths(start);
        return (dist[end] == -1) ? 0 : dp[end];
    }

    vector<int> solve(int N) {
        countPaths(1);
        vector<int> result(N + 1);
        for (int i = 1; i <= N; i++) {
            result[i] = (dist[i] == -1) ? 0 : dp[i];
        }
        return result;
    }
};

int main() {
    AdjGraph graph;

    int n, m;
    cin >> n >> m;
    graph.n = n;
    graph.e = m;

    for (int i=0;i<m;i++) {
        int x, y;
        cin >> x >> y;
        graph.addEdge(x, y);
        graph.addEdge(y, x);
    }

    Solution solution(graph);
    vector<int> result = solution.solve(n);
    for (int i=1;i<=n;i++) {
        cout << result[i] << endl;
    }

    return 0;
}