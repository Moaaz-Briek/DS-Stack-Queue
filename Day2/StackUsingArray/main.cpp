#include <iostream>
#include "Stack.h"
#include "Exception.h"

using namespace std;

int main()
{
    try {
        Stack st;
        st.push(10);
        st.push(20);
        st.push(30);
        st.pop();
        st.print();
    } catch (Exception e) {
        cout << e.name << endl;
    }
    return 0;
}
