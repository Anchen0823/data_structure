#include <iostream>
using namespace std;

const int MAXSIZE = 100;

class Queue {
public:
    int data[MAXSIZE];
    int front;
    int rear;

    Queue() : front(-1), rear(-1) {}

    bool empty() {
        return front == rear;
    }

    bool full() {
        return rear >= MAXSIZE-1;
    }

    bool push(int e) {
        if (full()) return false;
        rear++;
        data[rear] = e;
        return true;
    }

    bool pop(int& e) {
        if (empty()) return false;
        front++;
        e = data[front];
        return true;
    }

    bool top(int& e) {
        if (empty()) return false;
        e = data[front+1];
        return true;
    }
};

int main() {
    Queue odds;
    Queue evens;

    int num, i = 1;
    while (cin >> num) {
        if (i%2 == 0) {
            evens.push(num);
        } else {
            odds.push(num);
        }
        i++;
    }

    while (evens.pop(num)) {
        cout << num << " ";
    }
    while (odds.pop(num)) {
        cout << num << " ";
    }
}