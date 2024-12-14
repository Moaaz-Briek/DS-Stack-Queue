#include <iostream>
#include <Exception.h>

using namespace std;

int binarySearch (int* arr, int size, int item) {
    int start = 0, end = size - 1, mid = 0;

    while (start <= end) {
        mid = (start + end) / 2;
        if (arr[mid] == item)
            return mid;
        else if (arr[mid] > item)
            end = mid - 1;
        else
            start = mid + 1;
    }

    throw Exception(404, "Error: Not Found");
}

void test_case_1() {
    int size = 9;

    int arr[size] = {11, 14, 21, 31, 43, 55, 66, 77, 88};

    cout << "The item " << 55 << " exists at index " << binarySearch(arr, size, 55) << endl;
}

void test_case_2() {
    int size = 8;

    int arr[size] = {11, 14, 21, 31, 43, 66, 77, 88};

    cout << "The item " << 55 << " exists at index " << binarySearch(arr, size, 55) << endl;
}

int main()
{
    try {
        test_case_1();

        test_case_2();
    } catch (Exception e) {
        cout << e.message;
    }
    return 0;
}
