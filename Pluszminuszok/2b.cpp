#include <iostream>

struct A
{
    A(int param) : i(param)  {}
    A& operator+(int param) { return *this; }
    A& operator-(int param) { i -= param; return *this; }

    int i;
};

A & operator+(int param, A& a) {
    a.i =  a.i + 2 * param;
    return a;
}
int operator-(int param, A& a) {
    a.i = 6;
    return 3;
}

std::ostream & operator<<(std::ostream& out, const A& a) {
    out << "i = " << a.i / 3;
    return out;
}
A & operator>>(int i, A& a)
{
    a.i = 42;
    return a;
}

int main()
{
    //1. Feladat - Mit ír ki?
    //A - Nem fordul  B - Fordul:
    int c = 15;
    A a(c);
    std::cout << a + 3 - 3 << std::endl;

    //2. Feladat - Mit ír ki?
    //A - Nem fordul  B - Fordul:
    A b(4);
    int x = 3 - b;
    std::cout << x + b << std::endl;

    //3. Feladat - Mit ír ki?
    //A - Nem fordul  B - Fordul:
    const int i = 12;
    int & j = i;
    std::cout << (j >> a);

    return 0;
}