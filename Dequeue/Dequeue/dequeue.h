//
//  Header.h
//  Dequeue
//
//  Created by Harsh Patel on 9/2/17.
//  Copyright © 2017 HP Tech. All rights reserved.
//


using namespace std;

#ifndef Header_h
#define Header_h


template <typename T>

 class Deque{
 
     
     
 public:
     
    
     virtual void push_front(const T element)=0;
     virtual void push_back(const T element)=0;
     virtual void pop_front()=0;
     virtual void pop_back()=0;
     virtual T peek_front()=0;
     virtual T peek_back()=0;
     virtual bool is_empty()=0;
     virtual bool is_full()=0;
     virtual int length()const=0;
     virtual void clear()=0;
     virtual void display()=0;

};

template <typename T>
class Bounded_Deque: public Deque<T>{
    
private:
    int element_count;  //keeps track of elements in deque
    T*container;        //array to hold elements
    int max;            //limit on array
    int head, tail;     //keeps track of indices
    
public:
    Bounded_Deque(int max){
        
        head=-1;
        tail=-1;
        this->max=max;
        element_count=0;
        container=new T[max];   //this should be where it sets limit on array
    };
    
    ~Bounded_Deque(){
        delete []container;
        
    };
    
    //return number of elements
    int length()const {
        
        return element_count;
        
    };
    
    //puts element to the front
    void push_front(const T element) {
        
        if(is_full()){
            cout<<"Full can't add"<<endl;
            return;
        
        }
        else if(is_empty()){
            
            head=0;
            
            container[++tail]=element;
            
        }
        else if(head==0){
        
            head=this->max-1;
        
        }
        else if (head!=0){
            
            container[--head]=element;
            
        }
        
    };
    
    //determines if deque is empty
    bool is_empty() {
        
        return element_count==0?1:0;
        
    };
    
    //puts element in the bottom of deque
    void push_back(const T element) {
        
        
        if(is_full()){
        
            cout<<"Deque is full"<<endl;
            return;
        
        
        }
        
        else if(is_empty()){
            
            head++;
            tail++;
        }
        else if (tail==max-1)
            tail=0;
        
        else{
            
            tail=tail+1;
        }
        
        container[tail]=element;
        element_count++;
        
    };
    
    //removes last most element
    void pop_back() {
        
        if(head==-1){
            
            cout<<"Error. Deque Empty"<<endl;
            return;
            
        }
        else{
            if(head==tail){
                head=tail=-1;
                
            }
            else tail--;
        }
        
    };
    
    //removes front most element
    void pop_front() {
        if (tail==-1){
            cout<<"Impossible action. Empty deque"<<endl;
            return;
        }
        else {
            
            if (tail==head){
                
                head=tail=-1;
                return;
                
            }
            
            else
                head++;
        }
        
    };
    
    //returns lasts most element
    T peek_back() {
        
        return container[tail];
    };
    
    //returns front most element
    T peek_front() {
        
        return container[head];
    };
    
    //displays all elements in deque
    void display() {
 
        
        
        if(head==-1)
        {
            cout<<"Dequeue is empty";
        }
        else
        {
            for(int i=head;i<=tail;i++)
            {
                cout<<container[i]<<endl;
            }
        }
    };
    
    //checks if the deque is empty
    bool is_full() {
        return ((head == 0 && tail == max-1)||head == tail+1);
    }
    
    //resets deque
    void clear(){
    
        head=-1;
        tail=-1;
        element_count=0;
    
    }
    
};




#endif /* Header_h */
