#include <iostream>
#include <vector>
using namespace std;

// 循环队列类
class CircularQueue {
private:
    int* arr;       // 存储队列元素的数组
    int front;      // 队头指针
    int rear;       // 队尾指针
    int capacity;   // 队列容量

public:
    // 构造函数，初始化队列
    CircularQueue(int size) {
        capacity = size + 1; // 多分配一个空间用于区分队列满和空的情况
        arr = new int[capacity];
        front = 0;
        rear = 0;
    }

    // 判断队列是否为空
    bool isEmpty() {
        return front == rear;
    }

    // 判断队列是否已满
    bool isFull() {
        return (rear + 1) % capacity == front;
    }

    // 入队操作
    void enqueue(int value) {
        if (isFull()) {
            return;
        }
        arr[rear] = value;
        rear = (rear + 1) % capacity; // 循环移动队尾指针
    }

    // 出队操作
    int dequeue() {
        if (isEmpty()) {
            return -1; // 队列为空时返回-1
        }
        int value = arr[front];
        front = (front + 1) % capacity; // 循环移动队头指针
        return value;
    }

    // 获取队头元素
    int getFront() {
        if (isEmpty()) {
            return -1;
        }
        return arr[front];
    }

    // 旋转队列steps次（每次将队头元素移到队尾）
    void rotate(int steps) {
        for (int i = 0; i < steps; ++i) {
            int value = dequeue();      // 出队一个元素
            enqueue(value);             // 将出队元素重新入队（相当于移到队尾）
        }
    }
};

// 根据翻牌规则找出初始牌序
vector<int> find_initial_order(int n) {
    CircularQueue queue(n);
    
    // 逆向模拟翻牌过程：
    // 从最后一步（n）开始，倒序处理每一步
    for (int i = n; i >= 1; --i) {
        queue.enqueue(i);   // 将当前牌i入队
        queue.rotate(i);    // 旋转队列i次（模拟逆向翻牌过程）
    }

    // 将队列中的元素存入结果向量
    vector<int> result;
    while (!queue.isEmpty()) {
        result.push_back(queue.dequeue());
    }
    return result;
}

int main() {
    int m;
    cin >> m; // 输入测试用例数量
    while (m--) {
        int n;
        cin >> n; // 输入纸牌数量n
        vector<int> initial_order = find_initial_order(n); // 获取初始牌序
        
        // 倒序输出（因为队列模拟时是逆向处理，需要反转）
        for (int i = initial_order.size() - 1; i >= 0; --i) {
            if (i < initial_order.size() - 1) cout << " "; // 控制空格输出
            cout << initial_order[i];
        }
        cout << endl;
    }
    return 0;
}