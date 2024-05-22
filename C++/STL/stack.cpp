#include <iostream>
#include <stack>
using namespace std;
int main(){
    stack<int> st;
    st.push(21);
    st.push(22);
    st.push(24);
    st.push(25);

    int num = 0;
    st.push(num);

    st.pop();
    st.pop();
    st.pop();

    while (!st.empty()) {
        cout<< st.top() << " ";
        st.pop();
    }

}