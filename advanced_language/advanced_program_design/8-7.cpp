#include <iostream>

class Point {
private:
    int x, y;

public:
    // 构造函数
    Point(int x = 0, int y = 0) : x(x), y(y) {}

    // 前缀自增运算符重载
    Point& operator++() {
        ++x;
        ++y;
        return *this;
    }

    // 后缀自增运算符重载
    Point operator++(int) {
        Point temp = *this; // 保存当前对象的副本
        ++(*this);         // 调用前缀自增运算符
        return temp;       // 返回修改前的对象副本
    }

    // 前缀自减运算符重载
    Point& operator--() {
        --x;
        --y;
        return *this;
    }

    // 后缀自减运算符重载
    Point operator--(int) {
        Point temp = *this; // 保存当前对象的副本
        --(*this);         // 调用前缀自减运算符
        return temp;       // 返回修改前的对象副本
    }

    // 用于输出Point对象的方法
    void print() const {
        std::cout << "(" << x << ", " << y << ")" << std::endl;
    }
};

int main() {
    Point p(1, 2);

    std::cout << "Original Point: ";
    p.print();

    ++p; // 前缀自增
    std::cout << "After prefix ++p: ";
    p.print();

    p++; // 后缀自增
    std::cout << "After postfix p++: ";
    p.print();

    --p; // 前缀自减
    std::cout << "After prefix --p: ";
    p.print();

    p--; // 后缀自减
    std::cout << "After postfix p--: ";
    p.print();

    return 0;
}