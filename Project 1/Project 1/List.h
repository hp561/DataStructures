//
//  list.h
//  Project 1
//
//  Created by Harsh Patel on 9/14/17.
//  Copyright © 2017 HP Tech. All rights reserved.
//

#ifndef list_h
#define list_h
#include <iostream>
#include <stdexcept>

using namespace std;

namespace COP3530 {

    template<typename T>
    bool equals_function(T&element, T&findElement){
    
        if(element==findElement)
            return true;
        return false;
        
    };

template <typename T>
class List {
    
public:

    virtual void insert (T element, size_t position)=0;

    virtual void push_back (T element)=0;

    virtual void push_front (T element)=0;

    virtual void replace (T element, size_t position)=0;

    virtual T pop_back ()=0;

    virtual T pop_front()=0;

    virtual T item_at (size_t position)=0;

    virtual T peek_back ()=0;

    virtual T peek_front ()=0;

    virtual bool is_empty ()=0;

    virtual bool is_full ()=0;

    virtual size_t length()=0;

    virtual void clear()=0;

    virtual bool contains(T element, bool equals_function(T&element, T&findElement))=0;

    virtual void print (ostream &stream)=0;

    virtual T* contents()=0;

    virtual T remove(size_t position)=0;
    
};


//this ends the namespace COP3530
}
#endif /* list_h */
