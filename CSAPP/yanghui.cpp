#include <iostream>
#include <iomanip>
#include <sstream>
using namespace std;

// 队列节点结构
struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

// 自定义队列类
class Queue {
private:
    Node* front;
    Node* rear;

    // 清空队列
    void clear() {
        while (!isEmpty()) {
            dequeue();
        }
    }

public:
    Queue() : front(nullptr), rear(nullptr) {}
    
    // 拷贝构造函数（深拷贝）
    Queue(const Queue& other) : front(nullptr), rear(nullptr) {
        Node* current = other.front;
        while (current != nullptr) {
            enqueue(current->data);
            current = current->next;
        }
    }

    // 析构函数
    ~Queue() {
        clear();
    }

    // 赋值运算符（深拷贝）
    Queue& operator=(const Queue& other) {
        if (this != &other) {
            clear();
            Node* current = other.front;
            while (current != nullptr) {
                enqueue(current->data);
                current = current->next;
            }
        }
        return *this;
    }

    // 入队
    void enqueue(int val) {
        Node* newNode = new Node(val);
        if (rear == nullptr) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    // 出队
    int dequeue() {
        if (isEmpty()) {
            cerr << "Error: Dequeue from empty queue!" << endl;
            exit(1);
        }
        Node* temp = front;
        int val = temp->data;
        front = front->next;
        if (front == nullptr) {
            rear = nullptr;
        }
        delete temp;
        return val;
    }

    // 判断队列是否为空
    bool isEmpty() const {
        return front == nullptr;
    }
};

// 打印队列元素并居中显示
void printQueueCentered(Queue& q, int n, int currentRow) {
    Queue temp;
    stringstream ss;
    bool firstElement = true;

    // 构建当前行的字符串
    while (!q.isEmpty()) {
        int num = q.dequeue();
        temp.enqueue(num);
        if (!firstElement) {
            ss << "  ";
        } else {
            firstElement = false;
        }
        ss << setw(4) << num;
    }

    // 恢复原队列数据
    while (!temp.isEmpty()) {
        q.enqueue(temp.dequeue());
    }

    // 计算并添加前导空格
    string leadingSpaces(3 * (n - currentRow), ' ');
    cout << leadingSpaces << ss.str() << endl;
}

int main() {
    int n;
    cout << "Enter the order of Pascal's triangle: ";
    cin >> n;

    Queue q;
    q.enqueue(1);
    printQueueCentered(q, n, 1);

    for (int row = 2; row <= n; row++) {
        q.enqueue(0); // 添加0以辅助生成下一行
        Queue newQueue;
        int prev = 0;

        for (int i = 0; i < row; i++) {
            int current = q.dequeue();
            int sum = prev + current;
            newQueue.enqueue(sum);
            prev = current;
        }

        q = newQueue; // 更新队列为当前行
        printQueueCentered(q, n, row);
    }

    return 0;
}

/*
#include <iostream>
using namespace std;

const int MAX_SIZE = 1000;  // 假设字符串最大长度为1000

class SeqStack {
private:
    int top;          // 栈顶指针
    char data[MAX_SIZE];  // 存储字符的数组
public:
    SeqStack() : top(-1) {}
    bool IsEmpty() { return top == -1; }
    bool IsFull() { return top == MAX_SIZE - 1; }
    void Push(char c) {
        if (IsFull()) {
            cout << "栈满，无法入栈！" << endl;
            exit(0);
        }
        data[++top] = c;
    }
    char Pop() {
        if (IsEmpty()) {
            cout << "栈空，无法出栈！" << endl;
            exit(0);
        }
        return data[top--];
    }
};

bool CheckFormat(char* str) {
    SeqStack stack;
    bool hasAt = false;  // 标记是否遇到@
    int i = 0;

    // 将@前的字符压入栈
    while (str[i] != '\0') {
        if (str[i] == '@') {
            if (hasAt) return false;  // 存在多个@，直接返回false
            hasAt = true;
            i++;
            break;
        }
        stack.Push(str[i]);
        i++;
    }

    // 检查@是否存在且不在首尾
    if (!hasAt || stack.IsEmpty() || str[i] == '\0') return false;

    // 比较@后的字符与栈中逆序
    while (str[i] != '\0') {
        if (stack.IsEmpty()) return false;  // 栈空但还有字符未比较
        char c = stack.Pop();
        if (c != str[i]) return false;
        i++;
    }

    return stack.IsEmpty();  // 栈必须为空（序列2长度等于序列1）
}
*/

/*
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class LinkedStack {
private:
    Node* top;
public:
    LinkedStack() : top(nullptr) {}
    ~LinkedStack() {
        while (!isEmpty()) {
            pop();
        }
    }
    // 入栈操作
    void push(int val) {
        Node* newNode = new Node(val);
        newNode->next = top;
        top = newNode;
    }
    // 普通出栈操作
    bool pop() {
        if (isEmpty()) return false;
        Node* temp = top;
        top = top->next;
        delete temp;
        return true;
    }
    // 判断栈是否为空
    bool isEmpty() {
        return top == nullptr;
    }
    // 出栈第k个节点
    bool popKth(int k) {
        if (k < 1 || isEmpty()) return false;
        if (k == 1) { // 处理栈顶元素
            Node* temp = top;
            top = top->next;
            delete temp;
            return true;
        }
        Node* prev = top;
        int count = 1;
        // 遍历找到第k-1个节点
        while (count < k - 1 && prev != nullptr) {
            prev = prev->next;
            count++;
        }
        // 检查是否存在第k个节点
        if (prev == nullptr || prev->next == nullptr) {
            return false;
        }
        Node* temp = prev->next;
        prev->next = temp->next;
        delete temp;
        return true;
    }
    // 显示栈内容（栈顶到栈底）
    void display() {
        Node* current = top;
        while (current != nullptr) {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedStack st;
    int n, val;
    cout << "输入元素个数：";
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cout << "输入元素 " << i + 1 << ": ";
        cin >> val;
        st.push(val);
    }
    cout << "链栈内容（栈顶到栈底）: ";
    st.display();
    
    int k;
    cout << "输入要出栈的第k个节点：";
    cin >> k;
    bool success = st.popKth(k);
    if (success) {
        cout << "出栈成功。链栈当前内容：";
        st.display();
    } else {
        cout << "出栈失败，k无效或栈为空。" << endl;
    }
    return 0;
}
*/

/*
#include <iostream>

struct Queue {
    int* data;
    int front;
    int rear;
    int capacity;
};

void initQueue(Queue* q, int size) {
    q->data = new int[size];
    q->front = 0;
    q->rear = 0;
    q->capacity = size;
}

void enqueue(Queue* q, int val) {
    if (q->rear < q->capacity) {
        q->data[q->rear++] = val;
    }
}

int dequeue(Queue* q) {
    if (q->front < q->rear) {
        return q->data[q->front++];
    }
    return -1; // 此处简略处理，实际应用中应处理队列为空的情况
}

bool isEmpty(Queue* q) {
    return q->front == q->rear;
}

void reorderArray(int a[], int n) {
    Queue qOdd, qEven;
    initQueue(&qOdd, n);
    initQueue(&qEven, n);

    // 将奇数和偶数位置的元素分别入队
    for (int i = 0; i < n; ++i) {
        if (i % 2 == 0) { // 奇数位（0, 2, 4...）
            enqueue(&qOdd, a[i]);
        } else { // 偶数位（1, 3, 5...）
            enqueue(&qEven, a[i]);
        }
    }

    // 先出队奇数队列的元素，再出队偶数队列的元素
    int idx = 0;
    while (!isEmpty(&qOdd)) {
        a[idx++] = dequeue(&qOdd);
    }
    while (!isEmpty(&qEven)) {
        a[idx++] = dequeue(&qEven);
    }

    // 释放队列内存
    delete[] qOdd.data;
    delete[] qEven.data;
}

// 示例测试
int main() {
    int a[] = {1, 2, 3, 4, 5, 6};
    int n = sizeof(a) / sizeof(a[0]);
    reorderArray(a, n);
    for (int i = 0; i < n; ++i) {
        std::cout << a[i] << " ";
    }
    std::cout << std::endl; // 输出: 1 3 5 2 4 6 

    int b[] = {4, 5, 6, 7, 8, 9};
    reorderArray(b, 6);
    for (int i = 0; i < 6; ++i) {
        std::cout << b[i] << " ";
    }
    std::cout << std::endl; // 输出: 4 6 8 5 7 9 

    return 0;
}
*/