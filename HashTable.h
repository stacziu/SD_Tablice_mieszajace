//
// Created by stasi on 28.05.2024.
//

#ifndef SD3_HASHTABLE_H
#define SD3_HASHTABLE_H

//Separate Chaining
#include <iostream>
#include "BST.h"

class HashTable : public BST{
    static const int TABLE_SIZE = 100;
    BST* table;
public:
    HashTable();
    ~HashTable();
    int hash(int key);
    void insert(int key, int val);
    void remove(int key);
    int get(int key);
    void print();


};


#endif //SD3_HASHTABLE_H
