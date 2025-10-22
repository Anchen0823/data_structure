#include <iostream>
using namespace std;

bool cond(bool p, bool q) {
    return (!p || q);
}

bool d_cont(bool p, bool q) {
    return cond(p, q) && cond(q,p);
}

int main() {
    bool res = 0;
    for (int p=0;p<2;p++) {
        for (int q=0;q<2;q++) {
            bool t1 = !(p && q);
            bool t2 = !p || !q;
            res = d_cont(t1, t2);
            cout << res << endl;
        }
    }
}