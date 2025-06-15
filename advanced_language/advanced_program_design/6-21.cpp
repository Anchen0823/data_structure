#include <iostream>
#include <string>
#include <cctype>

int countLetters(const std::string& sentence);

int main() {
    std::string sentence;
    // std::cout << "请输入一条英文句子: ";
    std::getline(std::cin, sentence);
    int letterCount = countLetters(sentence);
    std::cout << "这个句子里有" << letterCount << "个英文字母。" << std::endl;

    return 0;
}

int countLetters(const std::string& sentence) {
    int count = 0;
    for (char ch : sentence) {
        if (std::isalpha(static_cast<unsigned char>(ch))) {
            ++count;
        }
    }
    return count;
}