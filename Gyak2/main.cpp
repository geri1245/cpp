#include <iostream>

class A //For classes the default access modifier is private
{
public: //These can be accessed from anywhere 
	A(int id, float money) //Constructor taking 2 parameters
	{                      //If there is a user-defined constructor, no default constructor is generated
		(*this).money = money; //this is a constant pointer to the object
		this->id = id; //a->b is shorthand for (*a).b
		std::cout << "Constructor" << std::endl;
	}
	A(const A& other) //Copy constructor, is called when constructing a new object from an existing one (A b(otherA); where otherA is of type A)
	{
		this->id = other.id;
		this->money = other.money;
		std::cout << "Copy Constructor" << std::endl;
	}
	A& operator=(const A& other) //Copy assignment operator, is called when the assignment operator is used: A a; a = otherA;
	{
		this->id = other.id;
		this->money = other.money;
		std::cout << "Copy assignment" << std::endl;

		return *this; //Return current object by reference
	}
	~A() //Destructor, is called when the object goes out of scope (when current stack is destroyed (eg. local variables at the end of a function))
	{
		std::cout << this << std::endl;
		std::cout << "Destructor" << std::endl;
	}

	float getMoney() // Getter function, we can read the value of private data members without being able to modify them
	{
		return money;
	}
private: //These data members can only be accessed by the class
	int id;
	float money;
};

A& f(A &param) //Calling this with a const object violates const-correcetness 
{              //If this wasn't an error, we could modify it through this function
	return param;
}

//A& f(const A &param)
//{
//	//return param; //This also violates const-correctness because param is a reference to a const object
//}                   //and we return is by reference to non-const

//int is just a placeholder to be able to overload f
const A& f(const A &param, int placeholder) //This is correct, we can see the object, but cannot modify it
{
	return param;
}

A f(A param) //param is copied (copy constructor is called here), we can modify the local copy
{            //and we return a copy (this function can be called with a const param as well)
	return param; //The local param variable is destroyed when returning from the function
}

int main()
{
	int a = 8;
	const int * b = &a; //Pointer to const int
	int const * c = &a; //Same 
	int * const d = &a; // const pointer to int

	int * f = &a;
	int * * const e = &f; //Const pointer to pointer to int

	A x(10, 500.5); //Instantiate A -- constructor
	A y(x);         //Copy constructor
	x = y;          //Copy assignment operator

	std::cout << x.getMoney() << std::endl;

	return 0; //This is when the local objects are destroyed (a - f, x, y)
	std::cout << "This code does not run, because we return in the previous line.";
}