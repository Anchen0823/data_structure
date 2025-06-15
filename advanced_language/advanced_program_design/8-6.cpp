#include <iostream>
#include <cmath>

const double pi = 3.1415926;

// 定义抽象类 Shape
class Shape {
public:
    virtual ~Shape() = default; // 虚析构函数

    // 纯虚函数，需要在派生类中实现
    virtual double getArea() const = 0;
    virtual double getPerim() const = 0;
};

// 定义 Rectangle 类，继承自 Shape
class Rectangle : public Shape {
private:
    double width;
    double height;

public:
    Rectangle(double w, double h) : width(w), height(h) {}

    double getArea() const override {
        return width * height;
    }

    double getPerim() const override {
        return 2 * (width + height);
    }
};

// 定义 Circle 类，继承自 Shape
class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    double getArea() const override {
        return pi * radius * radius;
    }

    double getPerim() const override {
        return 2 * pi * radius;
    }
};

int main() {
    Shape* rectangle = new Rectangle(5.0, 3.0);
    Shape* circle = new Circle(2.0);

    std::cout << "Rectangle Area: " << rectangle->getArea() << std::endl;
    std::cout << "Rectangle Perimeter: " << rectangle->getPerim() << std::endl;

    std::cout << "Circle Area: " << circle->getArea() << std::endl;
    std::cout << "Circle Perimeter: " << circle->getPerim() << std::endl;

    delete rectangle;
    delete circle;

    return 0;
}