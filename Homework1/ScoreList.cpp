//
//  ScoreList.cpp
//  Homework1-4
//
//  Created by Junnan Liu on 1/24/17.
//  Copyright © 2017 Junnan Liu. All rights reserved.
//

#include "ScoreList.h"

ScoreList::ScoreList(){}
    
bool ScoreList::add(unsigned long score)
{
    if(score>=0 && score <=100 && s.size()<=DEFAULT_MAX_ITEMS)
    {
        bool flag = s.insert(s.size(),score);
        return true;
    }
    else
    {
        return false;
    }
}


bool ScoreList::remove(unsigned long score)
{
    return s.remove(score) == 0 ? false:true;
}

int ScoreList::size() const
{
    return s.size();
}
    
unsigned long ScoreList::minimum() const
{
    if(s.empty())
    {
        return NO_SCORE;
    }
    else
    {
        unsigned long a; // min
        unsigned long b; // each number
        bool flag = s.get(0, a);
        for(int i = 0; i < s.size(); ++i)
        {
            bool flag = s.get(i,b);
            a = b < a ? b : a;
        }
        return a;
    }
}
    
unsigned long ScoreList::maximum() const
{
    if(s.empty())
    {
        return NO_SCORE;
    }
    else
    {
        unsigned long a; // max
        unsigned long b; // each number
        bool flag = s.get(0, a);
        for(int i = 0; i < s.size(); ++i)
        {
            bool flag = s.get(i,b);
            a = b > a ? b : a;
        }
        return a;
    }
}
