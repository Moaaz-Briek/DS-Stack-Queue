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
        if (head == 0 && tail == ssize - 1)
            return true;
        else if (head == tail + 1)
            return true;
        else
            return false;
    }

    void enQueue(int num) {
        if (isFull())
            throw Exception(102, "Queue is full");

        if (isEmpty()) {
            head = tail = 0;
            Q[tail] = num;
        } else if (tail == ssize - 1) {
            tail = 0;
            Q[tail] = num;
        } else {
            Q[++tail] = num;
        }
    }

    int deQueue() {
        if (isEmpty())
            throw Exception(101, "Queue is empty");
        else {
            if (head == tail) {
                head = tail = -1;
            } else if (head == ssize - 1) {
                head = 0;
            } else {
                ++head;
            }
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
