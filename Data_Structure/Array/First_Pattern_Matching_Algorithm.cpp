#include <iostream>
#include <string>

using namespace std;

//First pattern matching algorithm
int main(){
    string P, T;
    cout<< "Test string: ";
    cin >> T;
    cout << "Pattern: ";
    cin >> P;

    int R=P.length(), S=T.length();
    int K=1, MAX=S-R+1, INDEX=0;//initialize failure case
    
    while(K<=MAX){
        bool success = true; //reset success flag for every new K value

        for(int L=1; L<=R; L++){
            if(P[L-1] != T[K+L-2]){
                success = false; 
                break; 
            }
        }

        //step 5: success
        if(success){
            INDEX = K;
            break; //exit outer loop cause we found the pattern
        }
        else{
            K = K+1; //if not found, increment K
            //move to the next starting point 
        }        
    }

    if(INDEX > 0) cout<< "pattern found" << endl;
    else cout<< "pattern not found" << endl;
}