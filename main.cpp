
#include "SeparateChaining.h"
#include "CuckooHashTable.h"
#include <chrono>
#include <random>

int my_random(int min, int max)
{
    // Inicjalizuj generator liczb pseudolosowych
    std::random_device rd;
    std::mt19937 gen(rd());
    // Utwórz rozkład równomierny na przedziale [min_int, max_int]
    std::uniform_int_distribution<int> distribution(min, max);
    return distribution(gen);
}

void ultimate_testChain(int size, int number_of_tests)
{
    std::cout<<"Test dla "<<size<<" elementow:"<<std::endl;
    int elements = size;
    long long time2 = 0;
    long long time4 = 0;
    long long time6 = 0;
    long long time8 = 0;
    long long time85 = 0;
    long long time9 = 0;
    long long time95 = 0;
    long long time99 = 0;
    int l2 = 0.2 * size;
    int l4 = 0.4 * size;
    int l6 = 0.6 * size;
    int l8 = 0.8 * size;
    int l85 = 0.85 * size;
    int l9 = 0.9 * size;
    int l95 = 0.95 * size;
    int l99 = 0.98 * size;
    for(int j = 0; j < number_of_tests; j++){
        SeparateChaining hashTable(size);
        int tmp1, tmp2;
        for(int i = 0; i < elements; i++)
        {
            tmp1 = my_random(1, 2000000000);
            tmp2 = my_random(0, 10000);
            if(i == l2)
            {
                auto begin = std::chrono::high_resolution_clock::now();
                hashTable.insert(tmp1, tmp2);
                auto end = std::chrono::high_resolution_clock::now();
                auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
                time2 = time2 + elapsed.count();
            }
            else if(i == l4)
            {
                auto begin = std::chrono::high_resolution_clock::now();
                hashTable.insert(tmp1, tmp2);
                auto end = std::chrono::high_resolution_clock::now();
                auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
                time4 = time4 + elapsed.count();
            }
            else if(i == l6)
            {
                auto begin = std::chrono::high_resolution_clock::now();
                hashTable.insert(tmp1, tmp2);
                auto end = std::chrono::high_resolution_clock::now();
                auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
                time6 = time6 + elapsed.count();
            }
            else if(i == l8)
            {
                auto begin = std::chrono::high_resolution_clock::now();
                hashTable.insert(tmp1, tmp2);
                auto end = std::chrono::high_resolution_clock::now();
                auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
                time8 = time8 + elapsed.count();
            }
            else if(i == l85)
            {
                auto begin = std::chrono::high_resolution_clock::now();
                hashTable.insert(tmp1, tmp2);
                auto end = std::chrono::high_resolution_clock::now();
                auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
                time85 = time85 + elapsed.count();
            }
            else if(i == l9)
            {
                auto begin = std::chrono::high_resolution_clock::now();
                hashTable.insert(tmp1, tmp2);
                auto end = std::chrono::high_resolution_clock::now();
                auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
                time9 = time9 + elapsed.count();
            }
            else if(i == l95)
            {
                auto begin = std::chrono::high_resolution_clock::now();
                hashTable.insert(tmp1, tmp2);
                auto end = std::chrono::high_resolution_clock::now();
                auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
                time95 = time95 + elapsed.count();
            }
            else if(i == l99)
            {
                auto begin = std::chrono::high_resolution_clock::now();
                hashTable.insert(tmp1, tmp2);
                auto end = std::chrono::high_resolution_clock::now();
                auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
                time99 = time99 + elapsed.count();
            }
            else
                hashTable.insert(tmp1, tmp2);
        }
    }
    std::cout<<"Load_factor 0.2 average time "<<time2/number_of_tests<<std::endl;
    std::cout<<"Load_factor 0.4 average time "<<time4/number_of_tests<<std::endl;
    std::cout<<"Load_factor 0.6 average time "<<time6/number_of_tests<<std::endl;
    std::cout<<"Load_factor 0.8 average time "<<time8/number_of_tests<<std::endl;
    std::cout<<"Load_factor 0.85 average time "<<time85/number_of_tests<<std::endl;
    std::cout<<"Load_factor 0.9 average time "<<time9/number_of_tests<<std::endl;
    std::cout<<"Load_factor 0.95 average time "<<time95/number_of_tests<<std::endl;
    std::cout<<"Load_factor 0.99 average time "<<time99/number_of_tests<<std::endl;
}

