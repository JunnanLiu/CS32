//
//  Sequence.cpp
//  Homework1-Sequence of Strings
//
//  Created by Junnan Liu on 1/21/17.
//  Copyright © 2017 Junnan Liu. All rights reserved.
//

#include "newSequence.h"
#include <iostream>
using namespace std;
Sequence::Sequence()
{
    setsize = DEFAULT_MAX_ITEMS;
    p_str = new ItemType[setsize];
    strLength = 0;
}   // Create an empty sequence (i.e., one whose size() is 0).

Sequence::Sequence(int number)
{
    setsize = number;
    p_str = new ItemType[setsize];
    strLength = 0;
}

bool Sequence::empty() const // Return true if the sequence is empty, otherwise false.
{
    return strLength==0?true:false;
}

int Sequence::size() const    // Return the number of items in the sequence.
{
    return strLength;
}

bool Sequence::insert(int pos, const ItemType& value)
{
    if(pos < 0||pos > strLength||strLength==setsize) // only 1 item, strLength = 1, pos can be 1, means the end of sequence
    {
        return false;
    }
    else
    {
        strLength += 1;
        for(int i = strLength - 1; i > pos; i--)
        {
            p_str[i] = p_str[i-1];
        }
        p_str[pos] = value;
        return true;
    }
}

int Sequence::insert(const ItemType& value)
{
    if(strLength == DEFAULT_MAX_ITEMS)
    {
        return -1;
    }
    else
    {
        for(int i = 0; i < strLength;i++)
        {
            if (value <= p_str[i])
            {
                bool flag = this->insert(i, value);
                return i;
            }
        }
        bool flag = this->insert(strLength,value);
        return strLength;
    }
}

bool Sequence::erase(int pos)
{
    if(pos < 0 || pos >= strLength)
    {
        return false;
    }
    else
    {
        ItemType *p_old = p_str;
        strLength -= 1;
        for(int i = 0; i < pos; i++)
        {
            p_str[i] = p_old[i];
        }
        for(int i = pos; i < strLength;i++)
        {
            p_str[i] = p_old[i+1];
        }
        return true;
    }
}

int Sequence::remove(const ItemType& value)
{
    int count = 0;
    ItemType p_new[DEFAULT_MAX_ITEMS];
    for(int i=0;i<=strLength;i++)
    {
        if(p_str[i] != value)
        {
            p_new[i-count] = p_str[i];
        }
        else
        {
            count+=1;
        }
    }
    for(int i=0; i <= strLength-count;i++)
    {
        p_str[i] = p_new[i];
    }
    strLength = strLength - count;
    return count;
}
    
bool Sequence::get(int pos, ItemType& value) const
{
    if(pos < 0||pos >= strLength)
    {
        return false;
    }
    else
    {
        value = p_str[pos];
        return true;
    }
}

bool Sequence::set(int pos, const ItemType& value)
{
    if(pos < 0||pos >= strLength)
    {
        return false;
    }
    else
    {
        p_str[pos]=value;
        return true;
    }
}
    
int Sequence::find(const ItemType& value)
{
    bool flag = false;
    int p = 0;
    for(int i = 0; i < strLength;i++)
    {
        if(p_str[i]==value)
        {
            flag = true;
            p=i;
            break;
        }
    }
    if(flag)
    {
        return p;
    }
    else
    {
        return -1;
    }
}
    
void Sequence::swap(Sequence& other)
{
    for (int i = 0; i < max(other.strLength, this->strLength); ++i) {
        if (i >= this->strLength) {  // this 更短，对针对超出部分更换
            this->p_str[i] = other.p_str[i];
        }
        else if (i >= other.strLength) {
            other.p_str[i] = this->p_str[i];
        }
        else { // 两者共有的部分
            auto tmp = other.p_str[i];
            other.p_str[i] = this->p_str[i];
            this->p_str[i] = tmp;
        }
    }
    ::swap(this->strLength, other.strLength);
    ::swap(this->setsize,other.setsize);
}
