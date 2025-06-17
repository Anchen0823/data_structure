#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
    Node() : data(0), next(nullptr) {}
    Node(int d) : data(d), next(nullptr) {}
};

class LinkStack {
public:
    Node* head;

    LinkStack() {
        head = new Node();
    }

    bool empty() {
        return head->next == nullptr;
    }

    bool push(int e) {
        Node* newNode = new Node(e);
        newNode->next = head->next;
        head->next = newNode;
        return true;
    }

    bool pop(int& e) {
        Node* p;
        if (empty()) return false;

        p = head->next;
        e = p->data;
        head->next = p->next;
        delete p;
        return true;
    }

    bool top(int& e) {
        if (empty()) return false;
        e = head->next->data;
        return true;
    }
};

int main() {
    int n;
    cin >> n;

    LinkStack s;
    LinkStack temp;
    LinkStack evens;
    int num;

    for (int i=0;i<n;i++) {
        cin >> num;
        s.push(num);
    }

    while (s.pop(num)) {
        if (num % 2 == 0) {
            evens.push(num);
        } else {
            temp.push(num);
        }
    }

    while (evens.pop(num)) {
        cout << num << " "; 
    }
    cout << endl;

    while (temp.pop(num)) {
        cout << num << " "; 
    }

    return 0;
}