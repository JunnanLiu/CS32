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
#include <stdio.h>
#include <cassert>

const int DEFAULT_MAX_ITEMS = 200;
typedef unsigned long ItemType;

class Sequence
{
public:
    Sequence();    // Create an empty sequence (i.e., one whose size() is 0).
    
    Sequence(int number);  // Create an empty sequence (i.e., one whose size() is 0).
 
    bool empty() const;  // Return true if the sequence is empty, otherwise false.

    int size() const;    // Return the number of items in the sequence.

    bool insert(int pos, const ItemType& value);
    // 在位置pos处添加value，同时原位置和后续位置都后移一位。true时才能添加，false时不变。

    int insert(const ItemType& value);
    // 找到第一个 value小于该位置数值的位置，并插入value，其他位置后移。
    
    bool erase(int pos);
    // true时删除一位其他位置前移，否则不变

    int remove(const ItemType& value);
    // 和value相等的全部移除，并返回移除几个！

    bool get(int pos, ItemType& value) const;
    // 获得位置pos处数值存入value，如果size不合适返回false并不处理

    bool set(int pos, const ItemType& value);
    // 设置pos处数值，否则不变
    
    int find(const ItemType& value);
    // 返回等于value的第一个位置，不存在返回-1
    
    void swap(Sequence& other);
  
private:
    int setsize;
    ItemType *p_str;
    int strLength;
};

#endif /* Sequence_hpp */
