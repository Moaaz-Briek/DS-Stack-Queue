#include <iostream>

using namespace std;

#include "LinkedList.h"

void test_case_1() {
    LinkedList list;
    list.add(15);
    list.add(10);
    list.add(5);
    list.add(20);
    cout << list;
    list.bubbleSortBySwapData();
    cout << list;}

int main()
{
    test_case_1();
    return 0;
}
