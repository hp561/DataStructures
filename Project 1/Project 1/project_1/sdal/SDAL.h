//
//  SDAL.h
//  Project 1
//
//  Created by Harsh Patel on 11/14/17.
//  Copyright © 2017 HP Tech. All rights reserved.
//

#include "List.h"
#ifndef SDAL_h
#define SDAL_h
using namespace COP3530;


///Simple Dynamic Array-based List (SDAL)

template <typename T>
class SDAL : List<T> {
private:
    T* list;
    size_t tail;
    size_t max;
public:
    SDAL(){
        
        tail=-1;
        list = new T[50];
        max=50;
        
    };
    
    SDAL(size_t cap){
        
        
        tail=-1;
        list = new T[cap]; //size of list
        max=cap;
        
    };
    
    ~SDAL(){
        delete [] list;
    };
    
    
    //move constructor
    SDAL(const SDAL&& here){
        
        tail=here.tail;
        list=here.list;
        here.tail=-1;
        here.list=NULL;
        
    };
    
    //copy constructor
    SDAL(const SDAL& other){
        
        clear();
        for (SDAL<int>::SDAL_Iterator it = other.begin(); it != other.end(); ++it)
        {
            push_back(*it);
        }
        
    };
    
    //move assignment
    SDAL& operator = (SDAL&& other){
        
        clear();
        tail=other.tail;
        
        other.tail = -1;
        other.list = NULL;
        
        return *this;
        
    }
    
    //copy assignment
    SDAL& operator = (const SDAL& other){
        
        clear();
        for (SDAL<int>::SDAL_Iterator it = other.begin(); it != other.end(); ++it)
        {
            push_back(*it);
        }
        
        return *this;
        
    }
    
    
    
    
    
    
    
    
    
    
    class SDAL_Iterator{
        T* current;
        size_t index=0;
    
        
    public:
        SDAL_Iterator(T* arr = nullptr, size_t i=0) : current(arr), index(i){}
        
        
        SDAL_Iterator& operator=(const SDAL_Iterator& other)
        {
            if(this==&current)
                return *this;
            index=other.index;
            current[index]=other.here[other.index];
            return *this;
            
        }
        bool operator==(const SDAL_Iterator& other)
        {
            if (index<0)
            {
                return false;
            }
            else
            {
                return current[index] == other.here[other.index];
            }
        }
        bool operator!=(const SDAL_Iterator& other)
        {
            if (index<0)
        
                return false;
            
            else
            {
                return index!=other.index;
            }
            
        }
    
        SDAL_Iterator& operator++() // prefix
        {
            ++index;
            
            return *this;
        }
        SDAL_Iterator operator++(int i) // postfix
        {
            SDAL_Iterator temp(*this);
            ++(*this);
            return temp;
        }
        T& operator*()
        {
            return current[index];
        }
        T* operator->()
        {
            return &*(SDAL<T>::SDAL_Iterator)*this;
        }
    };


    SDAL_Iterator begin (){


        return SDAL_Iterator(list,0);
    }

    SDAL_Iterator end(){


        return SDAL_Iterator(list,tail+1);

    }

    
    void insert (T element, size_t position){
        
        if(is_empty()){
            cout<<"The list was empty so this ("<<element<<") will be your first element"<<endl;
            list[++tail]=element;
            return;
        }
        
        else if (position<0 || position>length()){
            
            cout<<"Error. Out of bounds."<<endl;
            return;
        }
        
        else if ((position<length()&&position>=0) && length()!=max){
            //cout<<length()<<endl;
            for (size_t i = length(); i!=position; --i) {
                T temp = list[i-1];
                list[i]=temp;
            }
            list[position]=element;
            
            ++tail;
            
        }
        else {
            list[position]=element;
            
            ++tail;
            
        }
        
        size_t empty_slots=max-length();
        
        if(max==length()){
            size_t new_size= 1.5 * max;
            T* temp=list;
            list = new T[new_size];
            
            for (size_t i = 0 ; i!=max; i++) {
                
                list[i]=temp[i];
                
            }
            
            max=new_size;
        }
        
        
        if (max>=100 && empty_slots<length()/2) {
            size_t new_size = .75 * max;
            T* temp=list;
            list = new T[new_size];
            
            for (size_t i = 0 ; i!=max; i++) {
                
                list[i]=temp[i];
                
            }
            
            max=new_size;
            
        }
        
        
    };
    
    
    void push_back (T element){
        
        if(is_empty()){
            cout<<"The list was empty so this ("<<element<<") will be your first element"<<endl;
            list[++tail]=element;
            return;
        }
        
        size_t empty_slots=max-length();
        
        if(max==length()){
            size_t new_size= 1.5 * max;
            T* temp=list;
            list = new T[new_size];
            
            for (size_t i = 0 ; i!=max; i++) {
                
                list[i]=temp[i];
                
            }
            
            max=new_size;
        }
        
        
        if (max>=100 && empty_slots<length()/2) {
            size_t new_size = .75 * max;
            T* temp=list;
            list = new T[new_size];
            
            for (size_t i = 0 ; i!=max; i++) {
                
                list[i]=temp[i];
                
            }
            
            max=new_size;
            
        }
        
        list[++tail]=element;
        
        
        
    };
    
