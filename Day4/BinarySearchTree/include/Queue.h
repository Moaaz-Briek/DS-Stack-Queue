#ifndef QUEUE_H
#define QUEUE_H
#include "QueueNode.h"
#include "Exception.h"
#include <iostream>

using namespace std;

class Queue
{
    public:
        QueueNode* front = NULL;
        QueueNode* rear = NULL;
        Queue() {}

        void enqueue(int data) {
            QueueNode* newQueueNode = new QueueNode(data);

            if (front == NULL)
                front = rear = newQueueNode;
            else {
                rear->next = newQueueNode;
                rear = newQueueNode;
            }
        }

        int dequeue() {
            if (front == NULL)
                throw Exception(102, "Queue is empty");

            QueueNode* temp = front;
            front = temp->next;
            int data = temp->data;
            delete temp;
            if (front == NULL) rear = NULL;
            return data;
        }

        int peakFirst() {
            if (front == NULL)
                throw Exception(102, "Queue is empty");

            return front->data;
        }

        int peakLast() {
            if (front == NULL)
                throw Exception(102, "Queue is empty");

            return rear->data;
        }

        void display() {
            if (front == NULL)
                throw Exception(102, "Queue is empty");

            QueueNode* current = front;

            while(current != NULL) {
                cout << current->data << "\t";
                current = current->next;
            }

            cout << endl;
        }

    protected:

    private:
};

#endif // QUEUE_H
