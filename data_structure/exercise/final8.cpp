#include <iostream>
#include <unordered_map>
using namespace std;

struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode() : data(0), left(nullptr), right(nullptr) {}
    TreeNode(int d) : data(d), left(nullptr), right(nullptr) {}
};

TreeNode* builtTree(int n) {
    unordered_map<int, TreeNode*> nodes;
    TreeNode* root = nullptr;

    for (int i=0;i<n;i++) {
        int x, l, r;
        cin >> x >> l >> r;

        if (!nodes.count(x)) {
            nodes[x] = new TreeNode(x);
            if (!root) root = nodes[x];
        }

        if (l != 0) {
            if (!nodes.count(l)) {
                nodes[l] = new TreeNode(l);
            }
            nodes[x]->left = nodes[l];
        }
        if (r != 0) {
            if (!nodes.count(r)) {
                nodes[r] = new TreeNode(r);
            }
            nodes[x]->right = nodes[r];
        }
    }
    return root;
}

int maxDepth(TreeNode* root) {
    if (!root) return 0;

    int leftDepth = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);
    return max(leftDepth, rightDepth)+1;
}


int main() {
    int n;
    cin >> n;

    TreeNode* root = builtTree(n);
    cout << (maxDepth(root)-1);
}