    void push_front (T element){
        
        if(is_empty()){
            cout<<"The list was empty so this ("<<element<<") will be your first element"<<endl;
            list[++tail]=element;
            return;
        }
        
        size_t empty_slots=max-length();
        
        if(max==length()){
            size_t new_size= 1.5 * max;
            T* temp=list;
            list = new T[new_size];
            
            for (size_t i = 0 ; i!=max; i++) {
                
                list[i]=temp[i];
                
            }
            
            max=new_size;
        }
        
        
        if (max>=100 && empty_slots<length()/2) {
            size_t new_size = .75 * max;
            T* temp=list;
            list = new T[new_size];
            
            for (size_t i = 0 ; i!=max; i++) {
                
                list[i]=temp[i];
                
            }
            
            max=new_size;
            
        }
        
        for (size_t i = length(); i!=0; --i) {
            T temp = list[i-1];
            list[i]=temp;
        }
        list[0]=element;
        
        ++tail;
        
    };
    
    void replace (T element, size_t position){
        
        if (is_empty()) {
            throw runtime_error("List is empty");
        }
        
        if(position>=0 && position<=tail){
            list[position]=element;
        }
        else
            cout<<"Error. Position "<<position<<" does not exist."<<endl;
        
    };
    
    T pop_back (){
        if (is_empty()) {
            cout<<"Error. List is empty"<<endl;
            return 0;
        }
        
        return list[tail--];
        
        
    };
    
    T pop_front(){
        
        if (is_empty()) {
            cout<<"Error. List is empty"<<endl;
            return 0;
        }
        T element = list[0];
        for (size_t i = 0; i!=length(); ++i) {
            T temp = list[i+1];
            list[i]=temp;
        }
        
        
        --tail;
        
        return element;
    };
    
    T item_at (size_t position){
        
        if (is_empty()) {
            throw runtime_error("List is empty");
        }
        
        if (position>=0 && position <length()) {
            return list[position];
        }
        else
            cout<<"Error. Position "<<position<<" does not exist"<<endl;
        return 0;
    };
    
    T peek_back (){
        if (is_empty()) {
            throw runtime_error("List is empty");
        }
        return list[tail];
    };
    
    T peek_front (){
        if (is_empty()) {
            throw runtime_error("List is empty");
        }
        
        return list[0];
    };
    
    
    bool is_empty (){
        
        if (tail==-1)
            return true;
        return false;
        
    };
    
    bool is_full(){
        
        if (length()==max)
            return true;
        return false;
        
    };
    
    
    size_t length(){
        return tail+1;
    };
    
    
    void clear(){
        
        tail=-1;
    }
    
    bool contains(T element, bool equals_function(T& element, T& findElement)){
        
        if(is_empty()){
            return false;
        }
        
        for(size_t i=0; i!=length();++i){
            
            if(equals_function(element,list[i]))
                return true;
        }
        
        
        
        return false;
        
    };
    
    T* contents(){
    
        T* contents = list;
        
        return contents;

        
    };
    
    T remove(size_t position){
        
        if (is_empty()) {
            throw runtime_error("List is empty");
        }
        
        
        T removed = list[position];
        
        for (size_t i= position; i!=length()-1; i++) {
            list[i]=list[i+1];
        }
        --tail;
        
        
        return removed;
    };
    
    
    void print(ostream &stream){
        
        if(is_empty()){
            stream<<"<empty list> \n";
            return;
        }
        stream<<"[";
        for (size_t i = 0; i!=length(); i++) {
            
            if (i==length()-1) {
                cout<<list[i]<<"]";
                break;
            }
            
            stream<<list[i]<<", ";
        }
        stream<<endl;
        stream<<"Lenght is: "<<length()<<endl;
    };
    
};

#endif /* SDAL_h */
