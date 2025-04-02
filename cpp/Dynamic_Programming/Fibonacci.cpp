#include <iostream>
#include <map>

using namespace std;
typedef long long ll; //use long long instead of int for larger return values

//map for memoization
map<int, ll> memo;

ll fib(int n){
    //base case
    if(memo.find(n) != memo.end()) return memo[n];
    if(n<=1) return n;

    //compute & memoize the return value
    memo[n] = fib(n-1) + fib(n-2);
    return memo[n];
}

int main(){
    cout<<fib(50)<<endl;

}