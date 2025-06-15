#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class BigInteger {
private:
    vector<int> digits;  // 存储每一位数字

public:
    // 构造函数：从字符串初始化
    BigInteger(const string& num) {
        for (char ch : num) {
            digits.push_back(ch - '0');
        }
    }

    // 构造函数：从 vector<int> 初始化
    BigInteger(const vector<int>& num) : digits(num) {}

    // 加法运算
    BigInteger operator+(const BigInteger& other) const {
        vector<int> result;
        int carry = 0;
        size_t i = digits.size();
        size_t j = other.digits.size();

        while (i > 0 || j > 0) {
            int digit1 = (i > 0) ? digits[--i] : 0;
            int digit2 = (j > 0) ? other.digits[--j] : 0;

            int sum = digit1 + digit2 + carry;
            result.push_back(sum % 10);
            carry = sum / 10;
        }
        if (carry) {    //最高位有进位
            result.push_back(carry);
        }
        reverse(result.begin(), result.end());
        return BigInteger(result);
    }

    // 比较运算符重载
    bool operator>(const BigInteger& other) const {
        if (digits.size() != other.digits.size()) {
            return digits.size() > other.digits.size();
        }
        for (size_t i = 0; i < digits.size(); ++i) {
            if (digits[i] != other.digits[i]) {
                return digits[i] > other.digits[i];
            }
        }
        return false;  // 相等
    }

    bool operator<(const BigInteger& other) const {
        return other > *this;
    }

    bool operator>=(const BigInteger& other) const {
        return !(*this < other);
    }

    bool operator<=(const BigInteger& other) const {
        return !(*this > other);
    }

    bool operator==(const BigInteger& other) const {
        return digits == other.digits;
    }

    bool operator!=(const BigInteger& other) const {
        return !(*this == other);
    }

    // 输出大数
    void print() const {
        for (int digit : digits) {
            cout << digit;
        }
        cout << endl;
    }
};

int main() {
    string a, b;
    cin >> a >> b;

    BigInteger num1(a);  // 从字符串初始化
    BigInteger num2(b);  // 从字符串初始化

    BigInteger result = num1 + num2;  // 使用加法运算符
    result.print();  // 输出结果

    return 0;
}