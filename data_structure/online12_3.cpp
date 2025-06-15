#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

bool isTarget(vector<string> codes) {
    for (int i = 0; i < codes.size(); i++) {
        for (int j = 0; j < codes.size(); j++) {
            // Skip comparing a code with itself
            if (i == j) continue;
            
            // Check if codes[i] is a prefix of codes[j]
            if (codes[j].size() >= codes[i].size() && 
                codes[j].substr(0, codes[i].size()) == codes[i]) {
                return false;
            }
        }
    }
    return true;
}

int main() {
    freopen("in.txt", "r", stdin);

    string code;
    vector<string> codes;

    while (true) {
        getline(cin, code);
        if (code == "9") {
            break;
        }
        codes.push_back(code);
    }

    if (isTarget(codes)) {
        cout << "Y";
    } else {
        cout << "N";
    }
    cout << endl;

    return 0;
}