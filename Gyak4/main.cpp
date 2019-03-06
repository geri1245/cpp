#include <iostream>
#include "a.hpp"
#include <vector>
#include <algorithm>

class A 
{
public: 
	A(int a) : i(a)
	{               
		std::cout << "Constructor" << std::endl;
	}
	A(const A& other) : i(other.i)
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

	A operator+(const A& rhs)
	{
		return A(i + rhs.i);
	}

private: 
	int i;
};


int main()
{
	//*****************************
	// Containers and algorithms
	//*****************************

	std::vector<int> v; //Instantiate an empty vector of ints
	v.reserve(8); //Allocate space for 8 ints inside v

	//Put some values into v with push_back calls
	//https://en.cppreference.com/w/cpp/container/vector/push_back
	v.push_back(5);
	v.push_back(6);
	v.push_back(8);
	v.push_back(5);
	v.push_back(8);
	v.push_back(5);

	//Almost all algorithms in the STL require a first and a last iterator to know which elements they have to work on
	//(Almost) All containers provide a begin and end member function that returns a pointer to first element and a pointer 
	//to past the last element (in case we want our algorithm to run on all elements of the container)
	int n = std::count(v.begin(), v.end(), 2); //https://en.cppreference.com/w/cpp/algorithm/count
	
	//Same as the previous call, just with explicitly defining the template parameters - usually the compiler can deduce them based on the arguments
	//int n = std::count<std::vector<int>::iterator, int>(v.begin(), v.end(), 2);

	
	//*****************************
	// Calling template functions
	//*****************************
	
	int x = f<int>(4, 7); //Because of this line, the compiler will generate f_int and that will be used here
	double y = f<double>(4.14, 2.47); //Same with double
	A z = f<A>(A(7), A(2)); //Same with A

	std::cout << x << " " << y << std::endl;

	//*****************************
	// Dynamic memory handling and the heap
	//*****************************

	int * pointer_to_array = new int[10]; //Allocate 10 ints on the heap
	A * pointer_to_A_object = new A(3); //Allocate 1 A object on the heap and call its constructor with "3"

	//ALWAYS DELETE EVERYTHING YOU ALLOCATE WITH NEW!!! ->->->  1 new <===> 1 delete 

	delete pointer_to_A_object; //Delete the A object (without this line A's destructor wouldn't be invoked)
	delete[] pointer_to_array; //Special syntax to delete arrays allocated on the heap

	return 0;
}