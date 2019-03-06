#ifndef A_HPP
#define A_HPP

// Definitions and declarations are in a single translation unit, because the compiler
// needs to see the definition as well to generate the code (instantiate the template)
// More: https://stackoverflow.com/questions/495021/why-can-templates-only-be-implemented-in-the-header-file

//Function template
template <class T /* = int*/> //There can be default values (like int here) and multiple parameters
T f(T a, T b)
{
	return a + b; //The + operator must be defined for the type T
}

// If there is a call to this function in our code with int parameter (f<int>), 
// the compiler generates the code for it. And a new function is generated for every type,
// that appears in our code with this function (f<double> generate for double, f<A> - generate for A ...)
// int f_int(int a, int b)
// {
//     return a + b; 
// }

// Class template
template <class T>
class B
{
public:
    T getA();
private:
    T a;
};

// Compiler also generates code with the given parameters (eg. B<double> b; is written in our code)
// class B
// {
// public:
//     double getA();
// private:
//     double a;
// };

// "Special" syntax for class template member function definitions:
template <class T>
T B<T>::getA()
{
    return a;
}

#endif