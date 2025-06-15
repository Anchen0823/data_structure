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

    TreeNode* p=nullptr;
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

int depth(TreeNode* root, int& maxDepth) {
    if (!root) return 0;

    int left_depth = depth(root->left, maxDepth);
    int right_depth = depth(root->right, maxDepth);
    maxDepth = max(maxDepth, left_depth+right_depth+1);
    return max(left_depth, right_depth) + 1;
}

int diameterOfBinaryTree(TreeNode *root) {
    int maxDepth = 1;
    depth(root, maxDepth);
    return maxDepth-1;
}

int main() {
    freopen("in.txt", "r", stdin);
    string line;
    getline(cin, line);
    TreeNode* root = buildTree(line);
    cout << diameterOfBinaryTree(root);
}