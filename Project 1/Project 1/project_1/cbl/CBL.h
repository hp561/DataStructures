//
//  CBL.h
//  Project 1
//
//  Created by Harsh Patel on 11/14/17.
//  Copyright © 2017 HP Tech. All rights reserved.
//
#include "List.h"
#ifndef CBL_h
#define CBL_h
using namespace COP3530;



template <typename T>
class CBL:List<T>{
    
private:
    
    T*list;
    size_t head;
    size_t tail;
    size_t max;
    
    //if full create this array
    void maximize (){
        size_t new_size= 1.5 * max;
        T* temp=list;
        list = new T[new_size];
     
        size_t j = 0;      //will place in appropriate indices starting from 0
        for (size_t i = head ; i!=tail; i++) {
            
            if (i==max) {
                i=0;
            }
            list[j]=temp[i];
    
            ++j;
         
            
        }
        delete temp;
        max=new_size;
        
    };
    
//whenever the array's size is ≥ 100 slots and fewer than half the slots are used, allocate a new array 75% the size of the original, copy the items over to the new array, and deallocate the original
    void miniMaximize (){
        
        size_t new_size = .75 * max;
        T* temp=list;
        list = new T[new_size];
        
        for (size_t i = 0 ; i!=new_size; i++) {
            list[i]=temp[i];
        }
        
        max=new_size;
        
    };
    
    
    
public:
    
    CBL(size_t maxVal){
        list=new T[maxVal];
        max=maxVal;
        head=0;
        tail=0;
        
    };
    
    CBL(){
        list=new T[50];
        max=50;
        head=0;
        tail=0;
        max=50;
        
    };
    
    ~CBL(){
        
        delete [] list;
    };
    
    
    //move constructor
    CBL(const CBL&& here){
        
        tail=here.tail;
        head=here.head;
        list=here.list;
        here.tail=0;
        here.head=0;
        here.list=NULL;
        
    };
    
    //copy constructor
    CBL(const CBL& other){
        
        clear();
        for (CBL<int>::CBL_Iterator it = other.begin(); it != other.end(); ++it)
        {
            push_back(*it);
        }
        
    };
    
    //move assignment
    CBL& operator = (CBL&& other){
        
        clear();
        tail=other.tail;
        head=other.head;
        other.tail = 0;
        other.head =0;
        other.list = NULL;
        
        return *this;
        
    }
    
    //copy assignment
    CBL& operator = (const CBL& other){
        
        clear();
        for (CBL<int>::CBL_Iterator it = other.begin(); it != other.end(); ++it)
        {
            push_back(*it);
        }
        
        return *this;
        
    }
    
    
    
    class CBL_Iterator{
        T* current;
        size_t head=0;
   
        size_t max = 0;
        
    public:
        CBL_Iterator(T* arr = nullptr, size_t h=0, size_t m =0) : current(arr), head(h), max(m) {}
        
        
        CBL_Iterator& operator=(const CBL_Iterator& other)
        {
            if(this==&current)
                return *this;
            
            current[head]=other.here[other.head];
            return *this;
            
        }
        bool operator==(const CBL_Iterator& other)
        {
            
          
                return current[head] == other.here[other.head];
            
        }
        bool operator!=(const CBL_Iterator& other)
        {
           
                return head!=other.head;
           
            
        }
        
        CBL_Iterator& operator++() // prefix
        {
            if (head==max-1) {
                head =0;
            }
           else ++head;
            
            return *this;
        }
        CBL_Iterator operator++(int i) // postfix
        {
            CBL_Iterator temp(*this);
            ++(*this);
            return temp;
        }
        T& operator*()
        {
            return current[head];
        }
        T* operator->()
        {
            return &*(CBL<T>::CBL_Iterator)*this;
        }
    };
    
    
    CBL_Iterator begin (){
        
        
        return CBL_Iterator(list,head, max);
    }
    
    CBL_Iterator end(){
        
        
        return CBL_Iterator(list,tail, max);
        
    }

    
    
    
    
    
    
    void insert (T element, size_t position){
        
        if(is_empty()){
            cout<<"The list was empty so "<<element<<" will be your first elemenet!"<<endl;
            list[tail++]=element;
            return;
        }
        
        try {
            
            if (position<0 || position>length()) {
                throw 0;
            }
            
        }
        catch(int e){
        
            cout<<"Invalid Index"<<endl;
            return;
            
        }
        
        
        if (position>=0 && position<length()) {
            
            for (size_t i=length(); i!=position; i--) {
                list[i]=list[i-1];
            }
            
            list[position]=element;
            ++tail;
        }
        else{
            list[position]=element;
            ++tail;
        }
        
        size_t empty_slots=max-length();
        
        if(length()==max-1){
            maximize();
        }
        
        
        if (max>=100 && empty_slots<length()/2) {
        
            miniMaximize();
            
        }
        
        
    };
    
   
    void push_back (T element){
   
        if (tail+1==head) {
            maximize();
            head=0;
            list[tail++]=element;
            return;
            
        }
        
        
        size_t empty_slots=max-length();

        if(length()==max-1){
            maximize();
            head=0;
        }
        
        
        if (max>=100 && empty_slots<length()/2) {
            
            miniMaximize();
            head=0;
        }
        
           list[tail++]=element;
        
    };
    
    void push_front (T element){
        
        size_t empty_slots=max-length();
        
        if (is_empty()) {
            list[tail++]=element;
            
            if(length()==max-1){
                maximize();
                head=0;
            }
            
            
            if (max>=100 && empty_slots<length()/2) {
                
                miniMaximize();
                head=0;
                
            }
            return;
        }
        
        
        if(head-1==tail){
    
            maximize();
            head=max-1;
            list[head]=element;
            return;
        
        }
       
        
        if (head==0) {
            head=max-1;
            list[head]=element;
        }
        
        else
            list[--head]=element;
        
       
        
    };
    
