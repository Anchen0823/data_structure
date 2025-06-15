#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode() : left(nullptr), right(nullptr) {}
    TreeNode(int d) : val(d), left(nullptr), right(nullptr) {}
};

TreeNode* insert(TreeNode* root, int val) {
    if (root == nullptr) {
        return new TreeNode(val);
    }

    if (val < root->val) {
        root->left = insert(root->left, val);
    } else if (val > root->val) {
        root->right = insert(root->right, val);
    }
    return root;
}

// printTree
void printTreeHelper(TreeNode* root, ofstream& file) {
    if (root == nullptr) {
        return;
    }
    printTreeHelper(root->left, file);
    file << root->val << " ";
    printTreeHelper(root->right, file);
}

void printTree(TreeNode* root, ofstream& file) {
    if (root == nullptr) {
        file << endl;
        return;
    }
    printTreeHelper(root, file);
    file << endl; // 每次输出后换行
}

void rangeQueryHelper(TreeNode* node, int low, int high, vector<int>& result) {
    if (node == nullptr) return;
    
    // 节点值大于low，则查询左子树
    if (node->val > low) {
        rangeQueryHelper(node->left, low, high, result);
    }
    
    // 节点值在范围内，加入结果
    if (node->val >= low && node->val <= high) {
        result.push_back(node->val);
    }

    // 节点值小于high，则查询右子树
    if (node->val < high) {
        rangeQueryHelper(node->right, low, high, result);
    }
}

// 范围查询
vector<int> rangeQuery(TreeNode* root, int low, int high) {
    vector<int> result;
    rangeQueryHelper(root, low, high, result);
    return result;
}



int main() {
    TreeNode* root = nullptr;
    freopen("in.txt", "r", stdin);
    ofstream file("out.txt");
    int m; cin >> m;
    char type;
    int a, b;
    for (int i = 0; i < m; i++) {
        cin >> type;
        switch (type)
        {
        case 'I':
            cin >> a;
            root = insert(root, a);
            break;
        case 'T':
            printTree(root, file);
            break;
        case 'Q':
            cin >> a >> b;
            vector<int> result = rangeQuery(root, a, b);

            if (result.empty()) {
                file << "NULL" << endl;
            } else {
                for (int num : result) {
                    file << num << " ";
                }
                file << endl;
            }

            break;
        }
    }
    file.close();
    return 0;
}