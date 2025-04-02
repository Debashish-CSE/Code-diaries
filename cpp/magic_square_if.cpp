#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int n, sum;
    cout <<"Enter n: ";
    cin>>n;
    sum = (n*(n*n +1))/2;
    cout << "Magic constant: "<< sum<< endl;
    int magic[n][n];
    cout<< "Enter the "<<n<<"*"<<n<<" matrix: "<<endl;
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cin>>magic[i][j];
        }
    }

    int vertical_sum1=0, vertical_sum2=0, vertical_sum3=0, horizontal_sum1=0, horizontal_sum2=0, 
        horizontal_sum3=0, diagonal_sum1=0, diagonal_sum2=0;
    for (int i=0; i<n; i++){
            vertical_sum1 += magic[i][0];
            vertical_sum2 += magic[i][1];
            vertical_sum3 += magic[i][2];
            horizontal_sum1 += magic[0][i];
            horizontal_sum2 += magic[1][i];
            horizontal_sum3 += magic[2][i];

            diagonal_sum1 += magic[i][i];
            diagonal_sum2 += magic[i][n-i-1];
        }
        cout<<vertical_sum1<<endl;
        cout<<vertical_sum2<<endl;
        cout<<vertical_sum3<<endl;
        cout<<horizontal_sum1<<endl;
        cout<<horizontal_sum2<<endl;
        cout<<horizontal_sum3<<endl;
        cout<<diagonal_sum1<<endl;
        cout<<diagonal_sum2<<endl;

        if(vertical_sum1 == sum && vertical_sum2 ==sum && vertical_sum3 == sum && horizontal_sum1 == sum && horizontal_sum2 == sum && horizontal_sum3 == sum
        && diagonal_sum1 == sum && diagonal_sum2 == sum) cout<<"Given "<< n << "*" << n << " matrix is a magic square"<<endl;
        else cout<<"Given "<< n << "*" << n << " matrix is not a magic square"<<endl;
    }