#include <iostream>
#include <fstream>
#include <string>

int main() {
    // 创建一个输入文件流对象，并打开文件 test1.txt
    std::ifstream inFile("test1.txt");

    // 检查文件是否成功打开
    if (!inFile) {
        std::cerr << "无法打开文件！" << std::endl;
        return 1;  // 返回非零值表示错误
    }

    // 读取文件内容并存储到字符串中
    std::string line;
    while (std::getline(inFile, line)) {
        // 输出每一行到控制台
        std::cout << line << std::endl;
    }
    inFile.close();

    return 0;  // 返回零值表示成功
}