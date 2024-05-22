#include <iostream>
#include <cmath>

using namespace std;

int main(){
    int n,sum;
    cout<<"Enter n: ";
    cin>>n;
    sum = (n*(n*n +1))/2;
    
    int **magic = new int *[n];
    for (int i = 0; i < n; i++){
            magic[i] = new int[n];

    }

    //Fill diagonals
    int i=0;
    for (int r=0; r<n; r++){
        for (int c=0; c<n; c++){
            magic[r][c] = i+1;
            i++;
        }
    }

    i=1;
    for (int r=0; r<n; r++){
        for (int c=0; c<n; c++){
            if(magic[r][c] == 0){
                magic[r][c] = i;
                i++;
            }
        }
    }

     for (int r=0; r<n; r++){
        for (int c=0; c<n; c++){
            cout<< magic[r][c] <<" ";
        }
        cout<<endl;
    }

}