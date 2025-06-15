#include <iostream>

const double PI = 3.1415926l;

class SimpleCircle {
private:
    int* itsRadius;

public:
    // 构造函数
    SimpleCircle(int radius) {
        itsRadius = new int(radius);
    }

    // 复制构造函数
    SimpleCircle(const SimpleCircle& other) {
        itsRadius = new int(*(other.itsRadius));
    }

    // 析构函数
    ~SimpleCircle() {
        delete itsRadius; // 释放动态分配的内存
    }

    // 获取半径
    int getRadius() const {
        return *itsRadius;
    }

    // 设置半径
    void setRadius(int radius) {
        *itsRadius = radius;
    }

    // 计算面积
    double getArea() const {
        return PI * (*itsRadius) * (*itsRadius);
    }

    // 计算周长
    double getCircumference() const {
        return 2 * PI * (*itsRadius);
    }
};

int main() {
    SimpleCircle circle1(5);
    std::cout << "Circle1 radius: " << circle1.getRadius() << std::endl;
    std::cout << "Circle1 area: " << circle1.getArea() << std::endl;
    std::cout << "Circle1 circumference: " << circle1.getCircumference() << std::endl;

    SimpleCircle circle2 = circle1;
    std::cout << "Circle2 radius: " << circle2.getRadius() << std::endl;
    std::cout << "Circle2 area: " << circle2.getArea() << std::endl;

    return 0;
}