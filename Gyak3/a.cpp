#include "a.h" //Include the header, so we get error messages when trying
               //to define a function of A that we haven't even declared (typo, missing qualifiers...) 

A::A()
{          
    i = 5;            
    std::cout << "Constructor" << std::endl;
}

A::A(const A& other)
{
    std::cout << "Copy Constructor" << std::endl;
}

A& A::operator=(const A& other)
{
    std::cout << "Copy assignment" << std::endl;

    return *this; 
}

A::~A() 
{
    std::cout << "Destructor" << std::endl;
}

int A::getI() const
{
    return i;
}

int A::operator+(int param)
{
    i += param;
    return i;
}

std::ostream & operator<<(std::ostream & out, const A& a)
{
    out << "i = " << a.i << std::endl;

    return out;
}

std::istream & operator>>(std::istream & in, A& a)
{
    in >> a.i;

    return in;
}
