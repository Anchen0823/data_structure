#include <iostream>
#include <string>
using namespace std;

int main()
{
    string line;
    int cnt=0;
    getline(cin, line);
    for (char ch : line) {
        if (('a' <= ch && ch <= 'z') || ('A' <= ch && ch <= 'Z')) {
            cnt += 1;
        }
    }

    cout << "这个句子里有" << cnt << "个英文字母。";

    return 0;
}