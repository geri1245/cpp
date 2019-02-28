#include <cassert>

int main()
{
    Stack<double> ds;
    assert(ds.size() == 0);

    ds.push(12).push(14).push(54);
    assert(ds.size() == 3);
    
    ds.add();
    assert(ds.pop() == 68);

    ds.push(60);
    assert(ds.pop() == 60);
    assert(ds.size() == 1);
    
    ds.clear();
    assert(ds.size() == 0);

    return 0;
}