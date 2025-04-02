#include <iostream>
#include <map>

using namespace std;
typedef long long ll; //use long long instead of int for larger return values

//map for memoization
map<string, ll> memo;

ll gridTraveler(int m, int n){
    string key = to_string(m) + "," + to_string(n);
    //base case
    if(memo.find(key) != memo.end()) return memo[key];
    if(m==1 && n==1) return 1;
    if(m==0 || n==0) return 0;

    //compute & memoize the return value
    memo[key] = gridTraveler(m-1, n) + gridTraveler(m, n-1);
    return memo[key];
}

int main(){
    cout<<gridTraveler(18,18)<<endl;

}