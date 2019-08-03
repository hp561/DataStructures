//
//  main.cpp
//  Project 2
//
//  Created by Harsh Patel on 12/6/17.
//  Copyright © 2017 HP Tech. All rights reserved.
//

#include <iostream>
#include "BSTLEAF.h"
#include "BSTRAND.h"
#include "BSTROOT.h"
#include "AVL.h"

int main(int argc, const char * argv[]) {

       cout<<"BSTLEAF"<<endl;
    BSTLEAF<int, int> tree;

    tree.insert(30, 24);
    tree.insert(1, 34);
    tree.insert(9, 12);
    tree.insert(4, 4);
    tree.print();
    
//    tree.remove(99);
//    tree.remove(1);
//    tree.remove(4);
//    tree.remove(9);
//    cout<<"New BST"<<endl;
//    tree.print();
    
    cout<<endl<<tree.lookup(30)<<endl;
    
    
    cout<<endl<<endl;
    
    cout<<"BSTROOT"<<endl;
    BSTROOT<int, int> root_tree;
    
    root_tree.insert(30, 24);
    root_tree.insert(1, 34);
    root_tree.insert(9, 12);
    root_tree.insert(4, 4);
    root_tree.print();
    cout<<endl<<endl;
    
    cout<<"BSTRAND"<<endl;
    BSTROOT<int, int> broot_tree;
    
    broot_tree.insert(30, 24);
    boot_tree.insert(1, 34);
    broot_tree.insert(9, 12);
    broot_tree.insert(4, 4);
    broot_tree.print();
    cout<<endl<<endl;
    
    
       cout<<"AVL"<<endl;
    AVL<int, int> avl_tree;
    avl_tree.insert(30, 24);
    avl_tree.insert(1, 34);
    avl_tree.insert(9, 12);
//    avl_tree.insert(4, 4);
//    avl_tree.insert(30, 24);
//    avl_tree.insert(1, 34);
//    avl_tree.insert(9, 12);
//    avl_tree.insert(4, 4);
    avl_tree.print();
    return 0;
}
