////
////  main.cpp
////  Project 1
////
////  Created by Harsh Patel on 9/14/17.
////  Copyright © 2017 HP Tech. All rights reserved.
////
//
//#include <iostream>
//#include "List.h"
//#include "SSLL.h"
//#include "PSLL.h"
//#include "SDAL.h"
//#include "CBL.h"
//#include "CDAL.h"
//#include <string>
//using namespace std;
//using namespace COP3530;
//
//int main() {
//    
//    //SSLL
//    cout<<endl<<endl;
//    cout<<"SSLL STARTS HERE"<<endl<<"--------------------"<<endl;
//      SSLL <int> list;
//    
//      list.insert(24, 2);
//      list.insert(244, 1);
//      list.insert(1234, 0);
//      list.insert(5, 3);
//      list.insert(543, 1);
//
//      list.insert(56, 5);
//      list.insert(76543,5);
//      list.insert(254, 3);
//      list.push_back(100);
//      list.push_front(1);
//    
//    int* contents = list.contents();
//    
//    for (int i =0; i!=10; i++) {
//        cout<<contents[i]<<endl;
//    }
//    
//   // list.replace(6, 10);
//   // cout<<list.item_at(10);
//    cout<<list.peek_front()<<endl;
//    cout<<list.peek_back()<<endl;
//    
//
//    
//    
//      list.print(cout);
//   cout<<endl<< list.contains(100, equals_function)<<endl;
//     cout<<list.remove(0);
//    list.print(cout);
//
//
//    //PSLL
//    cout<<endl<<endl;
//    cout<<"PSLL STARTS HERE"<<endl<<"--------------------"<<endl;
//
//    PSLL<int> pList;
//    pList.insert(24, 2);
//    pList.insert(244, 1);
//    pList.insert(1234, 0);
//    pList.insert(5, 3);
//    pList.insert(543, 1);
//    
//    pList.insert(56, 5);
//    pList.insert(76543,5);
//    pList.insert(254, 3);
//    pList.push_back(100);
//    pList.push_front(1);
//    
//    
//    int* contents1 = pList.contents();
//    
//    for (int i =0; i!=10; i++) {
//        cout<<contents1[i]<<endl;
//    }
//    
//    //sList.replace(6, 10);
//    //cout<<sList.item_at(10)<<endl;
//    cout<<pList.peek_front()<<endl;
//    cout<<pList.peek_back()<<endl;
//    pList.print(cout);
//    cout<<endl<< pList.contains(1, equals_function);
//    cout<<pList.remove(6);
//    pList.print(cout);
//    
//    //SDAL
//    cout<<endl<<endl;
//    cout<<"SDAL STARTS HERE"<<endl<<"--------------------"<<endl;
//    SDAL<int> sList(5);
//    sList.insert(24, 2);
//    sList.insert(244, 1);
//    sList.insert(1234, 0);
//    sList.insert(5, 3);
//    sList.insert(543, 1);
//    
//    sList.insert(56, 5);
//    sList.insert(76543,5);
//    sList.insert(254, 3);
//    sList.push_back(100);
//    sList.push_front(1);
////
////    int* contents2 = sList.contents();
////
////    for (int i =0; i!=10; i++) {
////        cout<<contents2[i]<<endl;
////    }
////
//    
//    
//  //sList.replace(6, 10);
//  //cout<<sList.item_at(10)<<endl;
//    cout<<sList.peek_front()<<endl;
//    cout<<sList.peek_back()<<endl;
//    
//    sList.print(cout);
//  // cout<< sList.contains(1, equals_function)<<endl;
//   cout<<sList.remove(0);
//    sList.print(cout);
//    
//    
//    
//    //CDAL
//
//    cout<<endl<<endl;
//    cout<<"CDAL STARTS HERE"<<endl<<"--------------------"<<endl;
//    CDAL<int> cList;
//
//    
//    for (int i = 0 ; i!=105; i++) {
//        cList.insert(i, i);
//    }
//    
//    
//
//   
//    cList.print(cout);
//    cout<<endl;
//    
//    //CBL
//    
//    cout<<endl<<endl;
//    cout<<"CBL STARTS HERE"<<endl<<"--------------------"<<endl;
//    CBL<int> cbList (4);
//    cbList.insert(0, 1);
//    cbList.insert(12, 0);
//    cbList.insert(11, 1);
//    cbList.insert(69, 3);
//    cbList.push_front(100);
//    cbList.push_back(0);
//    cbList.push_back(1);
//    cbList.push_back(2);
//    cbList.push_back(16);
//    cbList.push_back(90);
//    cbList.push_front(101);
//    cbList.push_front(103);
//    cbList.push_back(1);
////    cbList.push_back(2);
////    cbList.push_front(10);
////    cbList.push_front(666);
////    cbList.replace(50, 12);
//
//    cout<<"Item removed: "<<cbList.remove(0)<<endl;
//   // cout<<"Item removed: "<<cbList.remove(0)<<endl;
//  //  cout<<"Item removed: "<<cbList.remove(0)<<endl;
//  //  cout<<"Item removed: "<<cbList.remove(0)<<endl;
//
//    cbList.print(cout);
//    
////    cbList.clear();
//    cout<<cbList.length()<<endl;
//
//    
////    for (SSLL<int>::SSLL_Iterator it = list.begin(); it != list.end(); ++it)
////    {
////        cout << *it << endl;
////    }
//    
//    cout<<endl;
////
////    for (PSLL<int>::PSLL_Iterator it = pList.begin(); it != pList.end(); ++it)
////    {
////        cout << *it << endl;
////    }
////
////
////
//    
//    
//    cout<<"SDAL ITER"<<endl;
////    for (SDAL<int>::SDAL_Iterator it = sList.begin(); it != sList.end(); ++it)
////    {
////        cout << *it << endl;
////    }
//    
//    
//    
////    cout<<"CDAL ITER"<<endl;
////    for (CDAL<int>::CDAL_Iterator it = cList.begin(); it != cList.end(); ++it)
////    {
////        cout << *it << endl;
////    }
////
//    
//    cout<<"CBL ITER"<<endl;
//    
//    for (CBL<int>::CBL_Iterator it = cbList.begin(); it != cbList.end(); ++it)
//    {
//        cout << *it << endl;
//    }
//
//
//    return 0;
//    
//    
//    
//}

