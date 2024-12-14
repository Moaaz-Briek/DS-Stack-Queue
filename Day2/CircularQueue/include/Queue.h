#ifndef QUEUE_H
#define QUEUE_H
#include "Exception.h"
#include <iostream>

using namespace std;

class Queue
{
private:
    int* Q;
    int head = -1, tail = -1, ssize = 5;

public:
    Queue() {
        Q = new int[ssize];
    }

    Queue(int ssize) {
        Q = new int[ssize];
    }

    bool isEmpty() {
        return head == -1 && tail == -1;
    }

    bool isFull() {
        return (head == 0 && tail == ssize - 1) || (head == tail + 1);
    }

    void enQueue(int num) {
        if (isFull())
            throw Exception(102, "Queue is full");

        if (isEmpty()) {
            head = tail = 0; //case_1: Queue is empty, head and tail at -1
            Q[tail] = num;
        } else if (tail == ssize - 1) { //case_2: tail at last position of queue, reset it.
            tail = 0;
            Q[tail] = num;
        } else { //case_3: normal case tail at middle
            Q[++tail] = num;
        }
    }

    int deQueue() {
        if (isEmpty())
            throw Exception(101, "Queue is empty");

        if (head == tail) { //case_3: head and tail at the same position.
            head = tail = -1;
        } else if (head == ssize - 1) { //case_2: head at the last index of the queue.
            head = 0;
        } else { //case_1: default case, head at first or middle.
            ++head;
        }
    }

    int peak() {
        if (isEmpty())
            throw Exception(101, "Queue is empty");

        return Q[head];
    }

    void display() {
        if (isEmpty())
            throw Exception(101, "Queue is empty");
        else {
            if (head <= tail) {
                for (int i = head; i <= tail; i++)
                    cout << Q[i] << "\t";
            } else {
                for (int i = head; i < ssize; i++)
                    cout << Q[i] << "\t";

                for (int i = 0; i <= tail; i++)
                    cout << Q[i] << "\t";
            }
        }
        cout << endl;
    }
};

#endif // QUEUE_H
