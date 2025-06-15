#include <iostream>
using namespace std;
class BaseClass{
public:
    BaseClass(){
    base_num=30;
    cout<<"Base is Created"<<endl;
    }
    BaseClass(int n):base_num(n){
    cout<<"Base's number is "<<n<<endl;
}
void print();
    ~BaseClass(){
        cout<<"Base is Destroyed"<<endl;
    }
protected:
    int base_num;
};

void BaseClass::print(){
    cout<<"Print in Base"<<endl;
}

class DerivedClass: public BaseClass{
public:
    DerivedClass(){
        cout<<"Derived is Created"<<endl;
    }
    DerivedClass(int m,int n):BaseClass(n),derived_num(m){
        cout<<"Derived's number is "<<m<<endl;
    }
    ~DerivedClass(){
        cout<<"Derived is Destroyed"<<endl;
    }
protected:
    int derived_num;
};

int main()
{
    DerivedClass a;
    a.print();
    DerivedClass b(20,30);
    b.print();
    
    return 0;
 }