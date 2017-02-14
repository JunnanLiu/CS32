//
//  Sequence.h
//  Homework1-Sequence of Strings
//
//  Created by Junnan Liu on 1/21/17.
//  Copyright © 2017 Junnan Liu. All rights reserved.

#ifndef Sequence_hpp
#define Sequence_hpp
#include <iostream>
#include <string>
#include <cassert>
#include <stdio.h>

const int DEFAULT_MAX_ITEMS = 200;
typedef unsigned long ItemType;

class Sequence
{
public:
    Sequence();    // Create an empty sequence (i.e., one whose size() is 0).
    
    bool empty() const;  // Return true if the sequence is empty, otherwise false.

    int size() const;    // Return the number of items in the sequence.

    bool insert(int pos, const ItemType& value); //Insert value into the sequence so that it becomes the item at position pos.

    int insert(const ItemType& value); //Let p be the smallest integer such that value <= the item at position p in the sequence

    bool erase(int pos); // remove the item at position pos from the sequence

    int remove(const ItemType& value);  // Erase all items from the sequence that == value.  Return the number of items removed
    
    bool get(int pos, ItemType& value) const; //copy into value the item at position pos in the sequence and return true

    bool set(int pos, const ItemType& value);  //replace the item at position pos in the sequence with value and return true.
    
    int find(const ItemType& value); //Let p be the smallest integer such that value == the item at position p in the sequence
    
    void swap(Sequence& other); // Exchange the contents of this sequence with the other one.
    
private:
    ItemType p_str[DEFAULT_MAX_ITEMS];
    int strLength;
};
#endif /* Sequence_hpp */
