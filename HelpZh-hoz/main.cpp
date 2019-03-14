#include <vector>
#include <algorithm> //https://en.cppreference.com/w/cpp/algorithm
#include <iostream>
#include <numeric>

//A functor is a class/struct with overloaded () operator

struct Functor 
{
    bool operator()(int a) //Overloaded () operator, can have arbitrary parameters and return type
    {
        return a > 5; //Return true, if number is greater than 5.
    }
};

struct Addition
{
    int operator()(int a, int b) //We usually write predicates, that return bool, but this is also a functor
    {
        return a * b; //Just return a multiplied by b
    }
};

struct Triple
{
    int operator()(int a)
    {
        return 3 * a;
    }
};

int main()
{
    Functor f; //Instantiate our functor
    if( f(7) ) //We can simply use the () operator on an int and it returns a bool (just as we defined it)
    {
        std::cout << "7 is greater than 5" << std::endl;
    }

    Addition adder;
    int a = adder(7, 2); //a == 9

    //***********************
    //**** Usage of functors
    //***********************

    std::vector<int> v {1, 4, 7, 8, 9, 5, 4, 1, 4, 7, 4, 5 ,7, 7, 8}; //Need c++11 to initialize a vector like this

    a = std::count_if(v.begin(), v.end(), Functor{}); //Counts elements for which the () operator of Functor returns true
    std::cout << "Num of elemets greater than 5: " << a << std::endl;


    std::vector<int> result;
    result.reserve(v.size());
    std::transform(v.begin(), v.end(), result.begin(), Triple{}); //Same as a map in functional languages, stores the result in result

    //Iterate through a vector using iterators
    for(std::vector<int>::iterator it = result.begin(); it != result.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout <<std::endl;

    a = std::accumulate(v.begin(), v.end(), 1, Addition{}); //Basically the same as a fold in functional languages
    std::cout << "Result of multiplying all elements of v: " << a << std::endl;

    return 0;
}