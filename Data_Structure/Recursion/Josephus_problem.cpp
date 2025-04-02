#include <bits/stdc++.h>
using namespace std;

// Josephus problem
/*int josephus(int n, int k)
{
    if (n == 1)
        return 1;
    else
        // The position returned by josephus(n - 1, k)
        // is adjusted because the recursive call
        // josephus(n - 1, k) considers the
        // original position k % n + 1 as position 1
        return (josephus(n - 1, k) + k - 1) % n + 1;
}*/

//using recursion, if only 1 person is skipped
int josephus(int n){
    if (n == 1) return 1;
    else if(n%2 == 0) return 2*josephus(n/2) - 1;  //n is even
    else if(n%2 != 0) return 2*josephus(n/2) + 1;  //n is odd
}


int main(){
    int n = 100;
    int k = 2;
    cout << "The chosen place is " << josephus(n);
    return 0;
}
