#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const int MAXV = 1005;

struct ArcNode
{
    int adjVex;
    int weight;
    ArcNode* nextArc;
};

struct HeadNode
{
    string info;
    ArcNode* firstArc;
};

class AdjGraph
{
public:
    HeadNode adjList[MAXV]; // 头结点值
    int n, e;   // 边数、顶点数

    AdjGraph() : n(0), e(0) {
        for (int i=0;i<MAXV;i++) {
            adjList[i].firstArc = nullptr;
        }
    }

    // u->v的有向边
    void addEdge(int u, int v, int w=1) {
        ArcNode* newArc = new ArcNode;
        newArc->adjVex = v;
        newArc->weight = w;
        newArc->nextArc = adjList[u].firstArc;
        adjList[u].firstArc = newArc;
        e++;
    }

    void printAdjGraph() {
        ArcNode* curr;
        for (int i=0;i<n;i++) {
            cout << i;
            curr = adjList[i].firstArc;
            if (curr != nullptr) {
                cout << "->";
            }
            while (curr != nullptr) {
                cout << curr->adjVex << " " << curr->weight;
                curr = curr->nextArc;
            }
            cout << endl;
        }
    }

    vector<int> topoSort() {
        vector<int> result;
        vector<int> indegree(n, 0);

        // 计算每个顶点的入度
        for (int i=0; i<n; i++) {
            ArcNode* curr = adjList[i].firstArc;
            while (curr != nullptr) {
                indegree[curr->adjVex]++;
                curr = curr->nextArc;
            }
        }

        // 入度为0顶点入队
        queue<int> q;
        for (int i=0;i<n;i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        // 处理队列
        while (!q.empty()) {
            int u = q.front(); q.pop();
            result.push_back(u);

            ArcNode* curr = adjList[u].firstArc;
            while (curr != nullptr) {
                int v = curr->adjVex;
                indegree[v]--;

                // 邻接点入度变为0
                if (indegree[v] == 0) {
                    q.push(v);
                }

                curr = curr->nextArc;
            }
        }

        // 判断环
        if (result.size() != n) {
            cout << "Yes";
        } else {
            cout << "No";
        }
        return result;
    }
};

int main() {
    int N, M;
    cin >> N >> M;
    AdjGraph G;
    G.n = N;

    for (int i=0;i<M;i++) {
        int u, v;
        cin >> u >> v;

        G.addEdge(u-1, v-1);
    }

    G.topoSort();
    return 0;
}