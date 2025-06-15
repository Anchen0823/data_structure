#include <iostream>
#include <list>

template <class T>
void exchange(std::list<T>& l1, typename std::list<T>::iterator pl,
              std::list<T>& l2, typename std::list<T>::iterator p2) {
    // 获取区间 [pl, l1.end()) 和 [p2, l2.end()) 中的元素
    std::list<T> temp1(pl, l1.end());
    std::list<T> temp2(p2, l2.end());

    // 清空原区间内容
    l1.erase(pl, l1.end());
    l2.erase(p2, l2.end());

    // 将交换的元素插入到对方链表的末尾
    l1.insert(l1.end(), temp2.begin(), temp2.end());
    l2.insert(l2.end(), temp1.begin(), temp1.end());
}

int main() {
    // 创建两个示例链表
    std::list<int> list1 = {1, 2, 3, 4, 5};
    std::list<int> list2 = {6, 7, 8, 9, 10};

    // 打印原始链表
    std::cout << "Original list1: ";
    for (int num : list1) {
        std::cout << num << " ";
    }
    std::cout << "\nOriginal list2: ";
    for (int num : list2) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    // 交换 list1[pl, end()) 和 list2[p2, end()) 区间的内容
    auto pl = list1.begin();
    std::advance(pl, 2);  // 设置 pl 为 list1 第 3 个元素（值为 3）
    
    auto p2 = list2.begin();
    std::advance(p2, 1);  // 设置 p2 为 list2 第 2 个元素（值为 7）

    // 调用 exchange 函数模板进行交换
    exchange(list1, pl, list2, p2);

    // 打印交换后的链表
    std::cout << "After exchange list1: ";
    for (int num : list1) {
        std::cout << num << " ";
    }
    std::cout << "\nAfter exchange list2: ";
    for (int num : list2) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}