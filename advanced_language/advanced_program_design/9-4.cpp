/*  在双向链表中，每个节点不仅包含指向下一个节点的指针，还包含指向前一个节点的指针。
    相比之下，在单链表中，每个节点只包含指向下一个节点的指针。
    因此主要的不同在于 DNode 需要额外一个指针来指向前一个节点。
*/
#include <iostream>
class DNode {
public:
    int data;           // 节点存储的数据
    DNode* next;        // 指向下一个节点的指针
    DNode* prev;        // 指向前一个节点的指针

    // 构造函数
    DNode(int val = 0) : data(val), next(nullptr), prev(nullptr) {}

    // 打印节点信息
    void print() const {
        std::cout << "DNode(data=" << data << ")";
        if (next) {
            std::cout << " -> ";
            next->print(); // 递归打印下一个节点
        } else {
            std::cout << std::endl;
        }
    }
};

// 测试
int main() {
    DNode* node1 = new DNode(1);
    DNode* node2 = new DNode(2);
    DNode* node3 = new DNode(3);

    node1->next = node2;
    node2->prev = node1;
    node2->next = node3;
    node3->prev = node2;

    node1->print();

    delete node3;
    delete node2;
    delete node1;

    return 0;
}