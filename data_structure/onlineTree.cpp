#include <iostream>
#include <vector>
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

void getLeaves(TreeNode* root, vector<int>& res) {
    if (root == nullptr) {
        return;
    };

    if (!root->left && !root->right) {
        res.push_back(root->data);
        return;
    }

    if (root->left) (getLeaves(root->left, res));
    if (root->right) (getLeaves(root->right, res));
}

class Solution {
public:
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> res1, res2;
        getLeaves(root1, res1);
        getLeaves(root2, res2);
        if (res1 == res2) {
            return true;
        } else {
            return false;
        }
    }
    
};

int main() {
    freopen("in.txt", "r", stdin);
    string line1, line2;
    getline(cin, line1);
    getline(cin, line2);
    TreeNode* root1 = buildTree(line1);
    TreeNode* root2 = buildTree(line2);
    
    Solution sol;
    if (sol.leafSimilar(root1, root2)) {
        cout << "true";
    } else {
        cout << "false";
    }
    return 0;
}