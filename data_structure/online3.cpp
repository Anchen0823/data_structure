#include <iostream>
#include <fstream>
using namespace std;

int sum(int *p, int n) {
    int s = 0;
    while (n--) {
        s += *p;
        p += 1;
    }
  
    return s;
  }

int main() {
    int beds;
    string sequence;

    ifstream infile("in.txt");
    while (infile >> beds >> sequence) {
        int loss = 0;
        int currentClients[26] = {0};
        for (char ch : sequence) {
            int index = ch - 'A';
            if (currentClients[index] == 0) {   //到达
                if (sum(currentClients, 26) < beds) {   //入住
                    currentClients[index] = 1;
                }
                else {  //床不够
                    currentClients[index] = 1;
                    loss += 1;
                }
            }
            else {  //离开
                currentClients[index] = 0;
            }
        }

        if (loss == 0) {
            cout << "All customers tanned successfully." << endl;
        } 
        else {
            cout << loss << " customer(s) walked away." << endl;
        }
    }
    return 0;
}