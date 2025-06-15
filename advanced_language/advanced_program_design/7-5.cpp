#include <iostream>
#include <cmath>

const double pi = 3.1415926;

// 定义基类 Shape
class Shape {
public:
    virtual ~Shape() = default;
    virtual double getArea() const = 0;
};

// 定义派生类 Rectangle
class Rectangle : public Shape {
private:
    double width;
    double height;

public:
    Rectangle(double w, double h) : width(w), height(h) {}

    double getArea() const override {
        return width * height;
    }
};

// 定义派生类 Circle
class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    double getArea() const override {
        return pi * radius * radius;
    }
};

// 定义派生自 Rectangle 的 Square 类
class Square : public Rectangle {
public:
    Square(double s) : Rectangle(s, s) {}
};

int main() {
    Shape* shapes[] = {
        new Rectangle(4, 5),
        new Circle(3),
        new Square(6)
    };

    // 计算并打印每个形状的面积
    for (const auto& shape : shapes) {
        std::cout << "Area: " << shape->getArea() << std::endl;
        delete shape; // 释放内存
    }

    return 0;
}