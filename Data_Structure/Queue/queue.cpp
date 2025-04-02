#include <iostream>
#include <queue>
using namespace std;
int main(){
    queue<int> qu;
    qu.push(21);
    qu.push(22);
    qu.push(24);
    qu.push(25);

    int num = 5;
    qu.push(num);

    qu.pop();
    qu.pop();
    qu.pop();

    while (!qu.empty()) {
        cout<< qu.front() << " ";
        qu.pop();
    }

}