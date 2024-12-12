#ifndef QUEUE_H
#define QUEUE_H
#include "Node.h"
#include "Exception.h"

using namespace std;

class Queue
{
    public:
        Node* front = NULL;
        Node* rear = NULL;
        Queue() {}

        void enqueue(int data) {
            Node* newNode = new Node(data);

            if (front == NULL)
                front = rear = newNode;
            else {
                rear->next = newNode;
                rear = newNode;
            }
        }

        int dequeue() {
            if (front == NULL)
                throw Exception(102, "Queue is empty");

            Node* temp = front;
            front = temp->next;
            int data = temp->data;
            delete temp;
            if (front == NULL) rear = NULL;
            return data;
        }

        void display() {
            if (front == NULL)
                throw Exception(102, "Queue is empty");

            Node* current = front;

            while(current != NULL) {
                cout << current->data << "\t";
                current = current->next;
            }
        }

    protected:

    private:
};

#endif // QUEUE_H
