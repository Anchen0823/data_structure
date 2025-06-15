#include <iostream>
#include <string>

void reverse(std::string &s);
void reverseHelper(std::string &s, int start, int end);

int main() {
    std::string str;

    std::cout << "请输入一个字符串: ";
    std::getline(std::cin, str);

    reverse(str);

    std::cout << "倒序后的字符串为: " << str << std::endl;

    return 0;
}

void reverse(std::string &s) {
    int length = s.length();
    reverseHelper(s, 0, length - 1);
}

void reverseHelper(std::string &s, int start, int end) {
    if (start >= end) {
        return;
    }
    
    std::swap(s[start], s[end]);
    
    reverseHelper(s, start + 1, end - 1);
}