#include <iostream>
#include <stack>
#include <queue>
#include <fstream>
using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : data(-1), left(nullptr), right(nullptr) {}
    TreeNode(int d) : data(d), left(nullptr), right(nullptr) {}
};

TreeNode* buildTree(const string& s) {
    if (s.empty()) return nullptr;

    TreeNode* p;
    stack<TreeNode*> stk;
    TreeNode* root = nullptr;
    bool isLeft = true;  // 标记下一个节点是左孩子还是右孩子


    int i = 0;
    int n = s.size();
    while (i < n) {
        if (isdigit(s[i])) {
            int num = 0;
            while (i < n && isdigit(s[i])) {
                num = num * 10 + (s[i] - '0');
                i++;
            }
            p = new TreeNode(num);
            if (!root) {
                root = p;
            } else {
                if (isLeft) {
                    stk.top()->left = p;
                } else {
                    stk.top()->right = p;
                }
            }
            continue;
        }
        switch (s[i]) {
            case '(':
                stk.push(p);
                isLeft = true;
                break;
            case ')':
                stk.pop();
                break;
            case ',':
                isLeft = false;
                break;
        }
        i++;
    }

    return root;
}

void printLeaf1(TreeNode* root) {
    if (root == nullptr) {
        return;
    };
    if (!root->left && !root->right) cout << root->data << " ";
    if (root->left) (printLeaf1(root->left));
    if (root->right) (printLeaf1(root->right));
}

void printLeaf2(TreeNode* root) {
    if (root == nullptr) {
        return;
    };
    if (!root->left && !root->right) cout << root->data << " ";
    if (root->right) (printLeaf2(root->right));
    if (root->left) (printLeaf2(root->left));
}

void print3(TreeNode* root) {
    if (!root) return;

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();

        if (node) {
            cout << node->data << " ";
            q.push(node->right);
            q.push(node->left);
        }
    }
}

int main() {
    freopen("in.txt", "r", stdin);
    string line;
    getline(cin, line);
    TreeNode* root = buildTree(line);
    printLeaf1(root);cout << endl;
    printLeaf2(root);cout << endl;
    print3(root);
    return 0;
}