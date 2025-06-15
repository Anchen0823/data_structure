#include <iostream>
#include <stack>
#include <queue>
#include <fstream>
using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : data(0), left(nullptr), right(nullptr) {}
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

void preOrderTraversal(TreeNode* root) {
    if (root == nullptr) {
        cout << "null" << " ";
        return;
    };
    cout << root->data << " ";
    if (root->left) (preOrderTraversal(root->left));
    if (root->right) (preOrderTraversal(root->right));
}

bool isCompleteTree(TreeNode* root) {
    if (!root) return true;  // 空树是完全二叉树

    queue<TreeNode*> q;
    q.push(root);
    bool hasNull = false;  // 标记是否遇到空节点

    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();

        if (!node) {
            hasNull = true;  // 遇到空节点
        } else {
            // 如果之前已经遇到空节点，但当前节点非空，则不是完全二叉树
            if (hasNull) return false;
            q.push(node->left);
            q.push(node->right);
        }
    }
    return true;
}

int main() {
    freopen("in.txt", "r", stdin);
    string line;
    getline(cin, line);
    TreeNode* root = buildTree(line);
    // preOrderTraversal(root);

    cout << isCompleteTree(root);
    return 0;
}