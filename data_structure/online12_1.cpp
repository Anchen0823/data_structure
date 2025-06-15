#include <iostream>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

// 后缀表达式转队列顺序
string postfixToQueueOrder(const string& postfix) {
    struct Node {
        char value;
        Node* left;
        Node* right;
        
        Node(char val) : value(val), left(nullptr), right(nullptr) {}
    };
    
    // 构建表达式树
    stack<Node*> s;
    for (char c : postfix) {
        Node* node = new Node(c);
        
        if (isupper(c)) { // 运算符
            node->right = s.top(); s.pop();
            node->left = s.top(); s.pop();
        }
        
        s.push(node);
    }
    
    Node* root = s.top();
    
    // 层序遍历表达式树
    vector<char> levelOrder;
    queue<Node*> q;
    q.push(root);
    
    while (!q.empty()) {
        Node* current = q.front();
        q.pop();
        
        levelOrder.push_back(current->value);
        
        // 先左子树再右子树，确保层序遍历的正确顺序
        if (current->left) q.push(current->left);
        if (current->right) q.push(current->right);
    }
    
    // 倒序输出
    reverse(levelOrder.begin(), levelOrder.end());
    string result(levelOrder.begin(), levelOrder.end());
    
    // 释放内存
    /*function<void(Node*)> freeTree = [](Node* node) {
        if (!node) return;
        freeTree(node->left);
        freeTree(node->right);
        delete node;
    };
    
    freeTree(root);*/
    
    return result;
}

int main() {
    freopen("in.txt", "r", stdin);
    string postfix;
    
    while (getline(cin, postfix)) {
        if (postfix.empty()) break;
        cout << postfixToQueueOrder(postfix) << endl;
    }
    
    return 0;
}