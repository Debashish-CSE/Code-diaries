#include <iostream>
#include <queue>

using namespace std;

int main(){
    priority_queue<int> qu; //priority queue automatically sorts the queue after pushing 
    qu.push(21);
    qu.push(22);
    qu.push(24);
    qu.push(25);

    qu.pop();
    while(!qu.empty()){
        cout<< qu.top() << " ";
        qu.pop();
    }
}