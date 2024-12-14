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

void test_case_2() {
    LinkedList list;
    list.add(5);
    list.add(7);
    list.add(2);
    list.add(1);
    list.add(10);
    list.add(13);
    cout << list;
    list.bubbleSortBySwapNode();
    cout << list;}

int main()
{
    test_case_1();
    test_case_2();
    return 0;
}
