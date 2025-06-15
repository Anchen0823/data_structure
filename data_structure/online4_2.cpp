#include <iostream>
#include <string>
using namespace std;

struct Node {
    int val;
    long long ts;
    Node* prev;
    Node* next;
    Node(int v, long long t) : val(v), ts(t), prev(nullptr), next(nullptr) {}
};

struct Stack {
    Node* head;
    Node* tail;
    int size;

    Stack() : head(nullptr), tail(nullptr), size(0) {}
};

long long timestamp = 0;

void push(Stack& s, int val) {
    Node* newNode = new Node(val, ++timestamp);
    if (s.tail == nullptr) {
        s.head = s.tail = newNode;
    } else {
        s.tail->next = newNode;
        newNode->prev = s.tail;
        s.tail = newNode;
    }
    s.size++;
}

int pop(Stack& s) {
    Node* tailNode = s.tail;
    int val = tailNode->val;
    if (s.size == 1) {
        s.head = s.tail = nullptr;
    } else {
        s.tail = tailNode->prev;
        s.tail->next = nullptr;
    }
    s.size--;
    delete tailNode;
    return val;
}

void merge(Stack& a, Stack& b) {
    if (b.size == 0) {
        return;
    }
    if (a.size == 0) {
        a.head = b.head;
        a.tail = b.tail;
        a.size = b.size;
        b.head = nullptr;
        b.tail = nullptr;
        b.size = 0;
        return;
    }

    Node* aCur = a.head;
    Node* bCur = b.head;
    Node dummy(0, 0);
    Node* cur = &dummy;

    while (aCur && bCur) {
        if (aCur->ts < bCur->ts) {
            cur->next = aCur;
            aCur->prev = cur;
            aCur = aCur->next;
        } else {
            cur->next = bCur;
            bCur->prev = cur;
            bCur = bCur->next;
        }
        cur = cur->next;
    }

    if (aCur) {
        cur->next = aCur;
        aCur->prev = cur;
    } else if (bCur) {
        cur->next = bCur;
        bCur->prev = cur;
    }

    a.head = dummy.next;
    a.head->prev = nullptr;

    a.tail = a.head;
    while (a.tail->next) {
        a.tail = a.tail->next;
    }

    a.size += b.size;
    b.head = nullptr;
    b.tail = nullptr;
    b.size = 0;
}

int main() {
    freopen("in.txt", "r", stdin);
    int n;
    while (cin >> n && n != 0) {
        timestamp = 0;
        Stack A, B;
        string op;
        for (int i = 0; i < n; ++i) {
            cin >> op;
            if (op == "push") {
                string s;
                int x;
                cin >> s >> x;
                if (s == "A") push(A, x);
                else push(B, x);
            } else if (op == "pop") {
                string s;
                cin >> s;
                int val;
                if (s == "A") val = pop(A);
                else val = pop(B);
                cout << val << endl;
            } else if (op == "merge") {
                string a, b;
                cin >> a >> b;
                Stack& sa = (a == "A") ? A : B;
                Stack& sb = (b == "A") ? A : B;
                merge(sa, sb);
            }
        }
    }
    return 0;
}