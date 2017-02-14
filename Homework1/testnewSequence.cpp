#include "newSequence.h"
#include <iostream>
#include <cassert>
using namespace std;

int main()
{
    cout<<"Testing setsize array"<<endl;
    Sequence s;
    assert(s.empty());
    assert(s.find(42) == -1);
    s.insert(42);
    assert(s.size() == 1  &&  s.find(42) == 0);
    cout << "Passed all tests" << endl;
    
    cout<<"Testing dynamic size array"<<endl;
    Sequence p(18);
    assert(p.empty());
    assert(p.find(42) == -1);
    p.insert(42);
    assert(p.size() == 1  &&  p.find(42) == 0);
    cout << "Passed all tests" << endl;
    
    cout<< "Testing the given test"<<endl;
    Sequence a(1000);   // a can hold at most 1000 items
    Sequence b(5);      // b can hold at most 5 items
    Sequence c;         // c can hold at most DEFAULT_MAX_ITEMS items
    ItemType v = 192;
    
    // No failures inserting 5 items into b
    for (int k = 0; k < 5; k++)
    assert(b.insert(k, v));

    cout<<"If want to try the failure part"<<endl;
    // Failure if we try to insert a sixth item into b
    assert(!b.insert(5, v));
    
    // When two Sequences' contents are swapped, their capacities are
    // swapped as well:
    a.swap(b);
    assert(!a.insert(5, v));
    for (int k = 0; k < 1000; k++)
    assert(b.insert(k, v));
}
