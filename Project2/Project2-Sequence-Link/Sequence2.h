//
//  Sequence.h
//  Sequences-array
//
//  Created by Junnan Liu on 1/28/17.
//  Copyright © 2017 Junnan Liu. All rights reserved.
//
// Sequence.h

// For this linked list implementation, if you let the compiler write
// the destructor, copy constructor, and assignment operator, they will do the wrong thing,
// so you will have to declare and implement these public member functions as well

#include <iostream>
#include <cassert>
#ifndef SEQUENCE_INCLUDED
#define SEQUENCE_INCLUDED

using namespace std;

// Later in the course, we'll see that templates provide a much nicer
// way of enabling us to have Sequences of different types.  For now,
// we'll use a typedef.

typedef std::string ItemType;

struct Node
{
    ItemType value;
    Node *next;
    Node *previous;
};

class Sequence
{
public:
    Sequence();          // Create an empty sequence (i.e., one whose size() is 0).
    
    Sequence(Sequence const &old);
    // When a brand new Sequence is created as a copy of an existing Sequence,
    // enough new nodes must be allocated to hold a duplicate of the original list.

    Sequence &operator= (const Sequence &other);
    // When an existing Sequence (the left-hand side) is assigned the value of another Sequence (the right-hand side),
    // the result must be that the left-hand side object is a duplicate of the right-hand side object,
    // with no memory leak of list nodes (i.e. no list node from the old value of the left-hand side
    // should be still allocated yet inaccessible).
 
    bool empty() const;  // Return true if the sequence is empty, otherwise false.
    
    int size() const;    // Return the number of items in the sequence.
    
    bool insert(int pos, const ItemType& value);
    // Insert value into the sequence so that it becomes the item at
    // position pos.  The original item at position pos and those that
    // follow it end up at positions one higher than they were at before.
    // Return true if 0 <= pos <= size() and the value could be
    // inserted.  (It might not be, if the sequence has a fixed capacity,
    // (e.g., because it's implemented using a fixed-size array) and is
    // full.)  Otherwise, leave the sequence unchanged and return false.
    // Notice that if pos is equal to size(), the value is inserted at the
    // end.
    
    int insert(const ItemType& value);
    // Let p be the smallest integer such that value <= the item at
    // position p in the sequence; if no such item exists (i.e.,
    // value > all items in the sequence), let p be size().  Insert
    // value into the sequence so that it becomes the item at position
    // p.  The original item at position p and those that follow it end
    // up at positions one higher than before.  Return p if the value
    // was actually inserted.  Return -1 if the value was not inserted
    // (perhaps because the sequence has a fixed capacity and is full).
    
    bool erase(int pos);
    // If 0 <= pos < size(), remove the item at position pos from
    // the sequence (so that all items that followed this item end up at
    // positions one lower than they were at before), and return true.
    // Otherwise, leave the sequence unchanged and return false.
    
    int remove(const ItemType& value);
    // Erase all items from the sequence that == value.  Return the
    // number of items removed (which will be 0 if no item == value).
    
    bool get(int pos, ItemType& value) const;
    // If 0 <= pos < size(), copy into value the item at position pos
    // in the sequence and return true.  Otherwise, leave value unchanged
    // and return false.
    
    bool set(int pos, const ItemType& value);
    // If 0 <= pos < size(), replace the item at position pos in the
    // sequence with value and return true.  Otherwise, leave the sequence
    // unchanged and return false.
    
    int find(const ItemType& value) const;
    // Let p be the smallest integer such that value == the item at
    // position p in the sequence; if no such item exists, let p be -1.
    // Return p.
    
    void swap(Sequence& other);
    // Exchange the contents of this sequence with the other one.

//    void printItems() const;
    
    ~Sequence();
    // When a Sequence is destroyed, the nodes in the linked list must be deallocated.
    
private:
    Node *head;
    
    int m_size;  // The length of the link
    
    //和自己写的不一样的private函数，更方便了！
    void uncheckedInsert(int pos, const ItemType& value);
    // Insert value at position pos, shifting items to the right to make
    // room for it.  Assume pos is valid and there's room.
    
    void addToFront(const ItemType & value);
    // Insert value at the front of the link
};

int subsequence(const Sequence& seq1, const Sequence& seq2);
// if seq2 is a consecutive subsequence of seq1,
// the function returns the earliest place in seq1 where that subsequence starts

void interleave(const Sequence& seq1, const Sequence& seq2, Sequence& result);


#endif // SEQUENCE_INCLUDED
