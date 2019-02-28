#include <iostream>
#include "a.h"

//DON'T DO THIS
//Returning reference/pointer to temporary results in undefined behaviour
//In more detail and with examples - https://en.cppreference.com/w/cpp/language/ub
int & f(int a)
{
	int i;
	return i;
}

//We can overload on constness
int g(int & a)
{
	return 4;
}

int g(const int & a)
{
	return 5;
}

int main()
{
	A a;
	int b;
	std::cin >> a >> b; //We return the stream by reference, it is chainable
	std::cout << a << std::endl;


	int x = 5;
	int y = ++x; //Increments the variable, returns the new value - no copy is made, usually more efficient
	int z = y++; //Creates a copy, increments the original variable, returns the copy

	std::cout << x << " " << y << " " << z;

    return 0;
}