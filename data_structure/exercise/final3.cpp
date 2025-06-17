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

    bool empty() {return head->next == nullptr;}

    bool push(int e) {
        Node* p = new Node(e);
        if (empty()) {
            head->next = p;
            return true;}
        p->next = head->next;
        head->next = p;
        return true;
    }
    
    bool pop(int& e) {
        Node* p;
        if (empty()) {
            return false;
        }
        p = head->next;
        e = p->data;
        head->next = p->next;
        delete p;
        return true;
    }

    bool top(int& e) {
        Node* p;
        if (empty()) {
            return false;
        }
        p = head->next;
        e = p->data;
        delete p;
        return true;
    }
};

int main() {
    int n;
    cin >> n;

    int num;
    LinkStack s, temp;
    for (int i=0;i<n;i++) {
        cin >> num;
        s.push(num);
    }

    int k;
    cin >> k;
    if (k <= 0 || k > n) {
        cout << "error" << endl;
        while (s.pop(num)) {
            temp.push(num);
        }

    } else { // k合法
        int i=0;
        while (s.pop(num)) {
            if (i != n-k) {
                temp.push(num);
            } else {
                cout << num << endl;
            }
            i++;
        }
    }
    while (temp.pop(num)) {
        cout << num << " ";
    }
    
    return 0;
}