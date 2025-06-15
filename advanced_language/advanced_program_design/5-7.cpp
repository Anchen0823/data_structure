#include <iostream>
using namespace std;

class Cat{
public:
    Cat() {numOfCats++;};
    static int getNumOfCats() {return numOfCats;}
private:
    static int numOfCats;
};

int Cat::numOfCats = 0;

int main() {
    cout << Cat::getNumOfCats() << endl;

    Cat();
    cout << Cat::getNumOfCats() << endl;

    return 0;
}