//
//  MinHeap.hpp
//  LintCode_Test
//
//  Created by Junjie He on 3/11/19.
//  Copyright © 2019 Junjie He. All rights reserved.
//

#ifndef MinHeap_hpp
#define MinHeap_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
class MinHeap
{
    int value,nodeID;
    MinHeap* nextLeft=nullptr, *nextRight=nullptr;//, *root=nullptr;
    static int deepth;
    static std::vector<MinHeap> arr;
    
    
public:
    MinHeap(int v);
//    MinHeap(const MinHeap& mp);//take new mp to insert to the trea;
    void insert(MinHeap &heap);//insert with specify left/right
    void insert(std::vector<int> in_V);
    int getValue(){return value;}
    
    MinHeap* getLeft(){return this->nextLeft;}
    MinHeap* getRight(){return this->nextRight;}
    void setLeft(MinHeap& mh){this->nextLeft = &mh;}
    void setRight(MinHeap& mh){this->nextRight = &mh;}
    
    std::vector<MinHeap> getVect(){return arr;}
    
    bool hasLeftValue(){return nextLeft==NULL? false:true;}
    bool hasRightValue(){return this->nextRight==nullptr? false:true;}
    int getLValue(){return this->nextLeft->getValue();}
    int getRValue(){return this->nextRight->getValue();}
    
    int getNodeID(){return nodeID;}
    int getParentNode(int id){return (id-1)/2;}
    int getLChildNode(int id){return (id*2)+1;}
    int getRChildNode(int id){return (id*2)+2;}
    
    void insertRight(MinHeap &hp){this->nextRight = &hp;}
    void insertLeft(MinHeap &hp){this->nextLeft = &hp;}
    void swapNode(MinHeap &hp);
    void cleanConnnection(){this->nextRight=nullptr;this->nextLeft=nullptr;}
    void makeHeapUP();
    void makeHeapDOWN();
        
    void print(std::vector<MinHeap> VMinHeap);//print out current heap in form of array
    
};


#endif /* MinHeap_hpp */
