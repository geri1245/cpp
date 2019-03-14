#include <iostream>
#include <vector>

//Motivation: real-life example of inheritance in c++:
//Unreal engine inheritance hierarchy: https://api.unrealengine.com/INT/API/Runtime/Engine/Components/USceneComponent/index.html

//When classes have resources allocated with new, the default
//copy constructor is not correct 
class ResourceHandler
{
public: 
	ResourceHandler(int param) 
	{
        i = new int(param); //Allocate on the heap in the constructor
		std::cout << "Constructor" << std::endl;
	}
	ResourceHandler(const ResourceHandler& other)
	{
		i = new int(*other.i); //Allocate on the heap in the constructor
		// i = other.i; -> This is equivalent to the default generated CC, it points to the same memory location as other.
		std::cout << "Copy Constructor" << std::endl;
	}
	ResourceHandler& operator=(const ResourceHandler& other)
	{
        if(this == &other) //We need this to avoid segmentation fault, when doing self assignment ( b = b; )
            return *this;

        if(i != 0) //Check if i has a valid value. If so, delete it first to avoid memory leak. (in this case i will never be null pointer)
            delete i;
            
        i = new int(*other.i); //Same functionality as in the copy constructor
		std::cout << "Copy assignment" << std::endl;

		return *this; 
	}
	~ResourceHandler() 
	{
        delete i; //Free the allocated space
		std::cout << "Destructor" << std::endl;
	}

	int *i;
};

// We can make inteface classes - they have at least one pure virtual function.
// This means that we can't instantiate them (we can't create an object of type Inteface -> 'Interface i;' is an error)
class Interface
{
    virtual void render(int a) = 0; // =0 means pure virtual
};

// However we can have derived classes that inherit from the Interface and define the pure virtual methods
class Definition : public Interface
{
    void render(int a) /* override (in c++11) */;
};

class Base 
{
public: 
//Regular construction functions, nothing special
	Base(int param) 
	{
        i = param;
		std::cout << "Constructor" << std::endl;
	}
	Base(const Base& other) : i(other.i)
	{ std::cout << "Copy Constructor" << std::endl;	}
	Base& operator=(const Base& other)
	{ 
	    i = other.i; 
	    std::cout << "Copy assignment" << std::endl;	
	    return *this; 
	}
	virtual ~Base() //Always declare the destructor of the base class virtual, when you inherit from a class!!!
	{ std::cout << "Destructor" << std::endl; }


	//Virtual functions mean, we want to use dynamic dispatch (select the desired function at runtime)
	//This means that if we override f in a derived class, it will be called over this one.
    virtual void f()
    {
        std::cout << "f in base" << std::endl;
    }

	//Non-virtual method, there is no dynamic dispatch, the static type will matter when g is called
	void g()
	{
		std::cout << "g in base" << std::endl;
	} 

protected:
	int i;
};

class Derived : public Base //Most of the time, public inheritance is used. For completeness, here is a descriptionn:
							// https://stackoverflow.com/questions/860339/difference-between-private-public-and-protected-inheritance
{
public:
    Derived() : Base(5)
	{ std::cout << "BConstructor" << std::endl;	}
	Derived(const Derived& other) : Base(5)
	{ std::cout << "BCopy Constructor" << std::endl; }
	Derived& operator=(const Derived& other)
	{ std::cout << "BCopy assignment" << std::endl;	return *this; }
	~Derived() 
	{ std::cout << "BDestructor" << std::endl; }


	//Here we override f, so this implementation will be called 
    virtual void f()
    {
        std::cout << i << std::endl;
    }
};

class AnotherDerived : public Base // AnotherDerived does not override f, so the original implementation is called
{
public:
	AnotherDerived() : Base(5) {}
}; 

int main()
{
    //We can't instantiate the interface class, but we can have a vector of pointers to
	//objects that implement the interface's methods
	std::vector<Interface*> v;


    Base * b = new Derived; //Pointer to base can point to objects of type derived
							//Here the static type is what is in the code (Base), but the dynamic type is the 'real' type of the object (here Derived)
							//The dynamic type can change in runtime
							//https://en.wikipedia.org/wiki/Liskov_substitution_principle
							//Same goes with references (we can pass Derived object to a function expecting Base& as parameter)
	delete b;
	b = new AnotherDerived; //Static type is still Base, but dynamic type has changed to AnotherDerived
	Base * c = new Derived;

	std::cout << "Calling AnotherDerived's methods: " << std::endl;
    b->f(); //f is virtual, dynamic dispatch, but AnotherDerived does not override f, Base's definition is called
	b->g(); //g is not virtual, static type matters

	std::cout << "\n\nCalling Derived's methods: " << std::endl;
    c->f(); //f is virtual, dynamic dispatch, Derived's f definition is called
    c->g(); //g is not virtual, static type matters

    delete b;
    delete c;

    return 0;
}