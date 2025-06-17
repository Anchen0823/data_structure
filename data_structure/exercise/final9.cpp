#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

struct TreeNode {
    char ch;
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode() : ch('$'), data(0), left(nullptr), right(nullptr) {}
    TreeNode(char c, int d) : ch(c), data(d), left(nullptr), right(nullptr) {}
};

bool compareByData(TreeNode* a, TreeNode* b) {
    return a->data > b->data;
}

void sortNodes(vector<TreeNode*>& nodes) {
    sort(nodes.begin(), nodes.end(), compareByData);
}

TreeNode* builtHTree(vector<TreeNode*>& nodes) {
    while (nodes.size() > 1) {
        sortNodes(nodes);
        
        TreeNode* left = nodes.back(); nodes.pop_back();
        TreeNode* right = nodes.back(); nodes.pop_back();
        
        TreeNode* parent = new TreeNode('$', left->data + right->data);
        parent->left = left;
        parent->right = right;
        
        nodes.push_back(parent);
    }
    return nodes.empty() ? nullptr : nodes[0];
}

void generateHCode(TreeNode* root, string code, unordered_map<char, string>& HCode) {
    if (!root) return;

    // leave node
    if (!root->left && !root->right && root->ch!='$') {
        HCode[root->ch] = code;
        return;
    }

    generateHCode(root->left, code+'0', HCode);
    generateHCode(root->right, code+'1', HCode);
}

void printHCode(unordered_map<char, string>& HCode, vector<char>& inputOrder) {
    for (char ch : inputOrder) {
        auto it = HCode.find(ch);
        if (it != HCode.end()) {
            cout << it->second << " ";
        }
    }
}

int main() {
    int n;
    cin >> n;
    
    int num;
    char ch;
    vector<TreeNode*> nodes(n);
    vector<char> inputOrder;
    for (int i=0;i<n;i++) {
        cin >> ch >> num;
        TreeNode* newNode = new TreeNode(ch, num);
        inputOrder.push_back(ch);
        nodes[i] = newNode;
    }

    TreeNode* root = builtHTree(nodes);

    unordered_map<char, string> HCode;
    generateHCode(root, "", HCode);
    
    printHCode(HCode, inputOrder);
}