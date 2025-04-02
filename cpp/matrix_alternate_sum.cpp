#include <iostream>
#include <cmath>
using namespace std;

//sum of alternate elements in n*m matrix

int main(){
    int n,m;
    cout<<"Enter n: ";
    cin>>n;
    cout<<"Enter m: ";
    cin>>m;
    int mat[n][m];
    cout<< "Enter the "<<n<<"*"<<m<<" matrix: "<<endl;
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            cin>>mat[i][j];
        }
    }

    int sum_odd=0, sum_even=0;
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            //if total column is odd
            if(m %2 != 0){    
                if((i%2 != 0 && j%2 != 0) || (i%2 == 0 && j%2 == 0)) sum_odd += mat[i][j]; //row odd & column odd
                else sum_even += mat[i][j];
            }
            //if total column is even
            else{
                if(j%2 != 0) sum_odd += mat[i][j]; //only column odd
                else sum_even += mat[i][j];
            }
        }
    }
    cout<<"Sum of alternate elements: "<<sum_odd<<" "<<sum_even<<endl;

}