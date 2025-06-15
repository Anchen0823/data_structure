#include <iostream>
#include <string>
#include <stdexcept>

// 抽象基类 Exception
class Exception : public std::exception {
public:
    virtual const char* what() const noexcept override = 0; // 纯虚函数
    virtual ~Exception() noexcept = default; // 虚析构函数
};

// 派生类 OutOfMemory
class OutOfMemory : public Exception {
public:
    OutOfMemory(const std::string& message) : message_(message) {}
    
    const char* what() const noexcept override {
        return message_.c_str();
    }

private:
    std::string message_;
};

// 派生类 RangeError
class RangeError : public Exception {
public:
    RangeError(const std::string& message) : message_(message) {}
    
    const char* what() const noexcept override {
        return message_.c_str();
    }

private:
    std::string message_;
};

// 模拟内存不足的情况
void simulateOutOfMemory() {
    throw OutOfMemory("Memory allocation failed: Out of memory");
}

// 模拟输入值不在指定范围内的情况
void simulateRangeError(int value, int min, int max) {
    if (value < min || value > max) {
        throw RangeError("Value is out of range");
    }
}

int main() {
    try {
        simulateOutOfMemory();
    } catch (const Exception& e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }

    try {
        simulateRangeError(10, 1, 5);
    } catch (const Exception& e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }

    try {
        simulateRangeError(3, 1, 5);
    } catch (const Exception& e) {
        std::cerr << "Caught exception: " << e.what() << std::endl;
    }

    return 0;
}