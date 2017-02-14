//
//  main.cpp
//  Project2-Sequence-Link
//
//  Created by Junnan Liu on 1/28/17.
//  Copyright © 2017 Junnan Liu. All rights reserved.
//

#include <iostream>
#include "Sequence.h"

int main() {
  // Testing uncheckedinsert done
//    Sequence s2;
  //  s2.uncheckedInsert(0, "A");
    //s2.uncheckedInsert(0, "P");
//    s2/=.uncheckedInsert(1, "M");
  //  s2.uncheckedInsert(3, "Q");
   // s2.printItems();
    //cout<<endl;

    // Testing empty & size & insert(pos,value) done
    cout<<"Testing empty & size & insert(pos,value)"<<endl;
    Sequence s1;
    assert(s1.empty() == 1);
    assert(s1.size() == 0);
    assert(s1.insert(0, "B") == 1);
    assert(s1.insert(1, "C") == 1);
    assert(s1.size() == 2);
    assert(s1.insert(3, "D") == 0);
    assert(s1.empty() == 0);
    assert(s1.size() == 2);
    s1.printItems();
    cout<<"Correct answer is BC"<<endl;

    // Testing Sequence ( & old) done
    cout<<"Testing Sequence ( & old)"<<endl;
    Sequence s3(s1);
    s3.printItems();
    cout<<"Correct answer is BC"<<endl;
    
    // Testing operator =
    cout<<"Testing operator = "<<endl;
    s3.insert(2, "Q");
    s3.insert(3, "M");
    s3.printItems();
    cout<<"Correct answer is BCQM"<<endl;
    s3 = s1;
    s3.printItems();
    cout<<"Correct answer is BC"<<endl;
    Sequence s8(s1);
    s8.insert("P");
    s3 = s8;
    s3.printItems();
    cout<<"Correct answer is BCP"<<endl;

    
    // Testing insert(value)
    cout<<"Testing insert(value)"<<endl;
    assert(s1.insert("A") == 0);
    s1.printItems() ;
    cout<<"Correct answer is ABC"<<endl;
    assert(s1.insert("F") == 3);
    assert(s1.size() == 4);
    s1.printItems();
    cout<<"Correct answer is ABCF"<<endl;
//    assert(s1.insert("D")==3);
//    s1.printItems();
//    cout<<"Correct answer is ABCDF"<<endl;
 
    
    // Testing erase
    // erase first item
    cout<<"Testing erase"<<endl;
    s1.erase(0);
    s1.printItems();
    cout<<"Correct answer is BCF"<<endl;
    // erase middle item
    s1.erase(1);
    s1.printItems();
    cout<<"Correct answer is BF"<<endl;
    // erase last item
    s1.erase(1);
    s1.printItems();
    cout<<"Correct answer is B"<<endl;
    
    
    // Testing find
    cout<<"Testing find"<<endl;
    s1.insert(1, "P");
    s1.insert(1, "M");
    s1.printItems();
    cout<<"Correct answer is BMP"<<endl;
    assert(s1.find("B")==0);
    assert(s1.find("Q")==-1);
    assert(s1.find("M")==1);
    
    //Testing set & get
    cout<<"Testing set & get"<<endl;
    s1.set(2,"Q");
    s1.printItems();
    cout<<"Correct answer is BMQ"<<endl;
    ItemType p;
    assert(s1.get(2,p) == 1 && p == "Q");
    cout<<p<<endl;
    cout<<"Correct answer is Q"<<endl;
    
    // Testing remove
    cout<<"Testing remove"<<endl;
    s1.insert(2, "B");
    s1.insert(1, "Q");
    s1.insert(2, "C");
    cout<<"Original"<<endl;
    s1.printItems();
    cout<<"Correct answer is BQCMBQ"<<endl;
    cout<<"After"<<endl;
    assert(s1.remove("B")==2);
    s1.printItems();
    cout<<"Correct answer is QCMQ"<<endl;
    
    // Testing swap
    cout<<"Testing swap"<<endl;
    Sequence s4(s1);
    s4.set(3, "P");
    s4.insert(2, "L");
    s4.insert(0, "E");
    s4.printItems();
    cout<<"Correct answer is EQCLMP"<<endl;
    s4.swap(s1);
    s4.printItems();
    cout<<"Correct answer is QCMQ"<<endl;
    s1.printItems();
    cout<<"Correct answer is EQCLMP"<<endl;
    
    // Testing subsequence
    cout<<"Testing subsequence"<<endl;
    assert(subsequence(s4, s1) == -1); // s4 is shorter
    s4.swap(s1);
    assert(subsequence(s4, s1) == -1);
    s4.insert(6, "Q");
    s4.insert(7, "C");
    s4.insert(8, "M");
    s4.insert(9, "Q");
    assert(subsequence(s4, s1) == 6);
    
    // Testing interleaving
    cout << "Testing interleaving" << endl;
    Sequence s5(s1);
    Sequence s6;
    s6.insert("L");
    interleave(s5, s6, s3); // s5 is longer
    s3.printItems();
    cout << "Correct answer is QLCMQ"<<endl;
    
    Sequence s7;
    interleave(s7, s5, s3); // s7 is empty
    s3.printItems();
    cout << "Correct answer is QCMQ"<<endl;
    
    interleave(s1, s4, s3);  // s4 is longer
    cout<<"s1"<<endl;
    s1.printItems();
    cout<<endl;
    s3.printItems();
    cout << "Correct answer is QECQMCQLBMQPQCMP"<<endl;   // 这里有问题！！！理论上是要有BQ穿插进来的，但是结果没有BQ
    // 出现问题的地方详见cpp实现
    return 0;
}
