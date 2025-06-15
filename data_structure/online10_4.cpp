#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <fstream>

// 定义二叉树节点结构
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

// 解析括号表示法的二叉树字符串
TreeNode* buildTree(const std::string& s, int& pos) {
    // 跳过空白字符
    while (pos < s.size() && s[pos] == ' ') pos++;
    
    if (pos >= s.size() || !isdigit(s[pos])) {
        return nullptr;
    }
    
    // 解析节点值
    int val = 0;
    while (pos < s.size() && isdigit(s[pos])) {
        val = val * 10 + (s[pos] - '0');
        pos++;
    }
    
    TreeNode* root = new TreeNode(val);
    
    // 跳过空白字符
    while (pos < s.size() && s[pos] == ' ') pos++;
    
    // 处理左右子树
    if (pos < s.size() && s[pos] == '(') {
        pos++; // 跳过左括号
        
        // 处理左子树
        root->left = buildTree(s, pos);
        
        // 跳过逗号
        if (pos < s.size() && s[pos] == ',') {
            pos++;
            // 处理右子树
            root->right = buildTree(s, pos);
        }
        
        // 跳过右括号
        if (pos < s.size() && s[pos] == ')') {
            pos++;
        }
    }
    
    return root;
}

// 解析括号表示法的二叉树字符串（主函数）
TreeNode* parseTree(const std::string& s) {
    int pos = 0;
    return buildTree(s, pos);
}

// 获取二叉树的右视图
std::vector<int> rightSideView(TreeNode* root) {
    std::vector<int> result;
    if (!root) return result;
    
    std::queue<TreeNode*> q;
    q.push(root);
    
    while (!q.empty()) {
        int levelSize = q.size();
        
        for (int i = 0; i < levelSize; ++i) {
            TreeNode* node = q.front();
            q.pop();
            
            // 如果是当前层的最后一个节点，将其添加到结果中
            if (i == levelSize - 1) {
                result.push_back(node->val);
            }
            
            // 将子节点添加到队列中
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }
    }
    
    return result;
}

// 释放二叉树内存
void freeTree(TreeNode* root) {
    if (root) {
        freeTree(root->left);
        freeTree(root->right);
        delete root;
    }
}

int main() {
    std::ifstream inFile("in.txt");
    std::string treeStr;
    std::getline(inFile, treeStr);
    inFile.close();
    
    TreeNode* root = parseTree(treeStr);
    std::vector<int> rightView = rightSideView(root);
    
    // 格式化输出
    std::cout << "[";
    for (size_t i = 0; i < rightView.size(); ++i) {
        std::cout << rightView[i];
        if (i < rightView.size() - 1) {
            std::cout << ",";
        }
    }
    std::cout << "]" << std::endl;
    
    // 释放内存
    freeTree(root);
    
    return 0;
}
