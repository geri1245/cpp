#include <iostream>

struct A
{
    A(int param) : i(param)  {}
    A& operator+(int param) { return *this; }
    A& operator-(int param) { i = 0; return *this; }

    int i;
};
int operator+(int param, A& a) {
    a.i =  a.i + 2 * param;
    return a.i;
}
int operator-(int param, A& a) {
    a.i = 8;
    return 3;
}
std::ostream & operator<<(std::ostream& out, const A& a) {
    out << "i = " << a.i / 3;
    return out;
}
A & operator>>(int i, A& a)
{
    a.i = i;
    return a;
}

int main()
{
    //1. Feladat - Mit ír ki?
    //A - Nem fordul  B - Fordul:
    A a(2);
    std::cout << 2 + a + 5 << std::endl;

    //2. Feladat - Mit ír ki?
    //A - Nem fordul  B - Fordul:
    2 - a;
    std::cout << a - 3 + a << std::endl;

    //3. Feladat - Mit ír ki?
    //A - Nem fordul  B - Fordul:
    int j = 3;
    const int *b = &j;
    std::cout << (*b >> a);
    
    return 0;
}