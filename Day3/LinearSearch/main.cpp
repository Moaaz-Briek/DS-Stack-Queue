#include <iostream>
#include "Exception.h"
#include "LinkedList.h"

using namespace std;

LinkedList linearSearch(int* arr, int size, int item) {
    LinkedList occuranceList;
    for (int index = 0; index < size - 1; index++) {
        if (arr[index] == item)
            occuranceList.add(index);
    }

    return occuranceList;
}


void test_case_1() {
    int size = 5;

    int arr[size] = {15, 65, 23, 10, 85};

    try {
        cout << "The item exists at index/es: " << linearSearch(arr, size, 15) << endl;
    } catch (Exception e) {
        cout << e.message << endl;
    }
}

void test_case_2() {
    int size = 6;

    int arr[size] = {15, 65, 23, 10, 15, 85};

    try {
        cout << "The item exists at index/es: " << linearSearch(arr, size, 15) << endl;
    } catch (Exception e) {
        cout << e.message << endl;
    }
}


void test_case_3() {
    int size = 5;

    int arr[size] = {15, 65, 23, 10, 85};

    try {
        cout << "The item exists at index/es: " << linearSearch(arr, size, 115) << endl;
    } catch (Exception e) {
        cout << e.message << endl;
    }
}

int main()
{
    test_case_1();
    test_case_2();
    test_case_3();

    return 0;
}
