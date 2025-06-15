#include <iostream>
#include <string>
#include <cmath>
using namespace std;

template <typename T>
class SqStack {
    T* data;
    int top;
    int MaxSize;
public:
    SqStack(int ms) {
        MaxSize = ms;
        data = new T[MaxSize];
        top = -1;
    }

    ~SqStack() {
        delete[] data;
    }

    bool empty() const {
        return top == -1;
    }

    bool push(T e) {
        if (top == MaxSize - 1)
            return false;
        data[++top] = e;
        return true;
    }

    bool pop(T& e) {
        if (empty())
            return false;
        e = data[top--];
        return true;
    }

    bool getTop(T& e) const {
        if (empty())
            return false;
        e = data[top];
        return true;
    }

    int size() const {
        return top + 1;
    }
};

double GetValue(const string& line) {
    SqStack<double> opand(100);
    size_t i = 0;
    while (i < line.size()) {
        if (line[i] == ',') {
            ++i;
            continue;
        }

        // 处理数字（包括负数）
        if (isdigit(line[i]) || (line[i] == '-' && i + 1 < line.size() && isdigit(line[i + 1]))) {
            int sign = 1;
            if (line[i] == '-') {
                sign = -1;
                ++i;
            }
            double num = 0;
            while (i < line.size() && isdigit(line[i])) {
                num = num * 10 + (line[i] - '0');
                ++i;
            }
            opand.push(sign * num);
        } else {
            // 处理操作符
            char op = line[i];
            double a = 0, b = 0;
            opand.pop(a);
            opand.pop(b);
            double c = 0;
            switch (op) {
                case '+': c = b + a; break;
                case '-': c = b - a; break;
                case '*': c = b * a; break;
                case '/': 
                    c = b / a;
                    c = trunc(c); // 向零取整
                    break;
            }
            opand.push(c);
            ++i;
        }
    }

    double res = 0;
    opand.getTop(res);
    if (res == 0) 
        res = 0;
    return res;
}

int main() {
    freopen("in.txt", "r", stdin);
    string line;
    getline(cin, line);
    cout << GetValue(line) << endl;
    return 0;
}