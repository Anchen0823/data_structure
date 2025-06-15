#ifndef CLASSES_H
#define CLASSES_H

class X;    //前向声明
class Y {
public:
    void g(X *x);
};

class X {
private:
    int i;

    //友元声明
    friend void h(X *x);
    friend void Y::g(X *x);
    friend class Z;
public:
    X(int val = 0) : i(val) {}
    int getValue() const {return i;}
};


class Z {
public:
    void f(X *x);
};

void h(X *x) {
    x->i += 10;
}

void Y::g(X *x) {
    x->i += 1;
}

void Z::f(X *x) {
    x->i += 5;
}

#endif // CLASSES_H