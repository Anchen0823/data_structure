#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class BigInteger {
private:
    vector<int> digits;  // 存储每一位数字
    bool isNegative;     // 是否为负数

public:
    // 构造函数：从字符串初始化
    BigInteger(const string& num) {
        isNegative = false;
        size_t start = 0;
        
        // 检查是否为负数
        if (num[0] == '-') {
            isNegative = true;
            start = 1;  // 跳过负号
        }
        
        // 将字符串中的数字字符转换为整数并存储
        for (size_t i = start; i < num.size(); ++i) {
            digits.push_back(num[i] - '0');
        }
    }

    // 构造函数：从 vector<int> 初始化
    BigInteger(const vector<int>& num, bool isNegative = false) : digits(num), isNegative(isNegative) {}

    // 取负运算符
    BigInteger operator-() const {
        return BigInteger(digits, !isNegative);
    }

    // 输出大数
    void print() const {
        if (isNegative) {
            cout << "-";
        }
        for (int digit : digits) {
            cout << digit;
        }
        cout << endl;
    }

    // 比较运算符重载
    bool operator>(const BigInteger& other) const {
        if (isNegative != other.isNegative) {
            return !isNegative;     // 符号不同时，正数大
        }
        if (digits.size() != other.digits.size()) {
            return (digits.size() > other.digits.size()) ^ isNegative;      // 位数不同时
        }
        for (size_t i = 0; i < digits.size(); ++i) {
            if (digits[i] != other.digits[i]) {
                return (digits[i] > other.digits[i]) ^ isNegative;      // 位数相同时，从高位到低位比较
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

    // 加法运算
    BigInteger operator+(const BigInteger& other) const {
        if (isNegative != other.isNegative) {
            // 如果符号不同，转换为减法
            if (isNegative) {
                return other - (-*this);
            } else {
                return *this - (-other);
            }
        }

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
        if (carry) {    // 处理最高位的进位
            result.push_back(carry);
        }
        reverse(result.begin(), result.end());
        return BigInteger(result, isNegative);
    }

    // 减法运算
    BigInteger operator-(const BigInteger& other) const {
        if (isNegative != other.isNegative) {
            // 如果符号不同，转换为加法
            return *this + (-other);
        }

        if (*this < other) {
            // 如果被减数小于减数，交换并标记结果为负数
            BigInteger result = other - *this;
            result.isNegative = true;
            return result;
        }

        vector<int> result;
        int borrow = 0;
        size_t i = digits.size();
        size_t j = other.digits.size();

        while (i > 0 || j > 0) {
            int digit1 = (i > 0) ? digits[--i] : 0;
            int digit2 = (j > 0) ? other.digits[--j] : 0;

            int diff = digit1 - digit2 - borrow;
            if (diff < 0) {
                diff += 10;
                borrow = 1;
            } else {
                borrow = 0;
            }
            result.push_back(diff);
        }

        // 移除前导零
        while (result.size() > 1 && result.back() == 0) {
            result.pop_back();
        }

        reverse(result.begin(), result.end());
        return BigInteger(result, isNegative);
    }

    // 乘法运算
    BigInteger operator*(const BigInteger& other) const {
        // 处理符号
        bool resultIsNegative = isNegative != other.isNegative;

        // 初始化结果数组
        vector<int> result(digits.size() + other.digits.size(), 0);

        // 逐位相乘
        for (int i = digits.size() - 1; i >= 0; --i) {
            for (int j = other.digits.size() - 1; j >= 0; --j) {
                int product = digits[i] * other.digits[j];
                int sum = product + result[i + j + 1];
                result[i + j + 1] = sum % 10;
                result[i + j] += sum / 10;
            }
        }

        // 移除前导零
        while (result.size() > 1 && result[0] == 0) {
            result.erase(result.begin());
        }

        return BigInteger(result, resultIsNegative);
    }
};

int main() {
    string a, b;
    cin >> a >> b;

    BigInteger num1(a);  // 从字符串初始化
    BigInteger num2(b);  // 从字符串初始化

    BigInteger result1 = num1 + num2;  
    result1.print();  // 输出加法结果

    //BigInteger result2 = num1 * num2;  
    //result2.print();  // 输出乘法结果

    return 0;
}