    void replace (T element, size_t position){
        
        try{
            if (is_empty()) {
            throw 0;
            }
            
            
            if (position<0 || position>=length()) {
                throw 1;
            }
        }
        catch(int x){
            if(x==0)
            cout<<"Error!! List is empty!"<<endl;
            else
                cout<<"Error!! Invalid index!"<<endl;
            return;
        }
        
        if (head==0){
            
            list[position]=element;
            return;
            
        }

        else{
            
            size_t counter =head;
            size_t i = 0;
            while (counter!=tail) {
                
                if (counter==max) {
                    counter=0;
                }
                
                if (i==position) {
                    break;
                }
                ++counter;
                ++i;
            }
            
            list[counter]=element;

        }
    
    };
    
    T pop_back (){
        try{
            if (is_empty()) {
                throw 0;
            }
        
        }
        catch(int x){
            throw runtime_error("List is empty!");
        }
        
        T popped = list[tail-1];
        --tail;
        return popped;
        
    };
    
    T pop_front(){
        try{
            if (is_empty()) {
                throw 0;
            }
            
        }
        catch(int x){
            throw runtime_error("List is empty!");
        }
        
        T popped = list[head];
        
        if (head+1==max) {
            head=0;
            return popped;
        }
        
        else
            ++head;
        
        return popped;
        
        
    };
    
    T item_at (size_t position){
        try{
            if (is_empty()) {
                throw 0;
            }
            
            
            if (position<0 || position>=length()) {
                throw 1;
            }
        }
        catch(int x){
            if(x==0)
                throw runtime_error("Error!! List is empty!");
            else
                throw runtime_error("Error!! Invalid index!");
        }
        
        if (head==0){
            
            return list[position];
         
            
        }
        
        else{
            
            size_t counter =head;
            size_t i = 0;
            while (counter!=tail) {
                
                if (counter==max) {
                    counter=0;
                }
                
                if (i==position) {
                    break;
                }
                ++counter;
                ++i;
            }
            
            return list[counter];
            
        }
    
    };
    
    T peek_back (){
        try{
            if (is_empty()) {
                throw 0;
            }
            
        }
        catch(int x){
            throw runtime_error("List is empty!");
        }
        
        return list[tail-1];
    };
    
    T peek_front (){
        
        try{
            if (is_empty()) {
                throw 0;
            }
            
        }
        catch(int x){
            throw runtime_error("List is empty!");
        }
        
        return list[head];
    };

    bool is_empty (){
        
        if (head==tail) {
            return true;
        }
        
        return false;
    };
    
    bool is_full (){
        return false;
        
    };
    
    size_t length(){
        
        size_t length = 0;
        if (tail>head) {
            return  length= tail - head;
        }
        
        else
            
            return  length = (tail+ max) - head;
        
        
    };
    
    void clear(){
        head=0;
        tail=0;
    };
    
    
    bool contains(T element, bool equals_function(T&element, T&findElement)){
        
        
        if(is_empty())
            return false;
            
        for(size_t i=head; i!=tail;++i){
            
            if (i==max) {
                i=0;
            }
            
            if(equals_function(element,list[i]))
                return true;
        }
        
        
        
        return false;
        
        
    };
    
    T* contents(){
        
        if (is_empty()) {
            throw runtime_error("List is empty");
        }
        
        T *contents = new T[max];
        size_t k = 0;
        for (size_t i = head; i!=tail; ++i) {
            
            if(i==max)
                i=0;
            
            contents[k]=list[i];
            ++k;
            
        }
        
        return contents;
    };
    
    T remove(size_t position){
        try{
            if (is_empty()) {
                throw 0;
            }
            
            
            if (position<0 || position>=length()) {
                throw 1;
            }
        }
        catch(int x){
            if(x==0)
                throw runtime_error("Error!! List is empty!");
            else
                throw runtime_error("Error!! Invalid index!");
        }
        

            size_t counter =head;  //keeps track of index in head
            size_t i = 0;          //keeps track of how many times the program needs to go to next index in order to reach correct position
            while (counter!=tail) {
                
                if (counter==max) {
                    counter=0;
                }
                
                //position is found. exit loop
                if (i==position) {
                    break;
                }
                ++counter;
                ++i;
            }
        
            T removed = list[counter];
            
            for (size_t i=counter; i!=tail-1; ++i) {
                
                if (i+1==max) {
                    list[i]=list[0];
                    continue;
                }
                
                if (i==max) {
                    i=0;
                }
                
                list[i]=list[i+1];
                
            }
            --tail;
            return removed;
 
    };
    
    void print (ostream &stream){
        
        stream<<"Tail: "<<tail<<endl;
        stream<<"Head: "<<head<<endl;
        stream<<max<<endl;
        
        try{
            if(is_empty())
                throw 0;
        }
        catch(int x){
             stream<<"<empty list> \n";
            return;
        }
        
        stream<<"[";
        size_t i =head;
        
        while(i!=tail) {
            
        
            if (i==tail-1) {
                cout<<list[i]<<"]";
                break;
            }
            
            if (i==max) {
                i=0;
            }
            
            stream<<list[i]<<", ";
            i++;
        }
        stream<<endl;
        stream<<"Head is: "<<head<<endl;
         stream<<"Tail is: "<<tail<<endl;
   
    };
    
};



#endif /* CBL_h */
