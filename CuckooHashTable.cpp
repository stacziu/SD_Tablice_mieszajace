//
// Created by stasi on 06.06.2024.
//

#include "CuckooHashTable.h"

CuckooHashTable::CuckooHashTable(int capacity) {
    size = 0;
    this->capacity = capacity/2;
    T1 = new Pair[this->capacity];
    T2 = new Pair[this->capacity];

}

CuckooHashTable::~CuckooHashTable() {
    delete [] T1;
    delete [] T2;
}

int CuckooHashTable::hash1(int key) {
    return key % (capacity);
}

int CuckooHashTable::hash2(int key) {
    return (key / capacity) % capacity;
}

void CuckooHashTable::insert(int key, int val) {
    Pair newPair;
    newPair.setPair(key, val);
    for (int cycles = 0; cycles < max_cycles; cycles++) {
        int index = hash1(newPair.getKey());
        if (!T1[index].getState()) {
            T1[index] = newPair;
            size++;
            return;
        }
        std::swap(newPair, T1[index]);

        index = hash2(newPair.getKey());
        if (!T2[index].getState()) {
            T2[index] = newPair;
            size++;
            return;
        }
        std::swap(newPair, T2[index]);

    }

    // Dojscie do tego miejsca w kodzie oznacza, ze przekroczono maksymalna liczbe cykli
    // nalezy wiec zwiekszyc rozmiary tablic.
    resize();
}

void CuckooHashTable::remove(int key) {
    int index = hash1(key);
    if (T1[index].getState() && T1[index].getKey() == key) {
        T1[index].state = false;
        size--;
        return;
    }

     index = hash2(key);
    if (T2[index].getState() && T2[index].getKey() == key) {
        T2[index].state = false;
        size--;
        return;
    }
}

int CuckooHashTable::get(int key) {
    int index = hash1(key);
    if (T1[index].getState() && T1[index].getKey() == key) {
        return T1[index].getData();
    } else {
        index = hash2(key);
        if (T2[index].getState() && T2[index].getKey() == key) {
            return T2[index].getData();
        }
    }
    return -1; // nie znaleziono klucza
}

void CuckooHashTable::resize() {
    Pair* oldT1 = T1;
    Pair* oldT2 = T2;
    capacity *= 2;
    T1 = new Pair[capacity];
    T2 = new Pair[capacity];
    for (int i = 0; i < capacity/2; i++) {
        if (oldT1[i].getState()) {
            insert(oldT1[i].getKey(), oldT1[i].getData());
        }
        if (oldT2[i].getState()) {
            insert(oldT2[i].getKey(), oldT2[i].getData());
        }
    }
    delete [] oldT1;
    delete [] oldT2;
}

void CuckooHashTable::print() {
    for (int i = 0; i < capacity; i++) {
        if (T1[i].getState()) {
            std::cout << "Index1: " << hash1(T1[i].getKey()) << " Value1: " << T1[i].getData() << std::endl;
        }
        if (T2[i].getState()) {
            std::cout << "Index2: " << hash2(T2[i].getKey()) << " Value2: " << T2[i].getData() << std::endl;
        }
    }
}

