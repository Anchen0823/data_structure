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

int playGame() {
    while (true) {
        int result = playOneRound();
        if (result == 0) {
            int result2 = playOneRound();
            int result3 = playOneRound();
            if (result2 == 1 && result3 == 1) {
                return 1; // 反正正
            } else if (result2 == 0 && result3 == 1) {
                return 0; // 反反正
            }
        }
    }
}

int main() {
    for (int i = 0; i < 10; ++i) {
        int finalResult = playGame();
        if (finalResult == 1) {
            std::cout << "游戏结果：反正正" << std::endl;
        } else {
            std::cout << "游戏结果：反反正" << std::endl;
        }
    }
    return 0;
}