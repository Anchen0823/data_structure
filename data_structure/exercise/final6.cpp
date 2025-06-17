#include <iostream>
using namespace std;

const int MaxSize = 100;

class Queue {
public:
    int* data;
    int front, rear;

    Queue() {
        data = new int[MaxSize];
        front = rear = 0;
    }

    bool empty() {
        return front == rear;
    }

    bool full() {
        return (rear+1) % MaxSize == front;
    }

    bool push(int e) {
        if (full()) {
            return false;
        }
        rear = (rear+1) % MaxSize;
        data[rear] = e;
        return true;
    }

    bool pop(int& e) {
        if (empty()) {
            return false;
        }
        front = (front+1) % MaxSize;
        e = data[front];
        return true;
    }

    bool top(int& e) {
        if (empty()) {
            return false;
        }
        int head = (front+1) % MaxSize;
        e = data[head];
        return true;
    }
};

class Stack {
public:
    int* data;
    int top;

    Stack() {
        top = -1;
        data = new int[MaxSize];
    }

    bool empty() {
        return top == -1;
    }

    bool full() {
        return top == MaxSize-1;
    }

    bool push(int e) {
        if (full()) {
            return false;
        }
        top++;
        data[top] = e;
        return true;
    }

    bool pop(int& e) {
        if (empty()) {
            return false;
        }
        e = data[top];
        top--;
        return true;
    }

    bool getTop(int& e) {
        if (empty()) {
            return false;
        }
        e = data[top];
        return true;
    }
};

int main() {
    Queue q;
    Stack s;

    int n;
    cin >> n;
    int* pos = new int[n];
    int* non_neg1 = new int[n];

    int num;
    for (int i=0;i<n;i++) {
        cin >> num;
        q.push(num);
    }

    int i=0;
    while (q.pop(num)) {
        if (num == -1) {
            pos[i] = 1;
        } else {
            s.push(num);
        }
        i++;
    }

    i=0;
    while (s.pop(num)) {
        non_neg1[i] = num;
        i++;
    }

    int* result = new int[n];
    int non_ptr = 0;
    for (int i=0;i<n;i++) {
        if (pos[i] == 1) {
            result[i] = -1;
        } else {
            result[i] = non_neg1[non_ptr];
            non_ptr++;
        }
    }

    for (int i=0;i<n;i++) {
        cout << result[i] << " ";
    }
    return 0;
}