#include <iostream>
#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "Node.h"
#include "Exception.h"

using namespace std;

class LinkedList
{
    public:
        Node* head = NULL;
        Node* tail = NULL;

        LinkedList() {}

        void add(int data) {
            Node* newNode = new Node(data);
            if (head == NULL) {
                head = tail = newNode;
                return;
            }

            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }

        void insertAfter(int data, int flag) {
            Node* flagNode = getNode(flag);

            if (flagNode == NULL)
                throw Exception(404, "Not Found");


            Node* newNode = new Node(data);

            if (flagNode == head && flagNode == tail) {
                newNode->prev = flagNode;
                flagNode->next = newNode;
                tail = newNode;
            } else if (flagNode == tail) {
                newNode->prev = flagNode;
                flagNode->next = newNode;
                tail = newNode;
            } else {
                Node* A = flagNode->next;
                A->prev = newNode;
                newNode->next = A;
                flagNode->next = newNode;
                newNode->prev = flagNode;
            }
        }

        void insertBefore(int data, int flag) {
            Node* flagNode = getNode(flag);

            if (flagNode == NULL)
                throw Exception(404, "Not Found");

            Node* newNode = new Node(data);

            if (flagNode == head) {
                newNode->next = flagNode;
                flagNode->prev = newNode;
                head = newNode;
            } else {
                Node* A = flagNode->prev;
                newNode->prev = A;
                newNode->next = flagNode;
                flagNode->prev = newNode;
                A->next = newNode;
            }
        }

        void insertAfterWithoutCreateNewNode(Node* newNode, Node* flagNode) {
            if (flagNode == head && flagNode == tail) {
                newNode->prev = flagNode;
                flagNode->next = newNode;
                tail = newNode;
            } else if (flagNode == tail) {
                newNode->prev = flagNode;
                flagNode->next = newNode;
                tail = newNode;
            } else {
                Node* A = flagNode->next;
                A->prev = newNode;
                newNode->next = A;
                flagNode->next = newNode;
                newNode->prev = flagNode;
            }
        }

        int getCount() {
            Node* current = head;
            int Count = 0;
            while (current != NULL) {
                Count++;
                current = current->next;
            }
            return Count;
        }

        void getIndex(int index) {
            Node* current = head;
            int Count = 0;
            while (current != NULL) {
                if (Count == index) {
                    cout << current->data << endl;
                    return;
                }

                Count++;
                current = current->next;
            }

            throw Exception(404, "Not Found");
        }

        void RemoveConnection(Node* node) {
            if (node == head) {
                if (node == tail) {
                    head = tail = NULL;
                }
                head = node->next;
                head->prev = NULL;
            } else if (node == tail) {
                tail = node->prev;
                tail->next = NULL;
            } else {
                Node* prev = node->prev;
                Node* next = node->next;

                prev->next = next;
                next->prev = prev;
            }
        }

        void display() {
            Node* currentNode = head;

            while (currentNode != NULL) {
                cout << currentNode->data << "\t";
                currentNode = currentNode->next;
            }
            cout << endl;
        }

       friend ostream& operator<<(ostream& os, const LinkedList& list) {
            Node* currentNode = list.head;

            while (currentNode != NULL) {
                os << "[" << currentNode->data << "]";
                if (currentNode->next != NULL) {
                    os << " -> ";
                }
                currentNode = currentNode->next;
            }

            return os << endl;
        }

        void bubbleSortBySwapData() {
            if (head == NULL) return;

            bool sorted;
            Node* currentNode;
            Node* lastNode = NULL;


            do {
                sorted = false;
                currentNode = head;

                while (currentNode->next != lastNode) {
                    Node* nextNode = currentNode->next;

                    if (currentNode->data > nextNode->data) {
                        int temp = currentNode->data;
                        currentNode->data = nextNode->data;
                        nextNode->data = temp;

                        sorted = true;
                    }
                    currentNode = nextNode;
                }

                lastNode = currentNode;
            } while (sorted);
        }

        void bubbleSortBySwapNode() {
            if (head == NULL) return;

            bool sorted;
            Node* currentNode;
            Node* lastNode = NULL;

            do {
                sorted = false;
                currentNode = head;

                while (currentNode->next != lastNode) {
                    Node* nextNode = currentNode->next;

                    if (currentNode->data > nextNode->data) {
                        RemoveConnection(currentNode);
                        insertAfterWithoutCreateNewNode(currentNode, nextNode);
                        sorted = true;
                    }
                    currentNode = nextNode;
                }

                lastNode = currentNode;
            } while (sorted);
        }

    protected:

    private:
        Node* getNode(int data) {
            Node* currentNode = head;

            while (currentNode != NULL) {
                if (currentNode->data == data)
                    return currentNode;
                else
                    currentNode = currentNode->next;
            }
            return NULL;
        }
};

#endif
