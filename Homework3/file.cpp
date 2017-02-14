//
//  main.cpp
//  Homework3
//
//  Created by Junnan Liu on 2/8/17.
//  Copyright © 2017 Junnan Liu. All rights reserved.
//
// pure virtual, non-pure virtual, non-virtua
// The File class must not have a default constructor. The only constructor you may declare for File must have exactly one parameter

#include <iostream>
#include <string>
using namespace std;

// Your declarations and implementations would go here


class File
{
public:
    File(string new_name) {m_name = new_name;}
    string name() const {return m_name;}
    virtual void open() const {cout<<"open test message";}
    virtual void redisplay() const {cout<<"refresh the screen";}
    virtual ~File() {}   // MUST add virtual here!!!!!!
    
private:
    string m_name;
};


class TextMsg : public File
{
public:
    TextMsg(string new_name):File(new_name){}
    ~TextMsg() {cout<<"Destroying "<<name()<<", a text message"<<endl;}
};

class Video : public File
{
public:
    Video(string new_name, int new_number): File(new_name), number(new_number) {}
    virtual void open() const {cout<<"play "<<number<<" second video";}
    virtual void redisplay() const {cout << "replay video";}
    ~Video() {cout<<"Destroying "<<name()<<", a video"<<endl;}
private:
    int number;
};


class Picture : public File
{
public:
    Picture(string new_name):File(new_name){}
    virtual void open() const {cout<<"show picture";}
    ~Picture() {cout<<"Destroying the picture "<<name()<<endl;}
};
