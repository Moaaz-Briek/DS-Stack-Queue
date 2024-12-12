#include <iostream>
#include "Queue.h"
#include "Exception.h"

using namespace std;

void test_case_1() {
    Queue qu;
    qu.enqueue(10);
    qu.enqueue(20);
    qu.enqueue(30);
    qu.enqueue(40);

    try {
        cout << qu.dequeue() << endl;
        cout << qu.dequeue() << endl;
        cout << qu.dequeue() << endl;
        cout << qu.dequeue() << endl;
        cout << qu.dequeue() << endl;
    } catch (Exception e) {
        cout << e.name;
    }

    cout << endl;
}

void test_case_2() {
    Queue qu;
    qu.enqueue(10);
    qu.enqueue(20);
    qu.enqueue(30);
    qu.enqueue(40);

    try {
        cout << qu.dequeue() << endl;
        cout << qu.dequeue() << endl;
        cout << qu.dequeue() << endl;
        cout << qu.dequeue() << endl;
        cout << qu.dequeue() << endl;
    } catch (Exception e) {
        cout << e.name << endl;
    }

    qu.enqueue(10);
    qu.enqueue(20);
    qu.enqueue(30);
    qu.enqueue(40);

    qu.display();

    cout << endl;
}

int main()
{
    test_case_2();
    return 0;
}
