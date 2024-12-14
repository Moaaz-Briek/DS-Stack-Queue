#ifndef STACK_H
#define STACK_H
#include "Node.h"
#include "Exception.h"
#include <iostream>

using namespace std;

class Stack
{
    public:
        Node* tail = NULL;
        Stack() {}

        void push(int data) {
            Node* newNode = new Node(data);
            newNode->prev = tail;
            tail = newNode;
        }

        int pop() {
            if (tail == NULL)
                throw Exception(101, "Stack is empty.");
            else {
                Node* temp = tail;
                tail = temp->prev;
                int data = temp->data;
                delete temp;
                return data;
            }
        }

        int peak() {
            if (tail == NULL)
                throw Exception(101, "Stack is empty.");
            else
                return tail->data;
        }

        void display() {
            if (tail == NULL)
                throw Exception(101, "Stack is empty.");

            Node* currentNode = tail;

            while (currentNode != NULL) {
                cout << currentNode->data << "\t";
                currentNode = currentNode->prev;
            }
            cout << endl;
        }
    protected:

    private:
};

#endif // STACK_H
