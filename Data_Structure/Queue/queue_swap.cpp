#include <iostream>
#include <queue>

using namespace std;

int main(){
    queue<int> myqueue1;
    queue<int> myqueue2;

    //pushing elemets into 1st queue
    myqueue1.push(1);
    myqueue1.push(2);
    myqueue1.push(3);
    myqueue1.push(4);

    //pushing elements into 2nd queue
    myqueue2.push(3);
    myqueue2.push(5);
    myqueue2.push(7);
    myqueue2.push(9);

    //swap elements of queue
    myqueue1.swap(myqueue2);

    //printing the 1st queue
    cout<<"myqueue1 = ";
    while (!myqueue1.empty()){
        cout <<myqueue1.front()<<" ";
        myqueue1.pop();
    }
    cout<<endl;

    //printing the 2nd queue
    cout<<"myqueue2 = ";
    while (!myqueue2.empty()){
        cout <<myqueue2.front()<<" ";
        myqueue2.pop();
    }

}