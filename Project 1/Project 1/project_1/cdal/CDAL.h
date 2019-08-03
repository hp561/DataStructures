//
//  CDAL.h
//  Project 1
//
#include "List.h"
using namespace COP3530;
#ifndef CDAL_h
#define CDAL_h

template <typename T>
class CDAL:List<T> {
    
private:
    
    struct Node{
        
        T* list=new T[50];
        Node *next;
    };
    
    Node*head, *curr,*temp,*tail;
    size_t tailIndex;
    size_t max;
    size_t numberOfNodes;
    
    void addANode(){
        
        curr=head;
        
        while (curr->next) {
            curr=curr->next;
        }
        
        Node *newNode=new Node;
        newNode->next=nullptr;
        curr->next=newNode;
        numberOfNodes++;
        
    };
    
    
    
public:
    
    CDAL(){
        
        tailIndex=0;
        numberOfNodes=0;
        head=NULL;
        
        
    };
    
    
    
    ~CDAL(){
        
        curr=head;
        while (curr!=NULL) {
            temp = curr->next;
            delete curr;
            curr=temp;
        }
        head = NULL;
    };
    
    //move constructor
    CDAL(const CDAL&& here){
        
        head=here.head;
        tail=here.tail;
        here.head=NULL;
        here.tail=NULL;
        
    };
    
    //copy constructor
    CDAL(const CDAL& other){
        
        clear();
        for (CDAL<int>::CDAL_Iterator it = other.begin(); it != other.end(); ++it)
        {
            push_back(*it);
        }
        
    };
    
    //move assignment
    CDAL& operator = (CDAL&& other){
        
        head=other.head;
        tail=other.tail;
        
        other.head = nullptr;
        other.tail = nullptr;
        
        return *this;
        
    }
    
    //copy assignment
    CDAL& operator = (const CDAL& other){
        
        clear();
        for (CDAL<int>::CDAL_Iterator it = other.begin(); it != other.end(); ++it)
        {
            push_back(*it);
        }
        
        return *this;
        
    }
    
    
    class CDAL_Iterator{
        Node* here;
        size_t tail = 0;
        size_t max = 0;
        
    public:
        CDAL_Iterator(Node* node, size_t i=0, size_t m=0) : here(node), tail(i), max(m){}
        CDAL_Iterator(){ here = nullptr; }
        
        CDAL_Iterator& operator=(const CDAL_Iterator& other)
        {
            if(this==&here)
                return *this;
            here = other.here;
            tail = other.tail;
            max=other.max;
            return *this;
        }
        bool operator==(const CDAL_Iterator& other)
        {
            if (here == nullptr || other.here == nullptr)
            {
                return false;
            }
            else
            {
                return here->_list[tail] == other.here->_list[tail];
            }
        }
        bool operator!=(const CDAL_Iterator& other)
        {
            if (here == nullptr || tail==max)
            {
                return false;
            }
            else
            {
                
                return here!=other.here;
            }
        }
        
        CDAL_Iterator& operator++() // prefix
        {
            if (tail%50==49)
            {
                here = here->next;
            }
             ++tail;
            return *this;
        }
        CDAL_Iterator operator++(int) // postfix
        {
            CDAL_Iterator temp(*this);
            ++(*this);
            return temp;
        }
        T& operator*()
        {
            return here->list[tail%50];
        }
        T* operator->()
        {
            return &(operator*());
        }
        
    };
    
    
    CDAL_Iterator begin (){
        
        
        return CDAL_Iterator(head,0,length());
    };
    
    CDAL_Iterator end(){
        
        
        return CDAL_Iterator(nullptr);
        
    };
    
    

