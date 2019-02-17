#include <iostream>
#include "a.h"

/****************************
 * Preprocessor
 * Only use when necessary - https://stackoverflow.com/questions/14041453/why-are-preprocessor-macros-evil-and-what-are-the-alternatives
****************************/

#define PI 3.1415
#define add(a, b) ( (a) + (b) )

/****************************
 * Namespaces
****************************/

namespace a //Namespace definition
{
    namespace b //Nested namespaces are also possible
    {
        int g() //Can be referenced as a::b::g();
        {
            return 4;
        }
    }
}

/****************************
 * Declaration vs definition
****************************/

int g(){ return 4; } //Does not violate One Definition Rule - the g()s are not in the same namespace (g() and a::b::g())

void f(int, int); //Declaration of f
void f(int, int); //Another declaration of f
void f(int, int); //Yet another declaration of f (it can have arbitrarily many)

void f(int, int)
{

} //Definition (and declaration) of f (there can only be one)

/****************************
 * Passing function arguments
****************************/

void h_p(int * a) //Take parameter by pointer (no copy)
{
    *a += 2;
}

void h_ref(int &a) //Take parameter by reference (no copy)
{
    a += 2;
}

void h_cp(int a) //Take parameter by value (copy!)
{
    a += 2; //This has no effect on the calling side
}

void h_const_ref(const int& a) //Take parameter by const ref - can't be modified, no copy
                               //This is usually the preferred way for larger objects (eg for ints, value is fine)
{
    //a += 2; //Error: const value cannot be modified 
}

int main()
{
    //References

    int a = 8; //Local variable
    int &c = a; //Reference to local variable (Dangerous, should be avoided)
    c = 3; //Modify a through c
    std::cout << a << std::endl;

    //Pointers

    int s = 5;
    int *b = &s; //Pointer to local variable (&s == memory address of s)
    *b = 15; //Modify s through b
    std::cout << s << std::endl;

    //Arrays as pointers

    int t[4] = {4, 7, 2, 6}; //Array of 4 ints, initialized with an initializer list

    std::cout << t << std::endl; //pointer to the first member of the array

    std::cout << t[2] << std::endl; //Easiest to read
    std::cout << 2[t] << std::endl; //Pls don't use this
    std::cout << *(2 + t) << std::endl; //Ugly
    std::cout << *(t + 2) << std::endl; //Ugly
    
    return 0;
}