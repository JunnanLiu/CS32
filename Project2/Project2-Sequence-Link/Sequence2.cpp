//
//  Sequence.cpp
//  Sequences-array
//
//  Created by Junnan Liu on 1/28/17.
//  Copyright © 2017 Junnan Liu. All rights reserved.
//
// Sequence.cpp

#include "Sequence.h"

// 学会巧妙利用已经写好的函数

// ok
Sequence::Sequence()
{
    head = nullptr; // create empty link
    m_size = 0;
}
// ok
Sequence::Sequence(Sequence const &old)
{
    
    
    if(old.empty())  // If old is empty, do nothing
        return;
    int i = 0;
    m_size = 0;  // create empty link
    head = nullptr;
    for( Node *p = old.head; i < old.size(); p = p-> next) // copy all link from old
    {
        insert(i, p->value);
        ++i;
    }
}

// ok
Sequence & Sequence::operator= (const Sequence &other)
{
    if ( this != & other )  // avoiding duplicating itself
    {
        Sequence temp(other); // create a copy of other
        this->swap(temp);  // swap this and other
    }
    return *this;
}
// ok
bool Sequence::empty() const
{
    if(m_size == 0)
        return true;
    return false;
}
// ok
int Sequence::size() const
{
    return m_size;
}
// ok
bool Sequence::insert(int pos, const ItemType& value)
{
    
    if (pos < 0  ||  pos > size())
        return false;
    uncheckedInsert(pos, value);
    return true;
}
// ok
int Sequence::insert(const ItemType& value)
{
    int pos = -1;
    Node *p = head;
    if ( head == nullptr || value <= head->value)// If the sequence is empty, or value < head value, insert to the front
    {
        addToFront(value);
        return 0;
    }
    else
    {
        for ( int i = 0; i < m_size; i++)  // Insert in the middle
        {
            if(value <= p->value)
            {
                pos = i;
                insert(pos,value);
                return pos;
            }
            p = p-> next;  // Insert in the end of the sequence
            if(p == nullptr)
            {
                pos = m_size;
                insert(pos,value);
                return pos;
            }
        }
        return pos;
    }
}
// ok
void Sequence::addToFront(const ItemType & value)
{
    Node *p = new Node;
    p->value = value;
    p->next = head;
    p->previous = nullptr;
    head = p;
    m_size ++;
}
// ok
void Sequence::uncheckedInsert(int pos, const ItemType& value)
{
    // If pos = 0, insert at the front, m_size + 1
    if(pos == 0)
        addToFront(value);
    // If pos != 0, use a temp to traverse to the pos, m_size + 1
    else
    {
        Node *p = head;  // p is a traverse data, goes above the place to insert
        for (int i = 0; i < pos-1 ; i++)  // Very important!!! the stop sign is pos-1, because we want p pointing above insert
        {
            p = p->next;
        }
        Node *n = new Node;  // n is the insert node, with position = pos
        n->value = value;  // add value to new node
        n->next = p->next;  // new data connection
        n->previous = p;
        p->next = n;  // old data connection
        p->next->previous = n;
        m_size ++;
    }
}
// ok
bool Sequence::erase(int pos)
{
    if (pos < 0  ||  pos >= size())
        return false;
    if(pos == 0)   // Deleting the first item
    {
        Node *killMe = head;
        head = killMe-> next;
        head->previous = nullptr;
        delete killMe;
        m_size --;
        return true;
    }
    if(pos == size()-1)  // Deleting the last item
    {
        Node *p = head;
        for (int i = 1; i < pos; i++)
        {p = p->next;}
        Node *killMe = p->next;  // killMe is node in pos, p is node above pos, killMe = p->next
        // connect killMe->previous to killMe->next
        p->next = nullptr;
        delete killMe;
        m_size --;
        return true;
    }
    else  // Deleting the item in the middle of the link
    {
        Node *p = head;
        for (int i = 1; i < pos; i++)
        {p = p->next;}
        Node *killMe = p->next;  // killMe is node in pos, p is node above pos, killMe = p->next
        // connect killMe->previous to killMe->next
        p->next = killMe->next;
        p->next->previous = killMe->previous;
        delete killMe;
        m_size --;
        return true;
    }
}

