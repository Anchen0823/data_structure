#include <iostream>
#include <random>
#include <chrono>

#include <iostream>
#include <cstdlib>
#include <ctime>

bool fiftyPercentChance() {
    // 使用静态生成器，只初始化一次
    static std::mt19937 generator(std::random_device{}());
    static std::uniform_int_distribution<int> distribution(0, 1);
    
    return distribution(generator) == 1;
}

int playOneRound() {
    if (fiftyPercentChance()) {
        std::cout << "正";
        return 1;   // 正
    }

    std::cout << "反";
    return 0;
}

// playGame函数模拟抛硬币游戏，连续抛出硬币，直到出现“反正正”或“反反正”序列，分别返回1或0。
int playGame() {
    int last1 = -1, last2 = -1;
    while (true) {
        int current = playOneRound();
        if (last2 == 0 && last1 == 1 && current == 1) {
            return 1;   // 反正正
        }
        if (last2 == 0 && last1 == 0 && current == 1) {
            return 0;   // 反反正
        }
        last2 = last1;
        last1 = current;
    }
}

int main() {
    int fzz = 0, ffz = 0;
    int times = 1000000;
    for (int i = 0; i < times; ++i) {
        int finalResult = playGame();
        if (finalResult == 1) {
            std::cout << "游戏结果：反正正" << std::endl;
            fzz++;
        } else {
            std::cout << "游戏结果：反反正" << std::endl;
            ffz++;
        }
    }

    std::cout << std::endl;
    std::cout << "反正正出现次数：" << fzz << std::endl;
    std::cout << "反反正出现次数：" << ffz << std::endl;
    std::cout << "反正正概率：" << static_cast<double>(fzz) / times << std::endl;
    std::cout << "反反正概率：" << static_cast<double>(ffz) / times << std::endl;
    return 0;
}