#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

int main() {
    freopen("in.txt", "r", stdin); // 从文件读取输入

    int t;
    cin >> t;

    unordered_map<int, int> member_to_team;

    for (int i = 0; i < t; ++i) {
        int n;
        cin >> n;
        for (int j = 0; j < n; ++j) {
            int p;
            cin >> p;
            member_to_team[p] = i;
        }
    }

    vector<queue<int>> team_queues(t);
    queue<int> main_queue;

    string cmd;
    while (cin >> cmd) {
        if (cmd == "STOP") {
            break;
        } else if (cmd == "ENQUEUE") {
            int p;
            cin >> p;
            int tid = member_to_team[p];
            team_queues[tid].push(p);
            if (team_queues[tid].size() == 1) {
                main_queue.push(tid);
            }
        } else if (cmd == "DEQUEUE") {
            int tid = main_queue.front();
            int p = team_queues[tid].front();
            team_queues[tid].pop();
            cout << p << endl;
            if (team_queues[tid].empty()) {
                main_queue.pop();
            }
        }
    }

    return 0;
}