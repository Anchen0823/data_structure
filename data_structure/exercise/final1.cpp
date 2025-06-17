#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node() : data(0), next(nullptr) {}
    Node(int val) : data(val), next(nullptr) {}
};

void readList(Node*& head) {
    int num;
    while (cin >> num) {
        Node* newNode = new Node(num);
        if (!head) {
            head = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }

        if (cin.get() == '\n') {
            break; // Stop reading on newline
        }
    }
}

Node* mergeLists(Node*& l1, Node*& l2) {
    if (l1 == nullptr) return l2;
    if (l2 == nullptr) return l1;

    if (l1->data > l2->data) {
        l1->next = mergeLists(l1->next, l2);
        return l1;
    } else if (l1->data < l2->data) {
        l2->next = mergeLists(l1, l2->next);
        return l2;
    } else if (l1->data == l2->data) {
        l1->next = mergeLists(l1->next, l2->next);
        return l1;
    }

    return nullptr; // This line is never reached, but added to avoid warnings
}

int main() {
    Node* l1 = nullptr;
    Node* l2 = nullptr;

    readList(l1);
    readList(l2);

    Node* l3 = mergeLists(l1, l2);
    while (l3) {
        cout << l3->data << " ";
        l3 = l3->next;
    }
}