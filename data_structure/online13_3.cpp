#include <iostream>
#include <vector>
#include <queue>
#include <set>
using namespace std;

// 方向数组：上、右、下、左
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};

struct State {
    int wx, wy;  // 工人位置
    int bx, by;  // 箱子位置
    int pushes;  // 推动次数
    
    State(int _wx, int _wy, int _bx, int _by, int _pushes) 
        : wx(_wx), wy(_wy), bx(_bx), by(_by), pushes(_pushes) {}
    
    // 用于set去重
    bool operator<(const State& other) const {
        if (wx != other.wx) return wx < other.wx;
        if (wy != other.wy) return wy < other.wy;
        if (bx != other.bx) return bx < other.bx;
        return by < other.by;
    }
};

int minPushes(vector<vector<int>>& room, pair<int, int> worker, pair<int, int> box, pair<int, int> target) {
    int n = room.size();
    int m = room[0].size();
    
    // BFS队列
    queue<State> q;
    // 访问过的状态
    set<pair<pair<int, int>, pair<int, int>>> visited;
    
    // 初始状态
    State start(worker.first, worker.second, box.first, box.second, 0);
    q.push(start);
    visited.insert({{worker.first, worker.second}, {box.first, box.second}});
    
    auto isValid = [&](int x, int y) {
        return x >= 0 && x < n && y >= 0 && y < m && room[x][y] != 1;
    };
    
    while (!q.empty()) {
        State curr = q.front();
        q.pop();
        
        // 检查是否到达目标
        if (curr.bx == target.first && curr.by == target.second) {
            return curr.pushes;
        }
        
        // 工人可以尝试四个方向移动
        for (int dir = 0; dir < 4; dir++) {
            int nwx = curr.wx + dx[dir];
            int nwy = curr.wy + dy[dir];
            
            // 检查工人新位置是否有效
            if (!isValid(nwx, nwy)) continue;
            
            // 如果工人新位置是箱子位置，则推动箱子
            if (nwx == curr.bx && nwy == curr.by) {
                int nbx = curr.bx + dx[dir];
                int nby = curr.by + dy[dir];
                
                // 检查箱子新位置是否有效
                if (!isValid(nbx, nby)) continue;
                
                // 检查是否访问过该状态
                if (visited.find({{nwx, nwy}, {nbx, nby}}) == visited.end()) {
                    visited.insert({{nwx, nwy}, {nbx, nby}});
                    q.push(State(nwx, nwy, nbx, nby, curr.pushes + 1));
                }
            } 
            // 工人移动到空地
            else {
                // 检查是否访问过该状态
                if (visited.find({{nwx, nwy}, {curr.bx, curr.by}}) == visited.end()) {
                    visited.insert({{nwx, nwy}, {curr.bx, curr.by}});
                    q.push(State(nwx, nwy, curr.bx, curr.by, curr.pushes));
                }
            }
        }
    }
    
    // 无法到达目标
    return -1;
}

int main() {
    freopen("in.txt", "r", stdin);
    int n, m;
    cin >> n >> m;
    
    vector<vector<int>> room(n, vector<int>(m));
    pair<int, int> worker, box, target;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> room[i][j];
            if (room[i][j] == 2) {
                box = {i, j};
                room[i][j] = 0;  // 将箱子位置标记为空地
            } else if (room[i][j] == 3) {
                target = {i, j};
                room[i][j] = 0;  // 将目标位置标记为空地
            } else if (room[i][j] == 4) {
                worker = {i, j};
                room[i][j] = 0;  // 将工人位置标记为空地
            }
        }
    }
    
    int result = minPushes(room, worker, box, target);
    cout << result << endl;
    
    return 0;
}