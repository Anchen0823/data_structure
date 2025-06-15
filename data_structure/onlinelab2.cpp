#include <iostream>
#include <stack>
#include <string>
using namespace std;

// 表达式处理类
class Express {
    string exp;     // 存储原始表达式
    string postexp; // 存储转换后的后缀表达式
public:
    Express(string str) {  // 构造函数
        exp = str;
        postexp = "";
    }

    // 将中缀表达式转换为后缀表达式
    void Trans() {
        stack<char> op;  // 运算符栈
        char e;
        size_t i = 0;
        while (i < exp.size()) {
            // 处理左括号
            if (exp[i] == '(') {
                op.push(exp[i]);
            } 
            // 处理右括号
            else if (exp[i] == ')') {
                // 弹出栈顶元素直到遇到左括号
                while (!op.empty() && op.top()!='(') {
                    e = op.top();
                    op.pop();
                    postexp += e;
                }
                op.pop();  // 弹出左括号
            } 
            // 处理加减运算符
            else if (exp[i] == '+' || exp[i] == '-') {
                // 弹出栈顶所有优先级不低于当前运算符的运算符
                while (!op.empty() && op.top()!='(') {
                    e = op.top();
                    op.pop();
                    postexp += e;
                }
                op.push(exp[i]);
            } 
            // 处理乘除运算符
            else if (exp[i] == '*' || exp[i] == '/') {
                // 只弹出栈顶的乘除运算符
                while (!op.empty() && op.top()!='(' && (op.top()=='*' || op.top()=='/')) {
                    e = op.top();
                    op.pop();
                    postexp += e;
                }
                op.push(exp[i]);
            } 
            // 处理字母
            else if (('A' <= exp[i] && exp[i] <= 'Z') || ('a' <= exp[i] && exp[i] <= 'z')) {
                int num = (int)exp[i];  // 获取ASCII码
                postexp += to_string(num);  // 转换为字符串
                postexp += '#';  // 添加分隔符
            } 
            // 处理数字
            else if ('0' <= exp[i] && exp[i] <= '9') {
                string d = "";
                // 读取连续的数字
                while ('0' <= exp[i] && exp[i] <= '9') {
                    d += exp[i];
                    i++;
                }
                postexp += d;  // 添加数字
                postexp += '#';  // 添加分隔符
                continue;  // 跳过i++，因为while循环已经移动了i
            }
            i++;
        }
        // 弹出栈中剩余的所有运算符
        while (!op.empty()) {
            e = op.top();
            op.pop();
            postexp += e;
        }
    }

    // 计算后缀表达式的值
    int getValue() {
        stack<int> opand;  // 操作数栈
        int a, b, c, d;
        char ch;
        size_t i = 0;
        while (i < postexp.length()) {
            ch = postexp[i];
            switch (ch) {
            case '+':  // 加法运算
                a = opand.top(); opand.pop();
                b = opand.top(); opand.pop();
                c = b + a;
                opand.push(c);
                break;
            case '-':  // 减法运算
                a = opand.top(); opand.pop();
                b = opand.top(); opand.pop();
                c = b - a;
                opand.push(c);
                break;
            case '*':  // 乘法运算
                a = opand.top(); opand.pop();
                b = opand.top(); opand.pop();
                c = b * a;
                opand.push(c);
                break;
            case '/':  // 除法运算
                a = opand.top(); opand.pop();
                b = opand.top(); opand.pop();
                c = b / a;
                opand.push(c);
                break;
            default:
                if (ch == '#') {  // 跳过分隔符
                    i++;
                    continue;
                }
                // 处理数字
                d = 0;
                while ('0' <= ch && ch <= '9') {
                    d = 10 * d + (ch - '0');  // 将字符转换为数字
                    i++;
                    ch = postexp[i];
                }
                opand.push(d);  // 数字压栈
                continue;  // 跳过i++，因为while循环已经移动了i
            }
            i++;
        }
        return opand.empty() ? 0.0 : opand.top();  // 返回计算结果
    }
};

int main() {
    int n;
    cin >> n;
    cin.ignore();
    for (int i = 0; i < n; i++) {
        string line1, line2;
        getline(cin, line1);  // 读取表达式
        getline(cin, line2);
        
        Express o1(line1);  // 创建表达式对象
        Express o2(line2);
        
        o1.Trans();  // 转换为后缀表达式
        o2.Trans();

        // 比较两个表达式的计算结果
        if (o1.getValue() == o2.getValue()) {
            cout << "TRUE" << endl;
        } else {
            cout << "FALSE" << endl;
        }
    }

    return 0;
}