#include <iostream>
#include "Stack.h"
#include "Exception.h"

using namespace std;


void test_case_1() {
    Stack st;
    st.push(12);
    st.push(22);
    st.push(32);
    st.push(42);

    try {
        st.pop();
        cout << st.peak();
    } catch (Exception e) {
        cout << e.name << endl;
    }

    cout << endl;
}

void test_case_2() {
    Stack st;
    st.push(12);
    st.push(22);
    st.push(32);
    st.push(42);

    try {
        st.pop();
        st.pop();
        st.pop();
        st.pop();
        cout << st.peak();
    } catch (Exception e) {
        cout << e.name << endl;
    }

    cout << endl;
}

void test_case_3() {
    Stack st;
    st.push(12);
    st.push(22);
    st.push(32);
    st.push(42);

    try {
        st.display();
    } catch (Exception e) {
        cout << e.name << endl;
    }

    cout << endl;
}

int main()
{
    test_case_1();
    test_case_2();
    test_case_3();
    return 0;
}
