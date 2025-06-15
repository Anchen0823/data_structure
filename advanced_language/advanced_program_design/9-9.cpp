#include <iostream>
#include <vector>
#include <stdexcept>

class IntStack {
private:
    std::vector<int> elements;

public:
    // 入栈
    void push(int value) {
        elements.push_back(value);
    }

    // 出栈
    void pop() {
        if (elements.empty()) {
            throw std::out_of_range("Stack underflow");
        }
        elements.pop_back();
    }

    // 获取栈顶元素
    int top() const {
        if (elements.empty()) {
            throw std::out_of_range("Stack is empty");
        }
        return elements.back();
    }

    // 检查栈是否为空
    bool empty() const {
        return elements.empty();
    }

    // 重载==
    bool operator==(const IntStack& other) const {
        return elements == other.elements;
    }

    // 重载<（按字典序）
    bool operator<(const IntStack& other) const {
        return elements < other.elements;
    }

    // 打印栈
    void print() const {
        for (int value : elements) {
            std::cout << value << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    IntStack stack1;    // 123
    IntStack stack2;    // 124

    stack1.push(1);
    stack1.push(2);
    stack1.push(3);

    stack2.push(1);
    stack2.push(2);
    stack2.push(4);

    if (stack1 == stack2) {
        std::cout << "stack1 和 stack2 相等" << std::endl;
    } else {
        std::cout << "stack1 和 stack2 不相等" << std::endl;
    }

    if (stack1 < stack2) {
        std::cout << "stack1 小于 stack2" << std::endl;
    } else {
        std::cout << "stack1 不小于 stack2" << std::endl;
    }

    // 打印栈
    std::cout << "stack1 内容: ";
    stack1.print();

    std::cout << "stack2 内容: ";
    stack2.print();

    return 0;
}