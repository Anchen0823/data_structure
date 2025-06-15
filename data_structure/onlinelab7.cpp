#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

// 记录结构体
struct Record {
    int id;
    int score;
    
    Record() : id(0), score(0) {}
    Record(int i, int s) : id(i), score(s) {}
};

class SortSearchSystem {
private:
    vector<Record> records;
    
    // 快速排序的分区函数
    int partition(vector<Record>& arr, int low, int high) {
        int pivot = arr[high].id; // 选择最后一个元素作为基准
        int i = low - 1;
        
        for (int j = low; j < high; j++) {
            if (arr[j].id <= pivot) {
                i++;
                swap(arr[i], arr[j]);
            }
        }
        swap(arr[i + 1], arr[high]);
        return i + 1;
    }
    
    // 快速排序递归函数
    void quickSort(vector<Record>& arr, int low, int high) {
        if (low < high) {
            int pi = partition(arr, low, high);
            quickSort(arr, low, pi - 1);
            quickSort(arr, pi + 1, high);
        }
    }
    
    // 折半查找函数
    int binarySearch(int target) {
        int left = 0, right = records.size() - 1;
        int firstMatchId = -1; // 存储第一个匹配记录的id
        int firstMatchIndex = -1; // 存储第一个匹配记录的索引
        
        // 第一步：找到任意一个score等于target的记录
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            // score降序
            if (records[mid].score == target) {
                firstMatchId = records[mid].id;
                firstMatchIndex = mid;
                break; // 找到一个匹配的记录就跳出
            }
            else if (records[mid].score > target) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }

        left = 0;
        right = records.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            // score升序
            if (records[mid].score == target) {
                firstMatchId = records[mid].id;
                firstMatchIndex = mid;
                break; // 找到一个匹配的记录就跳出
            }
            else if (records[mid].score < target) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        
        // 如果没找到匹配的记录，返回-1
        if (firstMatchIndex == -1) {
            return -1;
        }
        
        // 第二步：从找到的位置向前查找，找到第一个（id最小的）匹配记录
        // 由于数组已经按id排序，所以只需要向前查找即可
        for (int i = firstMatchIndex - 1; i >= 0; i--) {
            if (records[i].score == target) {
                if (records[i].id < firstMatchId) {
                    firstMatchId = records[i].id;
                }
            } else {
                break; // 如果score不匹配就停止查找
            }
        }
        
        return firstMatchId;
    }
    
public:
    // 从文件读取数据
    bool readFromFile(const string& filename) {
        ifstream inFile(filename);
        if (!inFile.is_open()) {
            return false;
        }
        
        int n;
        inFile >> n;
        records.clear();
        records.reserve(n);
        
        for (int i = 0; i < n; i++) {
            int id, score;
            inFile >> id >> score;
            records.emplace_back(id, score);
        }
        
        inFile.close();
        return true;
    }
    
    // 对记录按id进行快速排序
    void sortById() {
        if (!records.empty()) {
            quickSort(records, 0, records.size() - 1);
        }
    }
    
    // 查找指定score的第一个记录
    int searchByScore(int targetScore) {
        return binarySearch(targetScore);
    }
    
    // 输出结果到文件
    void writeToFile(const string& filename, int searchResult) {
        ofstream outFile(filename);
        if (!outFile.is_open()) {
            return;
        }
        
        // 输出排序后的记录
        for (const auto& record : records) {
            outFile << record.id << " " << record.score << endl;
        }
        
        // 输出查找结果
        if (searchResult != -1) {
            outFile << searchResult << endl;
        } else {
            outFile << "NOT FOUND" << endl;
        }
        
        outFile.close();
    }
    
    // 打印记录（用于调试）
    void printRecords() {
        cout << "当前记录:" << endl;
        for (const auto& record : records) {
            cout << "ID: " << record.id << ", Score: " << record.score << endl;
        }
    }
};

int main() {
    SortSearchSystem system;
    
    // 从文件读取数据
    if (!system.readFromFile("in.txt")) {
        return 1;
    }
    
    // 对记录按id进行快速排序
    system.sortById();
    
    // 读取要查找的score值
    ifstream inFile("in.txt");
    if (!inFile.is_open()) {
        return 1;
    }
    
    int n;
    inFile >> n;
    
    // 跳过n行记录
    for (int i = 0; i < n; i++) {
        int id, score;
        inFile >> id >> score;
    }
    
    int targetScore;
    inFile >> targetScore;
    inFile.close();
    
    // 查找指定score的记录
    int result = system.searchByScore(targetScore);
    
    // 输出结果到文件
    system.writeToFile("out.txt", result);
    
    return 0;
}
