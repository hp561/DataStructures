//
//  PSLL.h
//  Project 1
//
//  Created by Harsh Patel on 11/14/17.
//  Copyright © 2017 HP Tech. All rights reserved.
//


#ifndef PSLL_h
#define PSLL_h
#include "List.h"
using namespace COP3530;


//Pool-using Singly-Linked List
template <typename T>
class PSLL : List<T> {
    
private:
    struct Node{
        T data;
        Node* next;
        
    };
   
    Node *head, *tail, *head2, *curr, *temp;
    
    size_t pool_length(){
        
        if (pool_is_empty()) {
            cout<<"List is empty. Can't calculate length!"<<endl;
            return 0;
        }
        
        
        size_t size = 0;
        
        curr=head2;
        while (curr->next) {
            curr=curr->next;
            ++size;
            
        }
        
        return size+1;
        
    };
    
    
public:
    
    PSLL(){
        
        head=NULL;
        head2=NULL;
        curr=NULL;
        
    };
    
    ~PSLL(){
        
        curr=head;
        while (curr!=NULL) {
            temp = curr->next;
            delete curr;
            curr=temp;
        }
        head = NULL;
    };
    
    
    
    //move constructor
    PSLL(const PSLL&& here){
        
        head=here.head;
        tail=here.tail;
        here.head=NULL;
        here.tail=NULL;
        
    };
    
    //copy constructor
    PSLL(const PSLL& other){
        
        clear();
        for (PSLL<int>::PSLL_Iterator it = other.begin(); it != other.end(); ++it)
        {
            push_back(*it);
        }
        
    };
    
    //move assignment
    PSLL& operator = (PSLL&& other){
        
        head=other.head;
        tail=other.tail;
        
        other.head = nullptr;
        other.tail = nullptr;
        
        return *this;
        
    }
    
    //copy assignment
    PSLL& operator = (const PSLL& other){
        
        clear();
        for (PSLL<int>::PSLL_Iterator it = other.begin(); it != other.end(); ++it)
        {
            push_back(*it);
        }
        
        return *this;
        
    }
    
    
    class PSLL_Iterator{
        Node* here;
    public:
        PSLL_Iterator(Node* node) : here(node){}
        PSLL_Iterator(){ here = nullptr; }
        
        PSLL_Iterator& operator=(const PSLL_Iterator& other)
        {
            here = other.here;
            return *this;
        }
        bool operator==(const PSLL_Iterator& other)
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
        bool operator!=(const PSLL_Iterator& other)
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
        
        PSLL_Iterator& operator++() // prefix
        {
            if (here!= nullptr)
            {
                here = here->next;
            }
            return *this;
        }
        PSLL_Iterator operator++(int) // postfix
        {
            PSLL_Iterator temp(*this);
            ++(*this);
            return temp;
        }
        T& operator*()
        {
            return here->data;
        }
        T* operator->()
        {
            return &*(PSLL<T>::PSLL_Iterator)*this;
        }
        
    };
    
    
    PSLL_Iterator begin (){
        
        
        return PSLL_Iterator(head);
    }
    
    PSLL_Iterator end(){
        
        
        return PSLL_Iterator(nullptr);
        
    }
    
    
    
    Node* findTail(){
        temp=head;
        while (temp->next) {
            temp=temp->next;
        }
        
        return temp;
    }
    
