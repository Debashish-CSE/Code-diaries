#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int t;
    cin>>t;
    long long n, sum_of_square, square_of_sum, dif, output[t];
    for(int i=0; i<t; i++){
        cin>>n;
        sum_of_square = (n*(n+1)*(2*n+1))/6;
        square_of_sum = ((n*n)*(n+1)*(n+1))/4;
        dif = (square_of_sum - sum_of_square);
        output[i] = dif;
    }

    for(int i=0; i<t; i++){
        cout<<output[i]<<endl;
    }

}