    void insert (T element, size_t position){
       
        size_t counter = 0;
        size_t nodeLocation = position/50;    //which node to insert
        size_t locationInNode = position%50;  //position within node array
        //if list is empty create a node and put value in first index
        if(is_empty()){
            
            Node *newNode=new Node;
            newNode->list[tailIndex++]=element;
            newNode->next=nullptr;
            head=newNode;
            numberOfNodes++;
        }
        
        //if position is greater than next index or negative give an error message
        else if (position>tailIndex || position<0){
            cout<<"Error. Out of bounds"<<endl;
            return;
        }
        
        //if pushed to back
        else if(tailIndex==position){
        
                curr=head;
                
                //will loop until counter = the correct node to be in (counter starts at 0)
                while(counter!=nodeLocation){
                        curr=curr->next;
                    counter++;
                }
                    curr->list[locationInNode]=element;
                    ++tailIndex;
        }
        
        
       //inserting between values
        else if (position>=0 && position<tailIndex){

            T temp;
            T temp2;
            T temp3;
            bool check =true;  //will check if we need to shift other array lists
            
            curr=head;
            
            
            while (curr!=NULL && counter!=nodeLocation) {
                curr=curr->next;
                counter++;
                
            }
            
            if(numberOfNodes==counter){
                
                for (size_t i =length() ; i!=locationInNode; i--) {
                    temp=curr->list[i-1];
                    curr->list[i]=temp;
                }
                curr->list[locationInNode]=element;
                check=false;
            }
            
            //this will check if initial placement of value is inserted before shifting other array lists
            bool initial=true;
            while(check){
           
            
                if(counter==numberOfNodes)
                    break;
                
                if(initial){
                
                temp2=curr->list[49];
                 
                
                for (size_t i =49; i!=locationInNode; i--) {
                    temp=curr->list[i-1];
                    curr->list[i]=temp;
                    }
                    
                curr->list[locationInNode]=element;
                    counter++;
                    tailIndex++;
                    initial=false;
                    
                }
                
                else{
               
                temp3=curr->list[49];
                
                for (size_t i = 49; i!=0; i--) {
                    
                    temp=curr->list[i-1];
                    curr->list[i]=temp;
                }
                curr->list[0]=temp2;
                temp2=temp3;
                counter++;
                
            }

                curr=curr->next;

            }
            
        }
        
        //if the node is full this will create a new node
        if(length()%50==0){
            addANode();
        }
    
    
    };
    
    
  
   
    void push_back (T element){
        
        if(is_empty()){
            
            Node *newNode=new Node;
            newNode->list[tailIndex++]=element;
            newNode->next=nullptr;
            head=newNode;
            numberOfNodes++;
            
            return;
        }
        

        size_t counter =0;
        size_t nodeLocation = tailIndex/50;
        size_t locationInNode = tailIndex%50;
       
        curr=head;
        
        //will loop until counter = the correct node to be in (counter starts at 0)
        while(counter!=nodeLocation){
            curr=curr->next;
            counter++;
        }
        curr->list[locationInNode]=element;
        ++tailIndex;
        
        if(tailIndex%50==0){
            addANode();
        }
        
    };
    
    void push_front (T element){
        
        if(is_empty()){
        
            Node *newNode=new Node;
            newNode->list[tailIndex++]=element;
            newNode->next=nullptr;
            head=newNode;
            numberOfNodes++;
            
            return;
        }
        
        size_t counter = 0;
        T temp;
        T temp2;
        T temp3;
        bool initial=true;
        
        curr=head;
        
        //if only one node in list
        if(numberOfNodes==1){
            
            
            for (size_t i =length(); i!=0;--i) {
                
                temp=curr->list[i-1];
                curr->list[i]=temp;
            
            }
            
            curr->list[0]=element;
            ++tailIndex;
            
            if(length()%50==0){
                addANode();
                ++numberOfNodes;
            }
            
            return;
            
        }
        
        else{
            
            while(curr!=NULL){
                
                if (counter==numberOfNodes) {
                    break;
                }
                
                //initial insert before shifting anything
                 if(initial){
        
                    temp2=curr->list[49];
                    for (size_t i =49; i!=0;--i) {
                
                        temp=curr->list[i-1];
                        curr->list[i]=temp;
                    
                }
                    curr->list[0]=element;
                    ++tailIndex;
                    ++counter;
                    initial=false;
                     
                    
                }
                
                //keep saving last value and shifting everyhing down
                else{
                    
                    //store curr last value
                
                    temp3=curr->list[49];
                    for (size_t i =49; i!=0;--i) {
                        
                        temp=curr->list[i-1];
                        curr->list[i]=temp;
                        
                    }
                    
                    //swap last node last value for curr node first value and store curr last value into temp 2
                    curr->list[0]=temp2;
                    temp2=temp3;
                    ++counter;
                    
                }
            
                curr=curr->next;
            }
            
    
            if(length()%50==0){
                addANode();
            }
            
        }
        
        
    };
    
    
    
