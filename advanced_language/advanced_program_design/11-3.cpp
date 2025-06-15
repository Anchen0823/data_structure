#include <iostream>
#include <fstream>

int main() {
    // 创建一个输出文件流对象，并打开文件 test1.txt
    std::ofstream outFile("test1.txt");

    // 检查文件是否成功打开
    if (!outFile) {
        std::cerr << "无法打开文件！" << std::endl;
        return 1;  // 返回非零值表示错误
    }

    outFile << "已成功写入文件！" << std::endl;
    outFile.close();

    std::cout << "文件写入成功！" << std::endl;

    return 0;
}