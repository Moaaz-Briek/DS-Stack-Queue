#ifndef STACK_H
#define STACK_H
#include <iostream>
#include "Exception.h"

using namespace std;

class Stack {

private:
    int Size = 10;
    int Tos = 0;
    int* Stk;

public:
    Stack(){
        Stk = new int[Size];
    }

    Stack(int Size){
        this->Size = Size;
        Stk = new int[Size];
    }

    Stack(const Stack& other){
        this->Size = other.Size;
        this->Tos = other.Tos;

        Stk = new int[Size];

        for (int i = 0; i <= Tos; i++) {
            Stk[i] = other.Stk[i];
        }
    }

    int push(int value) {
        if (Tos == Size)
            throw Exception(102, "Stack is full");

        Stk[Tos++] = value;
    }

    int pop() {
        if (Tos == 0)
            throw Exception(101, "Stack is empty");

        return Stk[--Tos];
    }

    void print() {
        int current = Tos;

        while (current != 0) {
            cout << Stk[--current] << "\t";
        }

        cout << endl;
    }

    ~Stack() {
        delete[] Stk;
    }
};
#endif // STACK_H
