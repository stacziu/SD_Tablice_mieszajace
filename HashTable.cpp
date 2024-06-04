//
// Created by stasi on 28.05.2024.
//

//Separate Chaining
#include "HashTable.h"

HashTable::HashTable() {
    table = new BST[TABLE_SIZE];
}

HashTable::~HashTable() {
    delete[] table;
}

int HashTable::hash(int key) {
    return key % TABLE_SIZE;
}

void HashTable::insert(int key, int val) {
    int index = hash(key);
    table[index].insert(key, val);
}

void HashTable::remove(int key) {
    int index = hash(key);
    table[index].remove(key);
}

int HashTable::get(int key) {
    int index = hash(key);
    return table[index].get(key);
}

void HashTable::print() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        if(!table[i].isEmpty()) {
            std::cout << "Bucket " << i << ": ";
            table[i].print();
            std::cout << std::endl;
        }
    }
}




