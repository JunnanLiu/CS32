//
//  ScoreList.hpp
//  Homework1-4
//
//  Created by Junnan Liu on 1/24/17.
//  Copyright © 2017 Junnan Liu. All rights reserved.
//

#ifndef ScoreList_h
#define ScoreList_h

#include <stdio.h>
#include "Sequence.h"
#include <limits>
#include <iostream>

using namespace std;

const unsigned long NO_SCORE = std::numeric_limits<unsigned long>::max(); // 返回编译器允许的 unsigned long 型数 最大值

class ScoreList
{
public:
    ScoreList();       // Create an empty score list.
    
    bool add(unsigned long score);
    
    bool remove(unsigned long score);
 
    int size() const;  // Return the number of scores in the list.
    
    unsigned long minimum() const;
    // Return the lowest score in the score list.  If the list is
    // empty, return NO_SCORE.
    
    unsigned long maximum() const;
    // Return the highest score in the score list.  If the list is
    // empty, return NO_SCORE.

private:
    Sequence s;// Some of your code goes here.
};

#endif /* ScoreList_hpp */
