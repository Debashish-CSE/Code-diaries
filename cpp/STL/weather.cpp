#include <iostream>
#include <bits/stdc++.h>
#include <map>

using namespace std;

int main(){
    string cname[] = {"Bahrain","Kawait","UK","Australia"};
    int temp[4][12] = {{17,18,21,25,30,33,34,34,32,30,25,20},
                       {17,21,26,32,40,44,46,46,43,36,26,20},
                       {7,7,9,11,14,16,19,19,17,13,10,7},
                       {23,23,22,19,16,14,13,14,16,18,20,22}};

    int min, max;
    for(int i=0; i<4; i++){
        max = temp[i][0];
        min = temp[i][0];
        for(int j=0; j<12; j++){
            if(temp[i][j] > max) max = temp[i][j];
            if(temp[i][j] < min) min = temp[i][j];
        }
        cout<<cname[i]<<" "<<max<<" "<<min<<endl;
    }
    
}