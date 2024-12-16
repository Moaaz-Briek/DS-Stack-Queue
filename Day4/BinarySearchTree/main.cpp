#include <iostream>
#include "Tree.h"
#include "Exception.h"

using namespace std;

void test_case_1(){
    Tree tree;
    tree.add(50);
    tree.add(30);
    tree.add(40);
    tree.add(60);
    tree.add(20);
    tree.add(70);
    tree.displayAll();
}

void test_case_2(){
    try {
        Tree tree;
        tree.add(50);
        tree.remove(50);
        tree.displayAll();
    } catch (Exception e) {
        cout << e.message << endl;
    }
}

void test_case_3(){
    Tree tree;
    tree.add(50);
    tree.add(30);
    tree.add(40);
    tree.add(60);
    tree.add(20);
    tree.add(70);
    tree.remove(60);
    tree.displayAll();
}

void test_case_4(){
    Tree tree;
    tree.add(50);
    tree.add(30);
    tree.add(40);
    tree.add(60);
    tree.add(20);
    tree.add(70);
    tree.getMin();
}

void test_case_5(){
    Tree tree;
    tree.add(50);
    tree.add(30);
    tree.add(40);
    tree.add(60);
    tree.add(20);
    tree.add(70);
    tree.getMax();
}

int main()
{
    test_case_1();
    test_case_2();
    test_case_3();
    test_case_4();
    test_case_5();
    return 0;
}
