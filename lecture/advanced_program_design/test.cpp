#include <iostream>
#include <random>
#include <chrono>

bool fiftyPercentChance() {
    // 使用当前时间作为随机种子
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::mt19937 generator(seed);
    
    // 创建一个0到1的均匀分布
    std::uniform_int_distribution<int> distribution(0, 1);
    
    // 返回true或false，各有50%概率
    return distribution(generator) == 1;
}
