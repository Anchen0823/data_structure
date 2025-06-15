#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <clocale>
using namespace std;

// 选课记录节点
struct SCNode {
    int sno;        // 学号
    int cno;        // 课程号
    int grade;      // 成绩
    SCNode* next;   // 下一个节点指针
    SCNode(int s, int c, int g) : sno(s), cno(c), grade(g), next(nullptr) {}  // 构造函数
};

// 学生信息节点
struct StudentNode {
    int sno;            // 学号
    string sname;       // 学生姓名
    int age;            // 年龄
    StudentNode* next;  // 下一个节点指针
    StudentNode(int s, const string& name, int a) : sno(s), sname(name), age(a), next(nullptr) {}  // 构造函数
};

// 选课记录链表类
class SCList {
public:
    SCNode* head;   // 链表头指针
    SCNode* tail;    // 链表尾指针
    SCList() : head(nullptr), tail(nullptr) {}  // 构造函数
    
    // 添加选课记录
    void add(int s, int c, int g) {
        SCNode* node = new SCNode(s, c, g);  // 创建新节点
        if (!head) {  // 如果链表为空
            head = tail = node;  // 头尾指针都指向新节点
        } else {
            tail->next = node;  // 尾节点的next指向新节点
            tail = node;        // 更新尾指针为新节点（尾插法）
        }
    }
};

// 学生信息链表类
class StudentList {
public:
    StudentNode* head;  // 链表头指针
    StudentNode* tail;   // 链表尾指针
    StudentList() : head(nullptr), tail(nullptr) {}  // 构造函数
    
    // 添加学生信息
    void add(int s, const string& name, int a) {
        StudentNode* node = new StudentNode(s, name, a);  // 创建新节点
        if (!head) {  // 如果链表为空
            head = tail = node;  // 头尾指针都指向新节点
        } else {
            tail->next = node;  // 尾节点的next指向新节点
            tail = node;       // 更新尾指针为新节点（尾插法）
        }
    }
};

int main() {
    setlocale(LC_ALL, "");  // 设置本地化，处理中文输入

    ifstream infile("in.txt");  // 打开输入文件

    // 读取选课记录
    SCList scList;
    int m;  // 选课记录数量
    infile >> m;
    for (int i = 0; i < m; ++i) {
        int sno, cno, grade;
        infile >> sno >> cno >> grade;  // 读取学号、课程号、成绩
        scList.add(sno, cno, grade);    // 添加到选课链表
    }

    // 读取学生信息
    StudentList studentList;
    int n;  // 学生数量
    infile >> n;
    for (int i = 0; i < n; ++i) {
        int sno, age;
        string sname;
        infile >> sno >> sname >> age;  // 读取学号、姓名、年龄
        studentList.add(sno, sname, age);  // 添加到学生链表
    }
    infile.close();  // 关闭文件

    // 输入要查询的学生姓名
    string target;
    cin >> target;

    // 查找所有匹配该姓名的学生学号
    vector<int> targetSno;  // 存储匹配的学号（重名）
    StudentNode* stuCurr = studentList.head;
    while (stuCurr) {
        if (stuCurr->sname == target) {
            targetSno.push_back(stuCurr->sno);  // 将匹配的学号加入vector
        }
        stuCurr = stuCurr->next;
    }

    // 遍历选课记录，输出匹配学生的选课信息
    SCNode* scCurr = scList.head;
    while (scCurr) {
        int sno = scCurr->sno;
        for (int s : targetSno) {  // 检查当前选课记录是否属于目标学生
            if (s == sno) {
                cout << sno << " " << target << " " << scCurr->cno << " " << scCurr->grade << endl;
                break;
            }
        }
        scCurr = scCurr->next;
    }

    return 0;
}