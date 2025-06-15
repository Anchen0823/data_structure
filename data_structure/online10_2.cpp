#include <iostream>
#include <vector>
#include <unordered_map>
#include <fstream>

using namespace std;

// 定义二叉树节点
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// 建立二叉树并返回根节点
TreeNode* buildTree(vector<int>& preorder, int preStart, int preEnd,
                   vector<int>& inorder, int inStart, int inEnd,
                   unordered_map<int, int>& inMap) {
    if (preStart > preEnd || inStart > inEnd) {
        return nullptr;
    }
    
    // 先序遍历的第一个节点是根节点
    int rootVal = preorder[preStart];
    TreeNode* root = new TreeNode(rootVal);
    
    // 找到根节点在中序遍历中的位置
    int rootIndex = inMap[rootVal];
    
    // 计算左子树的大小
    int leftSize = rootIndex - inStart;
    
    // 递归构建左子树和右子树
    root->left = buildTree(preorder, preStart + 1, preStart + leftSize,
                          inorder, inStart, rootIndex - 1, inMap);
    root->right = buildTree(preorder, preStart + leftSize + 1, preEnd,
                           inorder, rootIndex + 1, inEnd, inMap);
    
    return root;
}

// 后序遍历并保存结果
void postorderTraversal(TreeNode* root, vector<int>& result) {
    if (root == nullptr) {
        return;
    }
    
    // 左子树 -> 右子树 -> 根节点
    postorderTraversal(root->left, result);
    postorderTraversal(root->right, result);
    result.push_back(root->val);
}

// 释放二叉树内存
void deleteTree(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

int main() {
    freopen("in.txt", "r", stdin);
    
    int n;
    cin >> n;
    
    // 读取先序序列
    vector<int> preorder(n);
    for (int i = 0; i < n; i++) {
        cin >> preorder[i];
    }
    
    // 读取中序序列
    vector<int> inorder(n);
    for (int i = 0; i < n; i++) {
        cin >> inorder[i];
    }
    
    // 创建中序序列的值和索引的映射，方便快速查找
    unordered_map<int, int> inMap;
    for (int i = 0; i < n; i++) {
        inMap[inorder[i]] = i;
    }
    
    // 构建二叉树
    TreeNode* root = buildTree(preorder, 0, n - 1, inorder, 0, n - 1, inMap);
    
    // 后序遍历
    vector<int> postorder;
    postorderTraversal(root, postorder);
    
    // 输出后序序列
    for (int i = 0; i < n; i++) {
        cout << postorder[i];
        if (i < n - 1) {
            cout << " ";
        }
    }
    cout << endl;
    
    // 释放内存
    deleteTree(root);
    
    return 0;
}
