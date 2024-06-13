//
// Created by stasi on 28.05.2024.
//

//Separate Chaining
#include "SeparateChaining.h"

SeparateChaining::SeparateChaining(int capacity) {
    size = 0;
    this->capacity = capacity;
    table = new BST[capacity];
}

SeparateChaining::~SeparateChaining() {
    delete[] table;
}

int SeparateChaining::hash(int key) {
    return key % capacity;
}

void SeparateChaining::insert(int key, int val) {
    int index = hash(key);
    table[index].insert(key, val);
    size++;
}

void SeparateChaining::remove(int key) {
    int index = hash(key);
    table[index].remove(key);
    size--;
}

int SeparateChaining::get(int key) {
    int index = hash(key);
    return table[index].get(key);
}

void SeparateChaining::print() {
    for (int i = 0; i < capacity; i++) {
        if(!table[i].isEmpty()) {
            std::cout << "Bucket " << i << ": ";
            table[i].print();
            std::cout << std::endl;
        }
    }
}




