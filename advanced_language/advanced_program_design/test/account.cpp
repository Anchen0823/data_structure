#include "account.h"

#include <cmath>
#include <cstdio>
#include <iomanip>
#include <iostream>
using namespace std;
double SavingsAccount::total = 0;

void SavingsAccount::record(int date, double amount) {
    // 重点：观察输出，amount总保留至小数点后两位
    // 对于浮点类型变量 s，其舍入至N位的公式为
    // s = floor(s*(10^N)+0.5）/ (10^N)
    // 10^N表示10的N次方
    amount = floor(amount * 100 + 0.5) / 100;
    cout << date << " #" << id << " " << amount << " " << balance << endl;
}

SavingsAccount::SavingsAccount(int date, int id, double rate):balance(0), accumulation(0) {
    this->lastDate = date;
    this->id = id;
    this->rate = rate;
    // 注意这里需要换行
    printf("%d #%d is created\n", date, id);
}

void SavingsAccount::deposit(int date, double amount) {
    accumulation = accumulate(date);
    this->lastDate = date;
    this->balance += amount;
    total += amount;
    record(date, amount);
}

void SavingsAccount::withdraw(int date, double amount) {
    accumulation = accumulate(date);
    this->lastDate = date;
    this->balance -= amount;
    total -= amount;
    record(date, -amount);
}

void SavingsAccount::settle(int date) {
    double s = accumulate(date) / 365 * rate;
    this->lastDate = date;
    this->balance += s;
    total += s;
    record(date, s);
}

void SavingsAccount::show() const {
    // 注意这里main里有换行，所以我们不需要换行
    cout << "#" << id << " Balance:" << balance;
}