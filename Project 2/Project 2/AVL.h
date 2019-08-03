//
//  AVL.h
//  Project 2
//
//  Created by Harsh Patel on 12/6/17.
//  Copyright © 2017 HP Tech. All rights reserved.
//

#ifndef AVL_h
#define AVL_h

template <typename K, typename V, bool (*compare)(const K&, const K&), bool(*equals)(const K&, const K&)>

class AVL {
    
    struct Node{
        K key;
        V value;
        Node* left;
        Node* right;
        
    };
    
    Node* root;
    
    int treeHeight(Node* root){
        if (root==NULL)
            return 0;
        int left_height = treeHeight(root->left);
        int right_height = treeHeight(root->right);

        int maxTree = max(left_height,right_height);
        
        int height = maxTree +1;
        
        return height;
    };
    
    int balanceDiff(Node* root){
        if (root==NULL) {
            return 0;
        }
        return treeHeight(root->left)-treeHeight(root->right);
        
    };
    
    
    //rotate Left is RR_Rotate
    //rotate Right is LL_rotate
    Node* LL_rotate(Node*&root){
        Node * temp = root;
        root=root->left;
        temp->left=root->right;
        root->right=temp;
        
        return root;
    };
    
    Node* RR_rotate(Node*&root){
        if (root) {
       
        Node * temp = root;
        root=root->right;
        temp->right=root->left;
        root->left=temp;
        }
        return root;
    };
    
    Node* LR_rotate (Node*& root){
        RR_rotate(root->left);
        LL_rotate(root);
        
        return root;
    };
    
    Node* RL_rotate (Node*& root){
        
        LL_rotate(root->right);
        RR_rotate(root);
        
        return root;
        
    };
    
    Node* balanceAVL(Node* root){
        
        int balance_factor = balanceDiff(root);
        
        if (balance_factor > 1) {
            if (balanceDiff(root->left)>0)
                root = LL_rotate(root);
            
            else
                root = LR_rotate(root);
            
        }
        
        else if (balance_factor < -1){
            
            if (balanceDiff(root->right) > 0)
                root = RL_rotate(root);
            
            else
                root = RR_rotate(root);

        }
        
        return root;
        
    };
    
    void insert_avl (Node*& root, K key, V value){
        if (root==NULL) {
            Node* newNode=new Node;
            
            newNode->key=key;
            newNode->value=value;
            newNode->left=nullptr;
            newNode->right=nullptr;
            root=newNode;
            return;
        }
        
        if (key < root->key) {
            insert_avl(root->left, key, value);
            balanceAVL(root);
        }
        
        else if(key >= root->key){
            insert_avl(root->right, key, value);
            balanceAVL(root);
        }
  
    };
    
    void printHelper(Node *root) {
        
        if (root==NULL) {
            return;
        }
        
        cout<<root->value<<" ";
        printHelper(root->left);
        
        printHelper(root->right);
    };
    
    void destroyBST(Node* root){
        if (root) {
            destroyBST(root->left);
            destroyBST(root->right);
            delete root;
        }
        
        
    };
    
    Node* minKey(Node* root){
        
        Node* curr=root;
        while (curr->left!=NULL) {
            curr=curr->left;
        }
        
        return curr;
    };
    
    
    Node* lookUpNode(Node*root, K key){
        
        // Base Case: if root is null or key is present at root
        if (root == NULL || root->key == key)
            return root;
        
        // if key is greater than root's key
        if (root->key < key)
            return lookUpNode(root->right, key);
        
        // if key is smaller than root's key
        return lookUpNode(root->left, key);
        
    };
    
    Node* deleteNode(Node*&root, K key){
        
        if(root==NULL) return root;
        else if(key < root->key) root->left= deleteNode(root->left, key);
        else if(key > root->key) root->right= deleteNode(root->right, key);
        
        else{
            
            if (root->left==NULL && root->right== NULL) {
                delete root;
                root=NULL;
            }
            
            else if(root->left==NULL){
                
                Node* temp = root;
                root=root->right;
                delete temp;
                
            }
            else if(root->right==NULL){
                
                Node* temp = root;
                root=root->left;
                delete temp;
                
            }
            
            else{
                
                Node* temp = minKey(root->right);
                root->key=temp->key;
                root->right=deleteNode(root->right, temp->key);
                
            }
            
        }
        
        return root;
    };
    
public:
    
    AVL (){
        
        root=NULL;
        
    };
    
    ~AVL (){
        
        destroyBST(root);
        
    };
    
    void insert (K key, V value){
        
        insert_avl(this->root, key, value);
        
        
    };
    //move constructor
    AVL(const AVL&& other){
        
        root = other.root;
        other.root= NULL;
        
    };
    
    //move assignment
    AVL& operator = (AVL&& other){
        
        destroyBST(root);
        root = other.root;
        other.root= NULL;
        return *this;
        
    };
    
    //copy constructor
    AVL(const AVL& other){
        
        if (other.root ==NULL) {
            root=NULL;
        }
        else
            copyHelper(this->root);
    };
    
    //copy assignment
    AVL& operator = (const AVL& other){
        
        
        
        
    };
    
    void copyHelper(Node* root){
   
        if(!root) return root;
        Node* newNode =new Node();
        newNode->key= root->key;
        newNode->value = root->value;
        newNode->left = copyHelper(root->left);
        newNode->right = copyHelper(root->right);
        return newNode;

    };
    
    void remove (K key){
        
        if (lookUpNode(this->root, key)==NULL) {
            cout<<endl<<"Key "<<key<<" is invalid. Try again!"<<endl;
            return;
        }
        
        deleteNode(this->root, key);
    };
    
    V& lookup(K key){
        if (lookUpNode(this->root, key)==NULL) {
            cout<<"Key "<<key<<" is invalid. Try again!"<<endl;
            exit(0);
        }
        
        return lookUpNode(this->root, key)->value;
        
    };
    
    void print(){
        
        if (root==NULL) {
            cout<<"Empty tree!"<<endl;
            return;
        }
        printHelper(this->root);
        
        
    };
};


#endif /* AVL_h */
