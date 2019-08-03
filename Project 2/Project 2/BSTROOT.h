//
//  BSTROOT.h
//  Project 2
//
//  Created by Harsh Patel on 12/6/17.
//  Copyright © 2017 HP Tech. All rights reserved.
//

#include <iostream>
#ifndef BSTROOT_h
#define BSTROOT_h
using namespace std;

template <typename K, typename V, bool (*compare)(const K&, const K&), bool(*equals)(const K&, const K&)>
class BSTROOT {
    
    
    struct Node{
        K key;
        V value;
        Node* left;
        Node* right;
    };
    
    Node* root;
    
    //rotate Left is RR_Rotate
    //rotate Right is LL_rotate
    void LL_rotate(Node*&root){
        Node * temp = root;
        root=root->left;
        temp->left=root->right;
        root->right=temp;
    };
    
    void RR_rotate(Node*&root){
        Node * temp = root;
        root=root->right;
        temp->right=root->left;
        root->left=temp;
    };
    
    
    void insert_at_root(Node*&root, V value, K key){
    
        
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
            insert_at_root(root->left, value, key);
            LL_rotate(root);
            
        }
        
        else{
            
            insert_at_root(root->right, value, key);
            RR_rotate(root);
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
    
    
    
    Node* minKey(Node* root){
        
        Node* curr=root;
        while (curr->left!=NULL) {
            curr=curr->left;
        }
        
        return curr;
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
    
    void destroyBST(Node* root){
        if (root) {
            destroyBST(root->left);
            destroyBST(root->right);
            delete root;
        }
        
    };
    
public:
    
    
    BSTROOT(){
        
        root=NULL;
        
    };
    
    ~BSTROOT(){
        
        destroyBST(root);
        
    };
    
    void insert (K key, V value){
        
        insert_at_root(this->root, value, key);
        
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




#endif /* BSTROOT_h */
