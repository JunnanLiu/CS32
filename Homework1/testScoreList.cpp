//
//  testScoreList.cpp
//  Homework1-4
//
//  Created by Junnan Liu on 1/24/17.
//  Copyright © 2017 Junnan Liu. All rights reserved.
//

#include <stdio.h>
#include "ScoreList.h"
#include <cassert>

int main()
{
    // test add
    cout<<"Testing add"<<endl;
    ScoreList l1;
    l1.add(10);
    l1.add(43);
    l1.add(56);
    l1.add(143);
    assert(l1.add(134) == false);
    assert(l1.add(19) == true);
    
    //test remove
    cout<<"Testing remove"<<endl;
    l1.remove(10);
    assert(l1.remove(56)==true);
    assert(l1.remove(84)==false);
    
    //test size
    cout<<"Testing size"<<endl;
    assert(l1.size()==2);
    l1.add(69);
    assert(l1.size()==3);
    
    //test min
    cout<<"Testing minimum"<< endl;
    ScoreList l2;
    assert(l2.minimum() == NO_SCORE);
    assert(l1.minimum() == 19);
    
    //test max
    cout<<"Testing maximum" << endl;
    assert(l2.maximum() == NO_SCORE);
    assert(l1.maximum() == 69);
    
    cout<< "Pass all test" <<endl;
}
