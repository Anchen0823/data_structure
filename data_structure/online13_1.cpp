#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <climits>
#include <utility> // for pair

using namespace std;

class DirectedWeightedGraph {
private:
    int numVertices;
    // 邻接表：每个顶点对应一个链表，存储目标顶点和权重
    vector<list<pair<int, int>>> adjList;

public:
    // 构造函数，初始化顶点数量
    DirectedWeightedGraph(int vertices) : numVertices(vertices) {
        adjList.resize(numVertices + 1);  //顶点从1开始
    }

    // 添加有向边
    void addEdge(int src, int dest, int weight) {
        adjList[src].emplace_back(dest, weight);
    }

    // 打印图
    void printGraph() {
        for (int i = 1; i <= numVertices; ++i) {
            cout << "Vertex " << i << " -> ";
            for (const auto& neighbor : adjList[i]) {
                cout << "(" << neighbor.first << ", " << neighbor.second << ") ";
            }
            cout << endl;
        }
    }

    // 获取顶点数量
    int getNumVertices() const {
        return numVertices;
    }

    // 获取某个顶点的邻接边
    const list<pair<int, int>>& getAdjacent(int vertex) const {
        return adjList[vertex];
    }

    int findBestBroadcastVertex() {
    int bestVertex = -1;
    int minMaxDist = INT_MAX;
    
    // 对每个顶点运行Dijkstra算法
    for (int src = 1; src <= numVertices; ++src) {
        vector<int> dist(numVertices + 1, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        dist[src] = 0;
        pq.push({0, src});
        
        while (!pq.empty()) {
            int currentDist = pq.top().first;
            int currentVertex = pq.top().second;
            pq.pop();
            
            if (currentDist > dist[currentVertex]) {
                continue;
            }
            
            for (const auto& neighbor : adjList[currentVertex]) {
                int neighborVertex = neighbor.first;
                int edgeWeight = neighbor.second;
                int newDist = currentDist + edgeWeight;
                
                if (newDist < dist[neighborVertex]) {
                    dist[neighborVertex] = newDist;
                    pq.push({newDist, neighborVertex});
                }
            }
        }
        
        // 找出当前顶点的最大传播距离
        int currentMaxDist = 0;
        for (int i = 1; i <= numVertices; ++i) {
            if (dist[i] == INT_MAX) {
                // 图不连通，无法广播到所有顶点
                currentMaxDist = INT_MAX;
                break;
            }
            if (dist[i] > currentMaxDist) {
                currentMaxDist = dist[i];
            }
        }
        
        // 更新最佳广播顶点
        if (currentMaxDist < minMaxDist) {
            minMaxDist = currentMaxDist;
            bestVertex = src;
        }
    }
    
    if (bestVertex == -1) {
        cout << "disjoint" << endl;
    } else {
        cout << bestVertex << " " << minMaxDist << endl;
    }
    
    return bestVertex;
}
};

int main() {
    freopen("in.txt", "r", stdin);

    int n; cin >> n;
    DirectedWeightedGraph graph(n);

    for (int i=1;i<=n;i++) {
        int m;
        cin >> m;

        for (int j=0;j<m;j++) {
            int contact, time;
            cin >> contact >> time;
            graph.addEdge(i, contact, time);
        }
    }

    graph.findBestBroadcastVertex();
}
