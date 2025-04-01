#include<bits/stdc++.h>
using namespace std;

// Finding maximum pieces with n straight cuts
int findMaximumPieces(int n){
    return 1 + n*(n+1)/2; 
}

// using recursion
int findMaximumPieces_R(int n){
    if (n == 0) {
        return 1;  // Base case: If no cuts, there's only 1 piece
    }
    return findMaximumPieces_R(n-1) + n;
}

int main(){
    cout << "Total number of pieces: " << findMaximumPieces(3) << endl;
    cout << "Total number of pieces: " << findMaximumPieces_R(3) << endl;

    return 0;
}
