#include <iostream>
#include <stack>
#include <queue>
#include <string>
#include <cctype>
#include <map>
#include <vector>
using namespace std;

// 表达式树节点定义
struct TreeNode {
    char val;
    TreeNode* left;
    TreeNode* right;
    
    TreeNode(char x) : val(x), left(NULL), right(NULL) {}
};

// 判断是否为运算符
bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

// 判断运算符优先级
int precedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    return 0;
}

// 中缀表达式转后缀表达式
string infixToPostfix(const string& infix) {
    string postfix = "";
    stack<char> s;
    
    for (int i = 0; i < infix.length(); i++) {
        char c = infix[i];
        
        // 如果是操作数（数字或字母），直接添加到后缀表达式
        if (isalnum(c)) {
            postfix += c;
        }
        // 如果是左括号，压入栈
        else if (c == '(') {
            s.push(c);
        }
        // 如果是右括号，弹出栈直到找到匹配的左括号
        else if (c == ')') {
            while (!s.empty() && s.top() != '(') {
                postfix += s.top();
                s.pop();
            }
            s.pop(); // 弹出左括号
        }
        // 如果是运算符
        else if (isOperator(c)) {
            while (!s.empty() && s.top() != '(' && precedence(s.top()) >= precedence(c)) {
                postfix += s.top();
                s.pop();
            }
            s.push(c);
        }
    }
    
    // 弹出栈中剩余的所有运算符
    while (!s.empty()) {
        postfix += s.top();
        s.pop();
    }
    
    return postfix;
}

// 从后缀表达式构建表达式树
TreeNode* buildExpressionTree(const string& postfix) {
    stack<TreeNode*> s;
    
    for (char c : postfix) {
        TreeNode* node = new TreeNode(c);
        
        if (isOperator(c)) {
            // 运算符有两个操作数，从栈中弹出
            node->right = s.top(); s.pop();
            node->left = s.top(); s.pop();
        }
        
        s.push(node);
    }
    
    return s.top();
}

// 计算表达式树的值
int evaluateExpressionTree(TreeNode* root) {
    if (!root) return 0;
    
    // 如果是叶子节点（操作数）
    if (!root->left && !root->right) {
        char val = root->val;
        if (isdigit(val)) {
            return val - '0'; // 数字
        } else {
            return int(val); // 字母的ASCII值
        }
    }
    
    // 计算左右子树的值
    int leftVal = evaluateExpressionTree(root->left);
    int rightVal = evaluateExpressionTree(root->right);
    
    // 根据运算符进行计算
    switch (root->val) {
        case '+': return leftVal + rightVal;
        case '-': return leftVal - rightVal;
        case '*': return leftVal * rightVal;
        case '/': return leftVal / rightVal;
        default: return 0;
    }
}

// 层次遍历（倒序）
string levelOrderTraversalReversed(TreeNode* root) {
    if (!root) return "";
    
    queue<TreeNode*> q;
    vector<char> result;
    
    q.push(root);
    
    while (!q.empty()) {
        TreeNode* node = q.front();
        q.pop();
        
        result.push_back(node->val);
        
        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);
    }
    
    // 反转结果
    string reversed = "";
    for (int i = result.size() - 1; i >= 0; i--) {
        reversed += result[i];
    }
    
    return reversed;
}

// 从层次遍历倒序重建表达式树
TreeNode* rebuildFromReversedLevelOrder(const string& reversed) {
    if (reversed.empty()) return nullptr;
    
    vector<TreeNode*> nodes;
    
    // 创建所有节点
    for (char c : reversed) {
        nodes.push_back(new TreeNode(c));
    }
    
    int n = nodes.size();
    for (int i = 0; i < n; i++) {
        int leftIdx = 2 * i + 1;
        int rightIdx = 2 * i + 2;
        
        if (leftIdx < n) {
            nodes[i]->left = nodes[leftIdx];
        }
        if (rightIdx < n) {
            nodes[i]->right = nodes[rightIdx];
        }
    }
    
    return nodes[0];
}

// 从层次遍历的倒序字符串构建表达式树
TreeNode* buildTreeFromLevelOrderReversed(const string& reversedLevelOrder) {
    if (reversedLevelOrder.empty()) return nullptr;
    
    // 创建根节点（最后一个字符）
    TreeNode* root = new TreeNode(reversedLevelOrder[reversedLevelOrder.length() - 1]);
    queue<TreeNode*> q;
    q.push(root);
    
    int i = reversedLevelOrder.length() - 2; // 从倒数第二个字符开始
    
    while (!q.empty() && i >= 0) {
        TreeNode* curr = q.front();
        q.pop();
        
        // 如果当前节点是运算符，需要为其分配两个子节点
        if (isOperator(curr->val)) {
            // 右子节点
            if (i >= 0) {
                curr->right = new TreeNode(reversedLevelOrder[i--]);
                q.push(curr->right);
            }
            
            // 左子节点
            if (i >= 0) {
                curr->left = new TreeNode(reversedLevelOrder[i--]);
                q.push(curr->left);
            }
        }
    }
    
    return root;
}

int main() {
    string expr;
    getline(cin, expr);
    
    // 转换为后缀表达式
    string postfix = infixToPostfix(expr);
    
    // 构建表达式树
    TreeNode* root = buildExpressionTree(postfix);
    
    // 计算表达式值
    int result = evaluateExpressionTree(root);
    cout << result << endl;
    
    // 层次遍历倒序
    string reversedLevelOrder = levelOrderTraversalReversed(root);
    cout << reversedLevelOrder << endl;
    cout << result << endl;
    
    // 从层次遍历倒序重建表达式树
    TreeNode* rebuiltRoot = buildTreeFromLevelOrderReversed(reversedLevelOrder);
    
    // 计算重建树的表达式值
    int rebuiltResult = evaluateExpressionTree(rebuiltRoot);
    //cout << rebuiltResult << endl;
    
    return 0;
}