#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Student {
public:
    int id;         // 学号
    int chinese;    // 语文
    int math;       // 数学
    int english;    // 英语
    int physics;    // 物理
    int chemistry;  // 化学
    int biology;    // 生物
    int total;      // 总分
	bool isValid;
    Student (int id, int chinese, int math, int english, int physics, int chemistry, int biology, bool isValid) {
		this->id = id;
		this->chinese = chinese;
		this->math = math;
		this->english = english;
		this->physics = physics;
		this->chemistry = chemistry;
		this->biology = biology;
		this->total = chinese + math + english + physics + chemistry + biology;

		if (chinese < 0 || chinese > 150 || math < 0 || math > 150 || english < 0 || english > 150 || physics < 0 || physics > 100 || chemistry < 0 || chemistry > 100 || biology < 0 || biology > 100) 
			this->isValid = false;
		else this->isValid = true;
	}
};

bool compare(const Student& a, const Student& b, int sortType) {
	if (!a.isValid && !b.isValid) return true;
	else if (a.isValid && !b.isValid) return true;
	else if (!a.isValid && b.isValid) return false;
	else if (sortType == 1) {
		return a.id < b.id;
	}
	else if (sortType == 2) {
		return a.total > b.total;
	}
}

int main() {
	int n;
	cin >> n;

	vector<Student> students;
	for (int i = 0; i < n; i++) {
		int id, chinese, math, english, physics, chemistry, biology;
		cin >> id >> chinese >> math >> english >> physics >> chemistry >> biology;
		students.push_back(Student(id, chinese, math, english, physics, chemistry, biology, true));
	}

	int sortType;
	cin >> sortType;

	sort(students.begin(), students.end(), [sortType](const Student& a, const Student& b) {
		return compare(a, b, sortType);
		});
	for (const auto& student : students) {
		cout << student.id << ": " << student.chinese << " " << student.math << " " << student.english << " " << student.physics << " " << student.chemistry << " " << student.biology << " ";
	if (student.isValid) {
		cout << student.total;
	} else cout << "invalid";
	cout << endl;
	}
}
