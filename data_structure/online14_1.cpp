#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <map>
#include <fstream>
#include <iomanip>
using namespace std;

int main() {
    freopen("in.txt", "r", stdin);
    string tree;
    int n = 0;

    vector<string> trees;
    map<string, int> countMap;

    while (getline(cin, tree)) {
        
        trees.push_back(tree);
        n++;
        countMap[tree]++;
    }

    for (auto it = countMap.begin(); it != countMap.end(); it++) {
        cout << it->first << " " << fixed << setprecision(4) << (double)it->second / n * 100 << endl;
    }
}