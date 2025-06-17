#include <iostream>
#include <sstream>
#include <string>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node() : data(0), next(nullptr) {}
    Node(int val) : data(val), next(nullptr) {}
};

Node* readList() {
    Node* head = nullptr;
    Node* tail = nullptr;
    string line;
    getline(cin, line);  // 读取整行
    stringstream ss(line);
    int num;
    while (ss >> num) {  // 从字符串流中读取数字
        Node* newNode = new Node(num);
        if (!head) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    return head;
}

bool isPresent(Node* head, int& data) {
    if (!head) return false;
    if (head->data == data) return true;
    return isPresent(head->next, data);
}

Node* diffList(Node* l1, Node* l2) {
    if (!l1) return nullptr;

    Node* rest = diffList(l1->next, l2);

    if (!isPresent(l2, l1->data)) {
        Node* result = new Node(l1->data);
        result->next = rest;
        return result;
    } else {
        return rest;
    }

    return nullptr;
}

int main() {
    Node* l1 = readList();
    Node* l2 = readList();

    Node* l3 = diffList(l1, l2);
    while (l3) {
        cout << l3->data << " ";
        l3 = l3->next;
    }
    return 0;
}