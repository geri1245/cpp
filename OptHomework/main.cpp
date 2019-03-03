#include <cassert>

#include "SmartPointer.hpp"

class A{
public:
    A() { ++alive; };
    ~A() { --alive; };
    static int alive;
};

int A::alive = 0;

int main()
{
    /*{
        SmartPointer<int> p;
        *p = 7;
        assert(*p == 7);
        assert(p.getCounter() == 1);
        
        const SmartPointer<int> q{p};
        assert(p.getCounter() == q.getCounter());
        assert(p.getCounter() == 2);

        {
            SmartPointer<int> scoped{p};
            assert(scoped.getCounter() == 3);
            assert(*scoped == 7);
        }

        assert(p.getCounter() == 2);
    }*/
    /*{
        {
            SmartPointer<A> a;
            assert(A::alive == 1);
            SmartPointer<A> b{a};

            assert(A::alive == 1);
            assert(a.getCounter() == b.getCounter());
            assert(a.getCounter() == 2);
        }
        assert(A::alive == 0);
    }*/
    /*{
        {
            SmartPointer<A> a;
            assert(A::alive == 1);
            SmartPointer<A> b;
            assert(A::alive == 2);
            b = a;
            assert(A::alive == 1);
        }
        assert(A::alive == 0);
    }*/

    return 0;
}