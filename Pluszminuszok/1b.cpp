#include <iostream>

class A 
{
public: 
	A() 
	{                      
		std::cout << "Constructor" << std::endl;
	}
	A(const A& other)
	{
		std::cout << "Copy Constructor" << std::endl;
	}
	A& operator=(const A& other)
	{
		std::cout << "Copy assignment" << std::endl;

		return *this; 
	}
	~A() 
	{
		std::cout << "Destructor" << std::endl;
	}

private: 
	int i;
};

//****************
// 1. Feladat
int f(const int & i)
{
	const int * local = &i;
	return (*local + 1);
}
//***************
// 2. feladat
const A & g(A & param)
{
	A local;
	local = param;

	return param;
}

int main()
{
    //1. feladat: Mit ír ki a program?
	// A, Nem fordul    B, Fordul és valamilyen számot:
    int i = 5;
    int * const j = &i;

    std::cout << f(*j);

    //2. feladat: Mit ír ki a program?
	// A, Nem fordul    B, Fordul és az alábbiakat:
    A a;
    A b(a);
	a = g(b);

	//3. feladat: Mi a különbség a struct és a class között 
	//(technikailag és használatát tekintve)?

    return 0;
}