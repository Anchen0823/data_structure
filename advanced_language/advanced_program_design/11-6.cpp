#include <iostream>
#include <fstream>
#include <string>

class Dog {
public:
    Dog() : weight(0), age(0) {}
    Dog(int w, int a) : weight(w), age(a) {}

    void setWeight(int w) { weight = w; }
    int getWeight() const { return weight; }

    void setAge(int a) { age = a; }
    int getAge() const { return age; }

    // 用于以文本方式输出Dog对象的状态
    friend std::ostream& operator<<(std::ostream& os, const Dog& dog) {
        os << "Weight: " << dog.weight << ", Age: " << dog.age;
        return os;
    }

    // 用于以文本方式输入Dog对象的状态（输入格式为"Weight: X, Age: Y"）
    friend std::istream& operator>>(std::istream& is, Dog& dog) {
        std::string line;
        std::getline(is, line);
        size_t pos = line.find("Weight: ");
        if (pos != std::string::npos) {
            line = line.substr(pos + 8); // 跳过"Weight: "
            pos = line.find(", Age: ");
            if (pos != std::string::npos) {
                dog.weight = std::stoi(line.substr(0, pos)); // 转换体重
                line = line.substr(pos + 7); // 跳过", Age: "
                dog.age = std::stoi(line); // 转换年龄
            }
        }
        return is;
    }
    int weight;
    int age;
};

int main() {
    // 创建dog1实例，并设置其状态
    Dog dog1(5, 10);

    // 以文本方式写入文件
    {
        std::ofstream outFileText("dog_text.txt");
        if (outFileText.is_open()) {
            outFileText << dog1 << std::endl;
            outFileText.close();
        } else {
            std::cerr << "无法打开文本文件！" << std::endl;
            return 1;
        }
    }

    // 以二进制方式写入文件
    {
        std::ofstream outFileBinary("dog_binary.dat", std::ios::binary);
        if (outFileBinary.is_open()) {
            outFileBinary.write(reinterpret_cast<const char*>(&dog1.weight), sizeof(dog1.weight));
            outFileBinary.write(reinterpret_cast<const char*>(&dog1.age), sizeof(dog1.age));
            outFileBinary.close();
        } else {
            std::cerr << "无法打开二进制文件！" << std::endl;
            return 1;
        }
    }

    // 创建dog2实例，并通过读文本文件来初始化
    Dog dog2;
    {
        std::ifstream inFileText("dog_text.txt");
        if (inFileText.is_open()) {
            inFileText >> dog2;
            inFileText.close();
        } else {
            std::cerr << "无法打开文本文件！" << std::endl;
            return 1;
        }
    }

    // 输出dog2的状态（从文本文件读取）
    std::cout << "dog2 (from text file): " << dog2 << std::endl;

    // 创建dog3实例，并通过读二进制文件来初始化
    Dog dog3;
    {
        std::ifstream inFileBinary("dog_binary.dat", std::ios::binary);
        if (inFileBinary.is_open()) {
            inFileBinary.read(reinterpret_cast<char*>(&dog3.weight), sizeof(dog3.weight));
            inFileBinary.read(reinterpret_cast<char*>(&dog3.age), sizeof(dog3.age));
            inFileBinary.close();
        } else {
            std::cerr << "无法打开二进制文件！" << std::endl;
            return 1;
        }
    }

    // 输出dog3的状态（从二进制文件读取）
    std::cout << "dog3 (from binary file): Weight: " << dog3.getWeight() << ", Age: " << dog3.getAge() << std::endl;

    // 查看磁盘文件的ASCII码（这里只展示文本文件的内容）
    std::ifstream inFileTextForDisplay("dog_text.txt");
    if (inFileTextForDisplay.is_open()) {
        std::string line;
        std::getline(inFileTextForDisplay, line);
        std::cout << "Contents of dog_text.txt: " << line << std::endl;
        inFileTextForDisplay.close();
    } else {
        std::cerr << "无法打开文本文件以显示内容！" << std::endl;
    }

    return 0;
}