#include <iostream>
#include <chrono>

int main() {
    // 记录开始时间点
    auto start = std::chrono::steady_clock::now();

    // 待测试的代码
    // 解法2

    size_t sum=0;
    for (int i=0;i<=50100;i++) {
        sum += ((i+1)*i /2);
    }

    // 记录结束时间点
    auto end = std::chrono::steady_clock::now();

    // 计算时间差并转换为毫秒
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();

    std::cout << "耗时：" << duration << " 毫秒" << std::endl;
    return 0;
}