    void replace (T element, size_t position){
        
        if(is_empty()){
            
            cout<<"Error. The list is empty."<<endl;
            return;
            
        }
        
        
        size_t counter = 0;
        size_t nodeLocation = position/50;    //which node to insert
        size_t locationInNode = position%50;  //position within node array
        
        curr=head;
        
        while(counter!=nodeLocation){
            curr=curr->next;
            counter++;
        }
   
//        cout<<"Node Location: "<<nodeLocation<<endl;
//        cout<<"Location: "<<locationInNode<<endl;
        

        curr->list[locationInNode]=element;
       
    };
    
    
    T pop_back (){
        
        
        if(is_empty()){
            
            cout<<"Error. The list is empty."<<endl;
            return 0;
            
        }
        
        size_t lastVal=(tailIndex%50)-1;
        size_t nodeLocation = tailIndex/50;
        size_t counter=0;
        
        curr=head;
        //go to last node
        while(counter!=nodeLocation){
            curr=curr->next;
            counter++;
        }
        
        //save last value in node
        T popped = curr->list[lastVal];
        
        //decrease length
        --tailIndex;
        
        return popped;
    };
    
    T pop_front(){
        
        if(is_empty()){
            
            cout<<"Error. The list is empty."<<endl;
            return 0;
            
        }
        
        size_t counter=0;
        curr=head;
        
        //save first value
        T popped=curr->list[0];
        
        //loop will end when all nodes have been shofted up
        while (counter!=numberOfNodes) {
            
            temp=curr;
        
            //perform action when on last node
            if(counter==numberOfNodes-1){
                for (size_t i=0; i!=length()%50; ++i) {
     
                    curr->list[i]=curr->list[i+1];
                    
                }
                break;
            }
            
            
            for (size_t i=0; i!=50; ++i) {
                if(i==49){
                    
                    //this will go to next node
                    temp=temp->next;
                    
                    //insert temp nodes initial value into last index of curr
                    curr->list[49]=temp->list[0];
                    break;
                }
                
                //shift up
                curr->list[i]=curr->list[i+1];
            }
            
         
            curr=curr->next;
            counter++;
            
            
        }
        
        --tailIndex;
        return popped;
     
    };
    
    T peek_back (){
        
        size_t locationInNode=tailIndex%50-1;
        curr=head;
        
        while (curr->next!=nullptr) {
            curr=curr->next;
        }
        
        return curr->list[locationInNode];
        
    };
    
    T peek_front (){

        return head->list[0];
        
    };
    
    
    
    
    
