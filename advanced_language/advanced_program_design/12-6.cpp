#include <iostream>
#include <string>
#include <stdexcept>

class CException : public std::exception {
public:
    CException(const std::string& reason) : reason_(reason) {}

    virtual const char* what() const noexcept override {
        return reason_.c_str();
    }

    void Reason() const {
        std::cerr << "Exception reason: " << reason_ << std::endl;
    }

private:
    std::string reason_;
};

void fn1() {
    throw CException("An error occurred in fn1");
}

int main() {
    try {
        fn1();
    } catch (const CException& e) {
        // 捕获到 CException 异常
        std::cerr << "Caught a CException:" << std::endl;
        e.Reason(); // 调用 Reason() 方法显示异常原因
    } catch (const std::exception& e) {
        std::cerr << "Caught a std::exception:" << std::endl;
        std::cerr << e.what() << std::endl;
    } catch (...) {
        // 捕获所有其他类型的异常
        std::cerr << "Caught an unknown exception" << std::endl;
    }

    // 程序继续执行
    std::cout << "Program continues after handling the exception." << std::endl;

    return 0;
}