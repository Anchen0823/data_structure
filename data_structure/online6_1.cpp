#include <iostream>
#include <string>
#include <fstream>
#include <stack>
using namespace std;

int main() {
    freopen("in.txt", "r", stdin);
    string result = "";
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);

    int len1 = s1.size();
    int len2 = s2.size();
    int len = min(len1, len2);

    int cnt = len;
    while (cnt) {
        bool flag = true;
        for (int i=0;i<cnt;i++) {   //检测长度为cnt的ss
            char e1 = s1[i];
            char e2 = s2[len2-cnt+i];
            if (e1 != e2) {flag = false;break;}
        }
        if (flag) {
            for (int i=0;i<cnt;i++) {
                result += s1[i];
            }
            break;
        }
        cnt--;
    }

    if (cnt == 0) {cout << 0;}
    else {
        cout << result << " " << cnt;
    }
    return 0;
}