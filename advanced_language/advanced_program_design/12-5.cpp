#include <iostream>
#include <new> // 包含 std::bad_alloc

int main() {
    try {
        // 尝试导致内存分配失败
        int* largeArray = new int[1000000000000];

        // 如果内存分配成功，这里会做一些事情
        // ...

        delete[] largeArray;
    } catch (const std::bad_alloc& e) {
        // 捕获内存分配失败的异常
        std::cerr << "Memory allocation failed: " << e.what() << std::endl;
    }

    // 程序继续执行
    std::cout << "Program continues after handling potential memory allocation failure." << std::endl;

    return 0;
}