void ultimate_testCuckoo(int size, int number_of_tests)
{
    std::cout<<"Test dla "<<size<<" elementow:"<<std::endl;
    int elements = size;
    long long time2 = 0;
    long long time4 = 0;
    long long time6 = 0;
    long long time8 = 0;
    long long time85 = 0;
    long long time9 = 0;
    long long time95 = 0;
    long long time99 = 0;
    int l2 = 0.2 * size;
    int l4 = 0.4 * size;
    int l6 = 0.6 * size;
    int l8 = 0.8 * size;
    int l85 = 0.85 * size;
    int l9 = 0.9 * size;
    int l95 = 0.95 * size;
    int l99 = 0.98 * size;
    for(int j = 0; j < number_of_tests; j++){
        CuckooHashTable hashTable(size);
        int tmp1, tmp2;
        for(int i = 0; i < elements; i++)
        {
            tmp1 = my_random(1, 2000000000);
            tmp2 = my_random(0, 10000);
            if(i == l2)
            {
                auto begin = std::chrono::high_resolution_clock::now();
                hashTable.insert(tmp1, tmp2);
                auto end = std::chrono::high_resolution_clock::now();
                auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
                time2 = time2 + elapsed.count();
            }
            else if(i == l4)
            {
                auto begin = std::chrono::high_resolution_clock::now();
                hashTable.insert(tmp1, tmp2);
                auto end = std::chrono::high_resolution_clock::now();
                auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
                time4 = time4 + elapsed.count();
            }
            else if(i == l6)
            {
                auto begin = std::chrono::high_resolution_clock::now();
                hashTable.insert(tmp1, tmp2);
                auto end = std::chrono::high_resolution_clock::now();
                auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
                time6 = time6 + elapsed.count();
            }
            else if(i == l8)
            {
                auto begin = std::chrono::high_resolution_clock::now();
                hashTable.insert(tmp1, tmp2);
                auto end = std::chrono::high_resolution_clock::now();
                auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
                time8 = time8 + elapsed.count();
            }
            else if(i == l85)
            {
                auto begin = std::chrono::high_resolution_clock::now();
                hashTable.insert(tmp1, tmp2);
                auto end = std::chrono::high_resolution_clock::now();
                auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
                time85 = time85 + elapsed.count();
            }
            else if(i == l9)
            {
                auto begin = std::chrono::high_resolution_clock::now();
                hashTable.insert(tmp1, tmp2);
                auto end = std::chrono::high_resolution_clock::now();
                auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
                time9 = time9 + elapsed.count();
            }
            else if(i == l95)
            {
                auto begin = std::chrono::high_resolution_clock::now();
                hashTable.insert(tmp1, tmp2);
                auto end = std::chrono::high_resolution_clock::now();
                auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
                time95 = time95 + elapsed.count();
            }
            else if(i == l99)
            {
                auto begin = std::chrono::high_resolution_clock::now();
                hashTable.insert(tmp1, tmp2);
                auto end = std::chrono::high_resolution_clock::now();
                auto elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(end - begin);
                time99 = time99 + elapsed.count();
            }
            else
                hashTable.insert(tmp1, tmp2);
        }
    }
    std::cout<<"Load_factor 0.2 average time "<<time2/number_of_tests<<std::endl;
    std::cout<<"Load_factor 0.4 average time "<<time4/number_of_tests<<std::endl;
    std::cout<<"Load_factor 0.6 average time "<<time6/number_of_tests<<std::endl;
    std::cout<<"Load_factor 0.8 average time "<<time8/number_of_tests<<std::endl;
    std::cout<<"Load_factor 0.85 average time "<<time85/number_of_tests<<std::endl;
    std::cout<<"Load_factor 0.9 average time "<<time9/number_of_tests<<std::endl;
    std::cout<<"Load_factor 0.95 average time "<<time95/number_of_tests<<std::endl;
    std::cout<<"Load_factor 0.99 average time "<<time99/number_of_tests<<std::endl;
}

int main() {
    /*SeparateChaining table(10);
    table.insert(102, 10);
    table.insert(508, 20);
    table.insert(123, 30);
    table.insert(2034, 40);
    table.insert(509, 50);
    table.insert(10002, 60);
    table.insert(101, 70);
    table.insert(400, 80);
    table.insert(203, 90);
    table.insert(18, 100);
    table.insert(18, 100);
    //table.remove(10002);

    table.print();
    std::cout << table.get(10002);*/

    /*ultimate_testChain(100, 100);
    ultimate_testChain(1000, 100);
    ultimate_testChain(2000, 100);
    ultimate_testChain(4000, 100);
    ultimate_testChain(8000, 100);
    ultimate_testChain(16000, 100);
    ultimate_testChain(32000, 100);
    ultimate_testChain(64000, 100);
    ultimate_testChain(128000, 100);*/

    ultimate_testCuckoo(100, 100);
    ultimate_testCuckoo(1000, 100);
    ultimate_testCuckoo(2000, 100);
    ultimate_testCuckoo(4000, 100);
    ultimate_testCuckoo(8000, 100);
    ultimate_testCuckoo(16000, 100);
    ultimate_testCuckoo(32000, 100);
    ultimate_testCuckoo(64000, 100);
    ultimate_testCuckoo(128000, 100);

    /*CuckooHashTable cuckooTable(10);
    cuckooTable.insert(102, 10);
    cuckooTable.insert(508, 20);
    cuckooTable.insert(123, 30);
    cuckooTable.insert(2034, 40);
    cuckooTable.insert(509, 50);
    cuckooTable.insert(10002, 60);
    cuckooTable.insert(101, 70);
    cuckooTable.insert(400, 80);
    cuckooTable.insert(203, 90);
    cuckooTable.insert(18, 100);


    //cuckooTable.remove(10002);
    cuckooTable.print();
    std::cout << cuckooTable.get(10002);
    //cuckooTable.get(1);*/

    return 0;
}
