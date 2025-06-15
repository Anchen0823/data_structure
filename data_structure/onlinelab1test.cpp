#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <clocale>
using namespace std;

struct SCNode {
    int sno;
    int cno;
    int grade;
    SCNode* next;
    SCNode(int s, int c, int g) : sno(s), cno(c), grade(g), next(nullptr) {}
};

struct StudentNode {
    int sno;
    string sname;
    int age;
    StudentNode* next;
    StudentNode(int s, const string& name, int a) : sno(s), sname(name), age(a), next(nullptr) {}
};

class SCList {
public:
    SCNode* head;
    SCNode* tail;
    SCList() : head(nullptr), tail(nullptr) {}
    void add(int s, int c, int g) {
        SCNode* node = new SCNode(s, c, g);
        if (!head) {
            head = tail = node;
        } else {
            tail->next = node;
            tail = node;        //尾插法
        }
    }
};

class StudentList {
public:
    StudentNode* head;
    StudentNode* tail;
    StudentList() : head(nullptr), tail(nullptr) {}
    void add(int s, const string& name, int a) {
        StudentNode* node = new StudentNode(s, name, a);
        if (!head) {
            head = tail = node;
        } else {
            tail->next = node;
            tail = node;        //尾插法
        }
    }
};

int main() {
    setlocale(LC_ALL, "");      //处理中文输入

    ifstream infile("in.txt");

    SCList scList;
    int m;
    infile >> m;
    for (int i = 0; i < m; ++i) {
        int sno, cno, grade;
        infile >> sno >> cno >> grade;
        scList.add(sno, cno, grade);
    }

    StudentList studentList;
    int n;
    infile >> n;
    for (int i = 0; i < n; ++i) {
        int sno, age;
        string sname;
        infile >> sno >> sname >> age;
        studentList.add(sno, sname, age);
    }
    infile.close();

    string target;
    cin >> target;

    vector<int> targetSno;      //防止重名
    StudentNode* stuCurr = studentList.head;
    while (stuCurr) {
        if (stuCurr->sname == target) {
            targetSno.push_back(stuCurr->sno);
        }
        stuCurr = stuCurr->next;
    }

    SCNode* scCurr = scList.head;
    while (scCurr) {
        int sno = scCurr->sno;
        for (int s : targetSno) {
            if (s == sno) {
                cout << sno << " " << target << " " << scCurr->cno << " " << scCurr->grade << endl;
                break;
            }
        }
        scCurr = scCurr->next;
    }

    return 0;
}