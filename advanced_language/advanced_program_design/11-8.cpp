#include <iostream>
#include <iomanip>

int main() {
    int decimalNumber;

    // 提示用户输入一个十进制整数
    std::cout << "请输入一个十进制整数: ";
    std::cin >> decimalNumber;

    // 以十进制形式输出
    std::cout << "十进制: " << decimalNumber << std::endl;

    // 以八进制形式输出
    std::cout << "八进制: " << std::oct << decimalNumber << std::endl;

    // 以十六进制形式输出
    std::cout << "十六进制: " << std::hex << decimalNumber << std::endl;

    return 0;
}