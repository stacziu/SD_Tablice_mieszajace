//
// Created by stasi on 06.06.2024.
//

#ifndef SD3_CUCKOOHASHTABLE_H
#define SD3_CUCKOOHASHTABLE_H
#include <iostream>

class Pair {
public:
    int key;
    int data;
    bool state;

    Pair() {
        key = 0;
        data = 0;
        state = false;
    }
    bool getState() {
        return state;
    }
    void setPair(int key, int data) {
        this->key = key;
        this->data = data;
        state = true;
    }

    int getKey() {
        return key;
    }

    int getData() {
        return data;
    }
};

class CuckooHashTable {

    int size;
    int capacity;
    int max_cycles = capacity;
    Pair* T1;
    Pair* T2;
public:
    CuckooHashTable(int capacity);
    ~CuckooHashTable();
    int hash1(int key);
    int hash2(int key);
    void insert(int key, int val);
    void remove(int key);
    int get(int key);
    void print();
    void resize();
};


#endif //SD3_CUCKOOHASHTABLE_H
