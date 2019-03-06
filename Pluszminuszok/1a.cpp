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
int f(int & i)
{
    return 2 * i;
}

//***************
// 2. feladat
A & g(const A& param)
{
	A *local;
	local = &param;

	return *local;
}

int main()
{
    //1. feladat: Mit ír ki a program?
	// A, Nem fordul    B, Fordul és valamilyen számot:
    int i = 5;
    int * const j = &i;

    const int k = f(*j);

    std::cout << i;

    //2. feladat: Mit ír ki a program?
	// A, Nem fordul    B, Fordul és az alábbiakat:
    A a;
    A b(a);
	a = g(b);

	//3. feladat: Miért fontos/Mi az a konstans korrektség?

    return 0;
}