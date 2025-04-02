#include <iostream>

using namespace std;

int main(){
    int n,row,col;
    cout<<"Enter a number: ";
    cin>>n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(i==j || i==0 || i==n-1) cout<<"$ ";
            else cout<<"* ";
        }
        cout<<endl;
    }

}