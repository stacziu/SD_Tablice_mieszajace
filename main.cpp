
#include "HashTable.h"

int main() {

    HashTable table;
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
    table.get(1);



    return 0;
}
