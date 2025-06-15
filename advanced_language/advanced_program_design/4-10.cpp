#include <iostream>
#include <string>

using namespace std;

class Date {
public:
    int year;
    int month;
    int day;

    // 构造函数
    Date(int y = 2024, int m = 1, int d = 1) : year(y), month(m), day(d) {}

    // 复制构造函数
    Date(const Date& other) : year(other.year), month(other.month), day(other.day) {}

    void display() const{
        cout << year << "-" << month << "-" << day; 
    }
};

class Person {
public:
    // 构造函数
    Person(int id = 0, const string& gender = "Unknown", const Date& birthDate=Date(), const string& idCardNumber = " ")
        : id(id), gender(gender), birthDate(birthDate), idCardNumber(idCardNumber) {}

    // 析构函数
    ~Person() {
        cout << "Person " << id << " is fired!\n";
    }

    // 复制构造函数
    Person(const Person& other)
        : id(other.id), gender(other.gender), birthDate(other.birthDate), idCardNumber(other.idCardNumber) {}
    
    // 内联成员函数
    inline int getId() const {return id;}
    inline const string& getGender() const {return gender;}
    inline const Date& getBirthDate() const {return birthDate;}
    inline const string& getIdCardNumber() const {return idCardNumber;}

    // 带默认形参值的成员函数
    void setIdCardNumber(const string& idCardNumber = "") {
        this->idCardNumber = idCardNumber;
    }

    void display() const {
        cout << "ID: " << id << endl;
        cout << "Gender: " << gender << endl;
        cout <<  "Birth Date: ";
        birthDate.display();
        cout << endl;
        cout << "ID Card Number: " << idCardNumber << endl;
    }

    void input() {
        cout << "Enter ID: ";
        cin >> id;
        cout << "Entere Gender: ";
        cin >> gender;
        cout << "Enter Birth Date (year month day): ";
        int year, month, day;
        cin >> year >> month >> day;
        birthDate = Date(year, month, day);
        cout << "Enter ID Card Number: ";
        cin >> idCardNumber;
    }

private:
    int id;
    string gender;
    Date birthDate;
    string idCardNumber;
};

int main() {
    Person xyx;
    xyx.input();
    xyx.display();

    Person sxy = xyx;
    sxy.display();

    sxy.setIdCardNumber("123456");
    sxy.display();

    return 0;
}