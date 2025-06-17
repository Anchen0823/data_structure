#include <iostream>
using namespace std;

const int MaxSize = 100;

class Stack {
public:
    int top;
    int* data;

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
        cout << "in" << " ";
        return true;
    }

    bool pop(int& e) {
        if (empty()) {
            return false;
        }
        e = data[top];
        top--;
        cout << "out" << " ";
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
    Stack s;
    int n; 
    cin >> n;

    int num;
    int* result = new int[n];
    int j = 0;
    for (int i=0;i<n;i++) {
        cin >> num;
        if (num%2 != 0) { //odd
            s.push(num);
            s.pop(num);
            result[j] = num;
            j++;
        } else {
            s.push(num);
        }
    }
    while (s.pop(num)) {
        result[j] = num;
        j++;
    }

    cout << endl;
    for (int i=0;i<n;i++) {
        cout << result[i] << " ";
    }
}