    T item_at (size_t position){
        
        if(is_empty()){
            cout<<"Error. Empty"<<endl;
            return 0;
            
        }

        size_t counter = 0;
        size_t nodeLocation = position/50;    //which node to insert
        size_t locationInNode = position%50;
        
        curr=head;
        
        while(counter!=nodeLocation && curr!=NULL){
            curr=curr->next;
            counter++;
    }
        return curr->list[locationInNode];
        
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
    
    
    bool contains(T element, bool equals_function(T& element, T& findElement)){
        
        if (is_empty()) {
            return false;
        }
        
        curr=head;
        size_t counter = 0;
        
        while(curr!=NULL){
            
            
            if (counter==numberOfNodes) {
                for(size_t i = 0; i!=tailIndex%50; i++){
                    if(equals_function(element, curr->list[i]))
                        return true;
                }
            }
            
            
            
            for(size_t i = 0; i!=50; i++){
            if(equals_function(element, curr->list[i]))
                return true;
            }
            
            counter++;
            curr=curr->next;
            
        }
        
        
        return false;
        
        
        
    };
    
    
    T* contents(){
        
        size_t counter = 0;
        
        T* contents = new T[tailIndex];
        
        while (curr!=NULL) {
            
            if (counter==numberOfNodes) {
                for(size_t i = 0; i!=tailIndex%50; i++){
                    contents[i]=curr->list[i];
                    
                }
            }
            
            for(size_t i = 0; i!=50; i++){
                contents[i]=curr->list[i];
                
            }
            
            counter++;
            curr=curr->next;
        }
        
        return contents;
     
    };
    
    
    T remove(size_t position){
        
        if(is_empty()){
            cout<<"Error. Empty"<<endl;
            return 0;
            
        }
        
        size_t counter = 0;
        size_t nodeLocation = position/50;    //which node to insert
        size_t locationInNode = position%50;
        
        curr=head;
        
        //travser to correct node
        while(counter!=nodeLocation && curr!=NULL){
            curr=curr->next;
            counter++;
        }
        
        T removed = curr->list[locationInNode];
        
  
        bool firstRun = true;
        
        while (counter!=numberOfNodes) {
            
            temp=curr;
 
            //if only one node
            if(numberOfNodes==1){
                cout<<"it comes here 2"<<endl;
                for (size_t i=position; i!=length()%50; ++i) {
                    
                    curr->list[i]=curr->list[i+1];
                    
                }
                
                break;
                
            }
            
            //first shift
            if (firstRun) {
                
                for (size_t i=position; i!=50; ++i) {
                    if(i==49){
                        
                        //this will go to next node
                        temp=temp->next;
                        
                        //insert temp nodes initial value into last index of curr
                        curr->list[49]=temp->list[0];
                        break;
                    }
                    
                    //shift up
                    curr->list[i]=curr->list[i+1];
                }
                
                
                firstRun=false;
                curr=curr->next;
                counter++;
                continue;
            }

            //perform action when on last node
            if(counter==numberOfNodes-1){
                for (size_t i=0; i!=length()%50; ++i) {
                    
                    //shift up
                    curr->list[i]=curr->list[i+1];
                    
                }
                break;
            }
            
            
            for (size_t i=0; i!=50; ++i) {
                if(i==49){
                    
                    //this will go to next node
                    temp=temp->next;
                    
                    //insert temp nodes initial value into last index of curr
                    curr->list[49]=temp->list[0];
                    break;
                }
                
                //shift up
                curr->list[i]=curr->list[i+1];
            }
            
            curr=curr->next;
            counter++;
        }
        --tailIndex;
        return removed;
        
    };
    
    
    size_t length(){
        
        return tailIndex;
        
    };
    
    bool is_empty (){
        if(head==NULL)
            return true;
        return false;
        
    };
    
    bool is_full (){
        return false;
    }
    
    void print(ostream &stream){
        
        if (is_empty()) {
            stream<<"List is empty"<<endl;
            return;
        }
        
        size_t numberOfNodes=tailIndex/50;
        size_t counter =0;
        //stream<<tailIndex<<endl;
        
        curr=head;
       
       stream<<"[";
        
       while(curr!=NULL){
          
            if(counter==numberOfNodes){
                for(int i = 0; i!=tailIndex%50;++i){
                    if(i==(tailIndex%50-1)){
                        stream<<curr->list[i]<<"]";
                        break;
                    }
                    
                    stream<<curr->list[i]<<", ";
                }
                break;
            }
            
           
            for(int i = 0; i<50;++i){
               
                stream<<curr->list[i]<<", ";
            }
           
            curr=curr->next;
           ++counter;
        }
        
        
    };
    
};


#endif /* CDAL_h */