    void insert (T element, size_t position){
        size_t counter=0;
        
        if(is_empty()){
            
            Node* newNode=new Node;
            newNode->next=nullptr;
            newNode->data=element;
            head=newNode;
            
            
        }
        
        
        else if(position>length()||position<0){
            
            cout<<"Error. Out of bounds. Could not insert"<<endl;
        }
        
        else if(position==0){
            
            if (!pool_is_empty()) {
                curr=head2; //pool head
                head2=curr->next;  //relinking pool
                curr->next=head;  //
                head=curr;
            }
            
            else{
                
                Node* newNode=new Node;
                newNode->data=element;
                newNode->next=head;
                head=newNode;
                
            }
            
            
        }
        
        else if(position > length()){
            
            cout<<"Error. Out of bounds"<<endl;
            return;
            
        }
        
        else{
            
            if(!pool_is_empty()){
                
                temp=head2; //node we want to insert in "The List"
                head2=temp->next;
                temp->data=element;
                curr=head;
                while(++counter<position && curr->next!=NULL){
                    
                    curr = curr->next;
                    
                }
                
                temp->next=curr->next;
                curr->next=temp;
                
                
            }
            
            else{
                Node *newNode=new Node;
                newNode->data=element;
                curr=head;
                
                while(++counter<position && curr->next!=NULL){
                    
                    curr = curr->next;
                    
                }
                
                newNode->next=curr->next;
                curr->next=newNode;
                
            }
            
            
            
            
        }
        
        
        
    };
    
    
    void push_back (T element){
        
        if(is_empty()){
            Node* newNode=new Node;
            newNode->next=nullptr;
            head=newNode;
            return;
        }
        
        if(!pool_is_empty()){
            temp=head2; //node we want to insert from pool to "The List"
            head2=temp->next;
            temp->data=element;
            temp->next=nullptr;
            
            curr=head;
            while (curr->next) {
                curr=curr->next;
            }
            curr->next=temp;
            
        }
        
        else{
            
            Node *newNode= new Node;
            
            newNode->data=element;
            
            newNode->next=nullptr;
            curr=head;
            
            while (curr->next) {
                curr=curr->next;
            }
            
            curr->next=newNode;
            
            
        }
        
    };
    
    
    void push_front (T element){
        
        if(!pool_is_empty()){
            temp=head2; //node we want to insert from pool to "The List"
            head2=temp->next;
            temp->data=element;
            
            curr=head;
            temp->next=curr;
            head=temp;
        }
        
        else{
            Node *newNode= new Node;
            newNode->data=element;
            curr=head;
            newNode->next=curr;
            head=newNode;
        }
        
    };
    
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
    
    
    T pop_back (){
        
        if(is_empty()){
            
            cout<<"Error. The list is empty."<<endl;
            return 0;
            
        }
        
        curr=head;
        
        while(curr->next){
            temp=curr;
            curr=curr->next;
        }
        //after exiting while loop. temp will be second to last node in linked list and curr will be the last
        
        T popped = curr->data;    //set data from last node into variable T popped
        
        temp->next = curr->next;   //make second to last element point to whatever the last node was pointing to (which will be NULL)
        
        curr->next=head2;        //put popped node into memory pool by making it point to the head of unused nodes
        head2=curr;            //make new unused nodes list head = to the popped node (the first node in the memory pool linked list)
        
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
        
        curr->next=head2;
        head2=curr;
        
        return popped;
        
        
    };
    
    
    T item_at (size_t position){
        
        if (is_empty()) {
            
            cout<<"List is empty. Can't find location"<<endl;
            return 0;
        }
        
        
        T item;
        size_t counter=0;
        curr=head;
        
        if(position<0||position>(length()-1)){
            cout<<"Error. Out of bounds. Item at the "<<position<<"th position doesn't exist "<<endl;
            return 0;
        }
        
        
        while(curr->next && counter!=position){
            curr=curr->next;
            counter++;
        }
        
        item=curr->data;
        
        //cout<<item<<endl<<endl;
        
        
        return item;
    };
    
    T peek_back (){
        
        if (is_empty()) {
            cout<<"List is empty. Nothing to peek at"<<endl;
            return 0;
        }
        
        T peek_back=findTail()->data;
        return peek_back;
        
    };
    
    T peek_front (){
        
        if (is_empty()) {
            cout<<"List is empty. Nothing to peek at"<<endl;
            return 0;
        }
        
        return head->data;
        
        
    };
    
    void clear(){
        curr=head;
        
        while(curr ->next!=nullptr)
        {
            temp=curr->next;
            delete curr;
            curr = temp;
        }
        delete curr;
        head=nullptr;
        
        
        
        
        
    };
    
    
    bool pool_is_empty(){
        if (head2==NULL) {
            return true;
        }
        return false;
        
    };
    
    
    
    bool is_empty(){
        if(head==nullptr)
            return true;
        return false;
    };
    
    
    
    bool is_full(){
        
        return false;
    }
    
    
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
        
            T* contents=new T[length()];
        
        
            curr=head;
            size_t i =0;
        
        
            while (curr!=NULL) {
                
                contents[i]=curr->data;
                
                i++;
                curr=curr->next;
            }
        
            return contents;

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
            
            //set curr equal to head
            curr=head;
            
            //change head to curr's next node
            head=curr->next;
            
            //store value from curr
            T removed = curr->data;
            
            //relink curr to pool's head
            curr->next=head2;
            
            //change pool's head to curr
            head2=curr;
        
            
            return removed;
            
        }
        
        
        curr=head;
        Node* nextNode=new Node;
        Node* removeNode=new Node;
        size_t counter = 0;
        
        while (curr->next!=nullptr && counter!=position) {
            
            temp=curr;
            curr=curr->next;
            nextNode=curr->next;
            counter++;
        }
        
        //save data to be removed and returned
        T removed = curr->data;
        
        //set removeNode equal to node that needs to be removed
        removeNode=curr;
        
        //relink chain from curr
        curr=temp;
        curr->next=nextNode;
        
        //link unlinked node to pool's head
        removeNode->next=head2;
        
        //change pool lists head to removeNodes
        head2=removeNode;
        
        
        //if the list contains ≥ 100 items AND the pool contains more nodes than half the list size, reduce the number of pool nodes to half the list size (by deallocating the excess)
        if (length()>=100 && pool_length()>length()/2) {
            size_t reducedAmount = length()/2;
            size_t counter = 0;
            
            curr=head2;
            while (counter!=reducedAmount) {
                temp=curr->next;
                delete curr;
                curr = temp;
                counter++;
            }
            
            head2=curr;
            
        }
        
        
        
        return removed;

        //this is where ir ends
        
    };
    
    
    
    void print (ostream &stream){
        
        //cout<<length()<<endl;
        if(is_empty()){
            
            stream<<"<empty list> \n";
            return;
            
        }
        curr=head;
        stream<<"[";
        while (true) {
            if (curr->next==nullptr) {
                stream<<curr->data<<"]";
                break;
            }
            stream<<curr->data<<", ";
            curr=curr->next;
            
        }
        
        
    };
    
    
    
};


#endif /* PSLL_h */
