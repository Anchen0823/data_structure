#include <iostream>
#include <deque>

int main() {
    std::deque<char> charDeque;

    charDeque.push_back('A');
    charDeque.push_back('B');
    charDeque.push_front('X');
    charDeque.push_front('Y');

    std::cout << "双向队列内容: ";
    for (char c : charDeque) {
        std::cout << c << " ";
    }
    std::cout << std::endl;

    if (!charDeque.empty()) {
        std::cout << "第一个元素: " << charDeque.front() << std::endl;
        std::cout << "最后一个元素: " << charDeque.back() << std::endl;
    } else {
        std::cout << "队列为空，无法访问元素。" << std::endl;
    }

    charDeque.pop_front();
    charDeque.pop_back();

    std::cout << "移除元素后，双向队列内容: ";
    for (char c : charDeque) {
        std::cout << c << " ";
    }
    std::cout << std::endl;

    return 0;
}