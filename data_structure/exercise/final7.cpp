#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode
{
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode() : data(0), left(nullptr), right(nullptr) {}
    TreeNode(int d) : data(0), left(nullptr), right(nullptr) {}
};

TreeNode* _builtTree(vector<int>& nums, int& idx, int& n) {
    if (n <= 0 || idx >= n) return nullptr;

    if (nums[idx] == -1) {
        idx++;
        return nullptr;
    }

    TreeNode* root = new TreeNode(nums[idx]);
    idx++;

    root->left = _builtTree(nums, idx, n);
    root->right = _builtTree(nums, idx, n);
    return root;
}

TreeNode* builtTree(vector<int>& nums) {
    int n = nums.size();
    if (n <= 0) return nullptr;
    int idx = 0;
    return _builtTree(nums, idx, n);
}

int maxWidth(TreeNode* root) {
    int width = 0;
    if (root == nullptr) return width;

    TreeNode* curr;
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        int n = q.size();   // 当前层数的结点个数
        width = max(n, width);
        for (int i=0;i<n;i++) {
            curr = q.front(); q.pop();
            if (curr->left != nullptr) {
                q.push(curr->left);
            }
            if (curr->right != nullptr) {
                q.push(curr->right);
            }
        }
    }
    return width;
}

int main() {
    int num;
    vector<int> nums;
    while (cin >> num) {
        nums.push_back(num);
    }
    TreeNode* root = builtTree(nums);
    cout << maxWidth(root);
}