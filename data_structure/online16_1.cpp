#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

struct LinkNode {
    int data;
    LinkNode* next;

    LinkNode() : data(0), next(nullptr) {}
    LinkNode(int x) : data(x), next(nullptr) {}
};

LinkNode* buildLink(vector<int>& nums) {
    LinkNode* head = nullptr;
    LinkNode* tail = nullptr;
    for (int num : nums) {
        LinkNode* newNode = new LinkNode(num);
        if (!head) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    return head;
}

LinkNode* merge(LinkNode* left, LinkNode* right) {
    LinkNode* dummy = new LinkNode();
    LinkNode* tail = dummy;

    while (left && right) {
        if (left->data < right->data) {
            tail->next = left;
            tail = tail->next;
            left = left->next;
        } else {
            tail->next = right;
            tail = tail->next;
            right = right->next;
        }
    }

    tail->next = left ? left : right;
    return dummy->next;
}

LinkNode* merge_sort(LinkNode* head) {
    if (!head || !head->next) return head;
    
    LinkNode* slow = head;
    LinkNode* fast = head->next;

    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    LinkNode* mid = slow->next;
    slow->next = nullptr;

    LinkNode* left = merge_sort(head);
    LinkNode* right = merge_sort(mid);

    return merge(left, right);
}

int main() {
    freopen("in.txt", "r", stdin);
    ofstream file("out.txt");
    vector<int> nums;
    int num;
    while (cin >> num) {
        nums.push_back(num);
    }
    LinkNode* head = buildLink(nums);
    head = merge_sort(head);

    LinkNode* curr = head;
    while (curr) {
        file << curr->data << " ";
        curr = curr->next;
    }
    return 0;
}