// ok
int Sequence::remove(const ItemType& value)
{
    int keepPos = find(value);
    if (keepPos == -1) // nothing to remove if no value = value
        return 0;
    int count = 1;
    for (int examinePos = keepPos+1; examinePos < size(); examinePos++)  // Finding after the first pos that equals to value
    {
        Node * p = head;
        for( int i = 0; i < examinePos; i++)
        { p = p -> next; }
        
        Node * q = head;
        for( int i = 0; i < keepPos; i++)
        { q = q -> next; }
        
        if (p -> value == value)
            count++;
        else
        {
            q -> value = p -> value;
            keepPos++;
        }
    }
    m_size -= count;
    for( int i= m_size; i < m_size+count;i++)   // For every item after actual size, erase those node
    {
        erase(i);
    }
    return count;
}
// ok
bool Sequence::get(int pos, ItemType& value) const
{
    if (pos < 0  ||  pos >= size())
        return false;
    Node *p = head;
    for(int i = 0; i < pos; i++)
    {
        p = p->next;
    }
    value = p-> value;
    return true;
}
// ok
bool Sequence::set(int pos, const ItemType& value)
{
    if (pos < 0  ||  pos >= size())
        return false;
    Node *p = head;
    for(int i = 0; i < pos; i++)
    {
        p = p->next;
    }
    p->value = value;
    return true;
}

// ok
int Sequence::find(const ItemType& value) const
{
    Node *p = head;
    for (int pos = 0; pos < size(); pos++)
    {
        if (p->value == value)
        {
            return pos;
        }
        p = p->next;
    }
    return -1;
}
// not ok
void Sequence::swap(Sequence& other)
{
    Node * temp = this-> head;
    this -> head = other.head;
    other.head = temp;

    // swap size
    int tempSize = m_size;
    m_size = other.m_size;
    other.m_size = tempSize;
}

/*
void Sequence::printItems() const
{
    Node *p;
    p = head; // p points to 1st node
    while (p!=nullptr)
    {
        cout<< p->value <<std::endl;
        p = p->next;
    }
}
 */

// ok
Sequence::~Sequence()
{
    Node *p = head;
    while(p != nullptr)
    {
        Node *n = p->next;
        delete p;
        p = n;
    }
}

int subsequence(const Sequence& seq1, const Sequence& seq2)
{
    if(seq2.empty() || seq1.size() < seq2.size())  // If s2 is empty, or s2 is longer than s1, return -1
        return -1;
    ItemType value;  // the first value in seq2
    seq2.get(0, value);
    int m = seq1.find(value);  // find if the first value exist in seq1
    
    if(m == -1)  // The first value doesn't exist
        return -1;
    
    for(int i = m; i <= seq1.size() - seq2.size(); i++) // for every item after the first same pos
    {
        int count = 0;  // decide if every item in seq2 can find a match
        for(int j = 0; j < seq2.size(); j++)   // for every item in seq2
        {

            ItemType value1;  // value in seq1
            ItemType value2;  // value in seq2
            seq1.get(i+j, value1);
            seq2.get(j, value2);
            if(value1 == value2)
                count ++;  // count the number that seq1 and seq 2 are equal
            else
                break; // if one item is not equal, break counting
        }
        if(count == seq2.size())  // decide if every item in seq2 can find a match
        {
            return i;
        }
    }
    return -1;
}

void interleave(const Sequence& seq1, const Sequence& seq2, Sequence& result)
{
    if(seq1.empty())  //If either sequence is empty, result must consist of a copy of the other sequence
    {
        result = seq2;
        return;
    }
    
    if(seq2.empty())
    {
        result = seq1;
        return;
    }

    Sequence temp;  //  copy seq1 to temp
    temp = seq1;
    
    for(int i = 0; i < min(seq1.size(),seq2.size()); ++i)  // insert seq2 to seq1 for common part
    {
        ItemType value2;
        seq2.get(i, value2);
        temp.insert(2*i+1,value2);
    }
    
    if(seq1.size() < seq2.size())  // seq2 is longer
    {
        for(int i = 0 ; i < seq2.size() - seq1.size(); ++i)
        {
            ItemType value;
            seq2.get(i+seq1.size(), value);
            temp.insert(2 * seq1.size()+i, value);
        }
    }
    result.swap(temp);
}
