//
//  MinHeap.cpp
//  LintCode_Test
//
//  Created by Junjie He on 3/11/19.
//  Copyright © 2019 Junjie He. All rights reserved.
//

#include "MinHeap.hpp"

int MinHeap::deepth = 0;
std::vector<MinHeap> MinHeap::arr;

MinHeap::MinHeap(int v){
    value = v;
    nodeID = deepth++;
    std::cerr<<"New node val="<<v<<" ID:"<<nodeID<<std::endl;
    std::cerr<<"\t arr size:"<<arr.size()<<std::endl;
}
void MinHeap::swapNode(MinHeap &hp){
    if(this->getValue()>hp.getValue()){
        hp.insertLeft(*this->getLeft());
        hp.insertRight(hp);
        cleanConnnection();
    }else{
        std::cerr<<"no need to swap:"<<this->getValue()<<"with: "<<hp.getValue()<<std::endl;
    }
}

void MinHeap::insert(std::vector<int> V){
    for(int itr : V){
        std::cerr<<"working on: "<<itr<<std::endl;
        MinHeap *mh = new MinHeap(itr);
        insert(*mh);
    }
}
void MinHeap::insert(MinHeap &heap) {
    if (arr.size()<1){
        arr.push_back(heap);
        std::cerr<<"push first itmen to arr"<<std::endl;
    }else{
        MinHeap& parent = arr.at(arr.size()-1);
        if(parent.hasLeftValue()){
            if(parent.getLValue() > heap.getValue()){
                parent.setRight(*parent.getLeft());
                parent.setLeft(heap);
            }else{
                parent.setRight(heap);
                arr.push_back(heap);
            }
        }else{
            parent.setLeft(heap);
            arr.push_back(heap);
        }
    }
}

void MinHeap::print(std::vector<MinHeap> VMinHeap) {
    for(MinHeap& itr:VMinHeap){
        std::cout<<itr.getValue()<<" "<<std::endl;;
    }
}



