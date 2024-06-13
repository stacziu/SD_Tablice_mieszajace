//
// Created by stasi on 28.05.2024.
//

#ifndef SD3_SEPARATECHAINING_H
#define SD3_SEPARATECHAINING_H

//Separate Chaining
#include <iostream>
#include "BST.h"

class SeparateChaining : public BST{
    int size;
    int capacity;
    BST* table;
public:
    
    SeparateChaining(int size);
    ~SeparateChaining();
    int hash(int key);
    void insert(int key, int val);
    void remove(int key);
    int get(int key);
    void print();


};


#endif //SD3_SEPARATECHAINING_H
