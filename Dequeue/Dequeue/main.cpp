//
//  main.cpp
//  Dequeue
//
//  Created by Harsh Patel on 9/2/17.
//  Copyright © 2017 HP Tech. All rights reserved.
//

#include <iostream>
#include <string>
#include "dequeue.h"
using namespace std;


int main() {
    
    
 Bounded_Deque<string>words(4);
    
    words.push_back("hello");
    words.push_back("bye");
    words.push_back("pizza");
    words.push_back("ice");
    words.display();
 
    cout<<endl;
    cout<<endl;


    
    words.push_front("PLESSE");
    words.push_back("easy");
    words.pop_back();
    words.pop_front();
    
    cout<<endl;
    cout<<endl;
    
    words.push_front("PLESSE");
    words.push_back("easy");
    words.display();
    
    cout<<endl;
    cout<<endl;
    
    words.push_back("candy");
    words.push_front("chocho");
    words.clear();
    cout<<endl;
    cout<<endl;
    
    cout<<words.is_full()<<endl;
    cout<<words.is_empty()<<endl;
    cout<<words.length()<<endl;
    

    return 0;
}
