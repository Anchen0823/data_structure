#include <iostream>
using namespace std;
class CPU {
public:
    CPU(uint16_t freq, bool is64bit, uint8_t cores, bool ht)
        : clockFrequency(freq), wordSize(is64bit), coreCount((cores == 1) ? 0 : ((cores==2) ? 1 : 2)), hyperThreading(ht) {}
    
    void printInfo() const {
        cout << "CPU Clock Frequency: " << clockFrequency << " MHz" << endl;
        cout << "Word Size: " << (wordSize ? 64 : 32) << "-bit" << endl;
        cout << "Core Count: ";
        switch (coreCount)
        {
        case 0: cout << "1 Core"; break;
        case 1: cout << "2 Cores"; break;
        case 2: cout << "4 cores"; break;
        default:cout << "Unknown Core Count"; break;
        }
        cout << endl;
        cout << "Hyper-Threading: " << (hyperThreading ? "Yes" : "No") << endl;
    }
private:
    uint16_t clockFrequency : 12;
    uint8_t wordSize : 1;   // 0表示32位，1表示64位
    uint8_t coreCount : 2;
    uint8_t hyperThreading : 1;    // 1表示支持超线程

};

int main() {
    CPU i7_14700K(3400, true, 4, true);
    i7_14700K.printInfo();

    cout << "Size of class CPU: " << sizeof(CPU) << " bytes" << endl;
}