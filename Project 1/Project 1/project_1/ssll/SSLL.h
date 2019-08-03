//
//  SSLL.h
//  Project 1
//
//  Created by Harsh Patel on 11/14/17.
//  Copyright © 2017 HP Tech. All rights reserved.
//

#ifndef SSLL_h
#define SSLL_h
#include "List.h"
using namespace COP3530;

template <class T>
class SSLL : List<T> {
    
private:
    
    
    struct Node{
        
        T data;
        Node *next;
        
    };
    
    Node *head,*curr, *temp, *tail;
    
public:
    
    SSLL(){
        
        tail=nullptr;
        head=NULL;
        curr=NULL;
        
        
    };
    
    ~SSLL(){
        
        curr=head;
        while (curr!=NULL) {
            temp = curr->next;
            delete curr;
            curr=temp;
        }
        head = NULL;
    };
    
    
    //move constructor
    SSLL(const SSLL&& here){
        
        head=here.head;
        tail=here.tail;
        here.head=NULL;
        here.tail=NULL;
        
    };
    
    //copy constructor
    SSLL(const SSLL& other){
        
        clear();
        for (SSLL<int>::SSLL_Iterator it = other.begin(); it != other.end(); ++it)
                {
                    push_back(*it);
                }
        
    };
    
    //move assignment
    SSLL& operator = (SSLL&& other){
        
        head=other.head;
        tail=other.tail;
        
        other.head = nullptr;
        other.tail = nullptr;
        
        return *this;
        
    }
    
    //copy assignment
    SSLL& operator = (const SSLL& other){
    
        clear();
        for (SSLL<int>::SSLL_Iterator it = other.begin(); it != other.end(); ++it)
        {
            push_back(*it);
        }
        
        return *this;
        
    }
    
    class SSLL_Iterator{
        Node* here;
    public:
        SSLL_Iterator(Node* node) : here(node){}
        SSLL_Iterator(){ here = nullptr; }
        
        SSLL_Iterator& operator=(const SSLL_Iterator& other)
        {
            here = other.here;
            return *this;
        }
        bool operator==(const SSLL_Iterator& other)
        {
            if (here == nullptr || other.here == nullptr)
            {
                return false;
            }
            else
            {
                return here->_data == other.here->_data;
            }
        }
        bool operator!=(const SSLL_Iterator& other)
        {
            if (here == nullptr)
            {
                return false;
            }
            else
            {
                return here!=other.here;
            }
        }
        
        SSLL_Iterator& operator++() // prefix
        {
            if (here!= nullptr)
            {
                here = here->next;
            }
            return *this;
        }
        SSLL_Iterator operator++(int) // postfix
        {
            SSLL_Iterator temp(*this);
            ++(*this);
            return temp;
        }
        T& operator*()
        {
            return here->data;
        }
        T* operator->()
        {
            return &*(SSLL<T>::SSLL_Iterator)*this;
        }
        
    };
    
    
    SSLL_Iterator begin (){
        
       
        return SSLL_Iterator(head);
    };
    
    SSLL_Iterator end(){
        
        
        return SSLL_Iterator(nullptr);
        
    };
    
    
    
    Node* findTail(){
        temp=head;
        while (temp->next) {
            temp=temp->next;
        }
        
        return temp;
    }
    
    void insert (T element, size_t position){
        
        Node *newNode= new Node;
        
        newNode->data=element;
        
        size_t counter=0;
        
        if(is_empty()){
            
            head=newNode;
            head->next=nullptr;
            return;
            
        }
        
        if(position==0){
            
            newNode->next=head;
            head=newNode;
            
            
        }
        
        else if(position > length()){
            
            cout<<"Error. Out of bounds"<<endl;
            return;
            
        }
        
        else{
            
            curr=head;
            
            while(++counter<position && curr->next!=NULL){
                
                curr = curr->next;
                
            }
            
            newNode->next=curr->next;
            curr->next=newNode;
            
        }
        
        
        
    };
    
    
    void push_back (T element){
        
        Node *newNode= new Node;
        
        newNode->data=element;
        
        newNode->next=nullptr;
        
        if(is_empty()){
            
            newNode->next=nullptr;
            head=newNode;
            return;
        }
        
        
        curr=head;
        
        
        while (curr->next) {
            curr=curr->next;
        }
        
        curr->next=newNode;
        
    };
    
