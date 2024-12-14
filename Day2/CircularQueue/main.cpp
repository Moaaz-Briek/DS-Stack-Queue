#include <iostream>
#include "Queue.h"
#include "Exception.h"

using namespace std;

void test_case_1() {
    try {
        Queue qu;
        qu.enQueue(10);
        qu.enQueue(20);
        qu.enQueue(30);
        qu.enQueue(40);
        qu.enQueue(50);

        qu.deQueue();

        qu.display();

        qu.enQueue(60);

        qu.display();
    } catch (Exception e) {
        cout << e.name << endl;
    }
}

void test_case_2() {
    try {
        Queue qu;
        qu.enQueue(10);
        qu.enQueue(20);
        qu.enQueue(30);
        qu.enQueue(40);
        qu.enQueue(50);
        cout << qu.peak();
    } catch (Exception e) {
        cout << e.name << endl;
    }
}

int main()
{
    test_case_1();
    return 0;
}
