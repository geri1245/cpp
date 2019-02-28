#ifndef A_H
#define A_H

#include <iostream>

struct B
{
	B(int c, int d) : a(c), b(d) //Member initializer list - calls constructors of members with given values - these run first
	{  } //Body of the constructor - this runs after the above member initializations

private:
	int a, b;
};

class A 
{
public: 
	//There are only declarations here for readability
	//Member function definitions can also appear in class definitions, because 
	//they are implicitly declared inline - https://en.cppreference.com/w/cpp/language/inline
	A();
	A(const A& other);
	A& operator=(const A& other);
	~A();

	int getI() const; //const member function - can also be called on const objects (const A a;)

	//Overloaded + operator, we can use it in an infix form (A a; a + 6;)
	//We can also call it the ugly way: A::operator+(6);
	//We can have arbitrary return types, but if we want chainability, 
	//the return type has to be A&
	int operator+(int param);

	//operator<< declared inside the class:
	//Note that we can't change the parameter order when the definition is inside a class
	void operator<<(std::ostream & out);

	//Functions and classes declared as friend can acces this class' private
	//and protected members - https://en.cppreference.com/w/cpp/language/friend
	friend std::ostream & operator<<(std::ostream & out, const A& a);
	friend std::istream & operator>>(std::istream & out, A& a);

private: 
	int i;
};

//These declarations are not really necessary, the ones inside the class are enough
//Note that the return type is always the stream, returned by reference
//This allows these operations to be chainable (std::cout << a << b << 5;)
std::ostream & operator<<(std::ostream & out, const A& a);
std::istream & operator>>(std::istream & out, A& a);

#endif