    void push_front (T element){
        
        Node *newNode= new Node;
        newNode->data=element;
        
        if(is_empty()){
            
            newNode->next=nullptr;
            head=newNode;
            return;
        }
        
        curr=head;
        
        newNode->next=curr;
        head=newNode;
        
    }
    
    
    void replace (T element, size_t position){
        if (position>=length()) {
            cout<<"Error. Poaition "<<position<<" does not exist"<<endl;
            return;
        }
        
        size_t counter = -1;
        curr=head;
        
        while(++counter!=position && curr->next){
            
            curr=curr->next;
            
            
        }
        
        curr->data=element;
        
    };
    
    
    
    T pop_back () {
        
        if(is_empty()){
            
            cout<<"Error. The list is empty."<<endl;
            return 0;
            
        }
        
        Node* prev= new Node;
        
        curr=head;
        
        while(curr->next){
            prev=curr;
            curr=curr->next;
        }
        
        T popped = curr->data;
        
        prev->next = curr->next;
        
        
        free(curr);
        
        
        return popped;
    };
    
    T pop_front() {
        
        if(is_empty()){
            
            cout<<"Error. The list is empty."<<endl;
            return 0;
            
        }
        
        curr=head;
        
        head=curr->next;
        
        T popped = curr->data;
        
        free(curr);
        
        return popped;
        
        
    };
    
    
    
    T item_at (size_t position){
        
        
        T item;
        size_t counter=0;
        curr=head;
        
        if(position<0 || position>(length()-1)){
            cout<<"Error. Out of bounds. Item at the "<<position<<"th position doesn't exist "<<endl;
            return 0;
        }
        
        
        while(curr->next && counter!=position){
            curr=curr->next;
            counter++;
        }
        
        item=curr->data;
        
        //      cout<<item<<endl<<endl;
        
        
        return item;
        
    }
    
    
    T peek_back (){
        
        if (is_empty()) {
            cout<<"List is empty. Nothing to peek at"<<endl;
            return 0;
        }
        
        curr=head;
        
        while(curr->next){
            
            curr=curr->next;
            
        }
        
        T peekBack=curr->data;
        
        return peekBack;
        
    };
    
    
    
    T peek_front (){
        
        if (is_empty()) {
            cout<<"List is empty. Nothing to peek at"<<endl;
            return 0;
        }
        return head->data;
        
    };
    
    bool is_empty(){
        
        if(head==NULL)
            return 1;
        else return 0;
    };
    
    bool is_full (){
        
        return false;
    };
    
    size_t length(){
        
        if (is_empty()) {
            cout<<"List is empty. Can't calculate length!"<<endl;
            return 0;
        }
        size_t size = 0;
        
        curr=head;
        while (curr->next) {
            curr=curr->next;
            ++size;
            
        }
        
        return size+1;
        
    };
    
    void clear(){
        curr=head;
        Node* temp=new Node();
        while(curr ->next!=nullptr)
        {
            temp=curr->next;
            delete curr;
            curr = temp;
        }
        delete curr;
        head=nullptr;
        
        
    };
    
    bool contains(T element, bool equals_function(T& element, T& findElement)){
        
        
        if (is_empty()) {
            return false;
        }
        
        curr=head;
        
        while(curr!=NULL){
            
            if(equals_function(element, curr->data))
                return true;
            curr=curr->next;
            
        }
        
        
        return false;
        
    };
    T* contents(){
        
        T* print=new T[length()];
        curr=head;
        size_t i =0;
        
        
        while (curr!=NULL) {
          
            print[i]=curr->data;
            
            i++;
            curr=curr->next;
        }
        
        
        
        return print;
    };
    
    T remove(size_t position){
        
        if (is_empty()) {
            cout<<"Error. it's empty"<<endl;
            return 0;
        }
        
        
        if(position>=length()||position<0){
            
            cout<<"Invalid position"<<endl;
            return 0;
        }
        
        if (position == 0) {
            curr=head;
            T removed = head->data;
            
            delete head;
            head=curr->next;
            
            return removed;
            
        }
        
        
        curr=head;
        Node* nextNode=new Node;
        
        size_t counter = 0;
        
        while (curr->next!=nullptr && counter!=position) {
            
            temp=curr;
            curr=curr->next;
            nextNode=curr->next;
            counter++;
        }
        
        T removed = curr->data;
        delete curr;
        curr=temp;
        curr->next=nextNode;
        
        return removed;
        
    };
    
    
    void print(ostream &stream){
        
        if(is_empty()){
            
            stream<<"<empty list> \n";
            return;
            
        }
        curr=head;
        stream<<"[";
        while (curr!=NULL) {
            if (curr->next==nullptr) {
                stream<<curr->data<<"]";
                break;
            }
            stream<<curr->data<<", ";
            curr=curr->next;
            
        }
    };
};

#endif /* SSLL_h */
