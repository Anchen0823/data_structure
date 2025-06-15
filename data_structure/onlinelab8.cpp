#include <iostream>
#include <list>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#include <sstream>
#include <fstream>
#include <utility>
using namespace std;

class HashTable {
private:
    int size;
    vector<list<pair<string, int>>> table;

    int hashFunc(string& word) {
        int hash = 0;
        for (char c : word) {
            hash = (hash * 31 + c) % size;
        }
        return hash;
    }

public:
    HashTable(int tableSize) : size(tableSize) {
        table.resize(size);
    }

    void insert(string& word) {
        int index = hashFunc(word);
        table[index].push_back({word, 1});
    }

    string search(string& word) {
        int index = hashFunc(word);
        for (auto& p : table[index]) {
            if (p.first == word) {
                return p.first;
            }
        }
        return "NOT FOUND";
    }

    bool in(string& word) {
        int index = hashFunc(word);
        for (auto& p : table[index]) {
            if (p.first == word) {
                return true;
            }
        }
        return false;
    }

    void add(string& word) {
        int index = hashFunc(word);
        for (auto& p : table[index]) {
            if (p.first == word) {
                p.second++;
                return;
            }
        }
        table[index].push_back({word, 1});
    }

    // 删除键值对
    void remove(string& word) {
        int index = hashFunc(word);
        for (auto it = table[index].begin(); it != table[index].end(); it++) {
            if (it->first == word) {
                table[index].erase(it);
                return;
            }
        }
    }

    vector<pair<string, int>> getAllWords() {
        vector<pair<string, int>> words;
        for (int i = 0; i < size; i++) {
            for (const auto& p : table[i]) {
                words.push_back(p);
            }
        }
        return words;
    }

    // 堆排序
    vector<pair<string, int>> getTopKWords(int k) {
        auto cmp = [](const pair<string, int>& a, const pair<string, int>& b) {
            if (a.second != b.second) {
                return a.second > b.second;
            }
            return a.first < b.first;
        };
    
        priority_queue<pair<string, int>, vector<pair<string, int>>, decltype(cmp)> minHeap(cmp);
    
        for (int i = 0; i < size; i++) {
            for (const auto& p : table[i]) {
                minHeap.push(p);
                if (minHeap.size() > k) {
                    minHeap.pop();
                }
            }
        }
    
        // 将结果转换为vector
        vector<pair<string, int>> result;
        while (!minHeap.empty()) {
            result.push_back(minHeap.top());
            minHeap.pop();
        }
        
        reverse(result.begin(), result.end());
        return result;
    }
};

bool readFromFile(const string& filename, string& content) {
    ifstream file(filename);
    if (!file.is_open()) {
        return false;
    }
    
    string line;
    while (getline(file, line)) {
        content += line + " ";
    }
    file.close();
    return true;
}

bool writeToFile(const string& filename, const vector<pair<string, int>>& words) {
    ofstream file(filename);
    if (!file.is_open()) {
        return false;
    }
    
    for (const auto& word : words) {
        file << word.first << " " << word.second << endl;
    }
    file.close();
    return true;
}

int main() {
    HashTable h(100);
    
    // 从文件读取数据
    string content;
    freopen("in.txt", "r", stdin);
    getline(cin, content);
    
    // 处理输入文本
    stringstream ss(content);
    string word;
    
    while (ss >> word) {
        if (!word.empty()) {
            h.add(word);
        }
    }

    int k; cin >> k;
    vector<pair<string, int>> topKWords = h.getTopKWords(k);
    for (const auto& word : topKWords) {
        cout << word.first << ": " << word.second << endl;
    }

    // 输出结果到文件
    writeToFile("out.txt", topKWords);
    return 0;
}