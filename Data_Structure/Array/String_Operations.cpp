#include <iostream>
#include <string>

using namespace std;

//length of a string
int LENGTH(string s1){
    int count = 0, i=0;
    
    while(s1[i] != '\0'){
        count++;
        i++;
    }
    return count;
}


//substring of a string
void SUBSTRING(string s2, int initial, int length){
    if(initial-1 <= LENGTH(s2) && (initial + length - 1) <= LENGTH(s2)){
        for(int i=initial-1; i<(initial+length-1); i++){
            cout << s2[i];
        }
        cout << endl;
    }
    else{
        cout << "Give valid input for initial and length" << endl;
    }
}


//string concatenation
string CONCATENATE(string s1, string s2){
    string s = s1 + s2;
    return s;
}


//inserting another string into a string at fixed index
string INSERT(string s1, int position, string s2){
    string str;
    if (position < 1 || position > LENGTH(s1) + 1) { // Validate position
        return "Invalid position";
    }
    
    for(int i=0; i<(position-1); i++){
        str += s1[i];
    }

    str += s2;

    for(int i=(position-1); i<LENGTH(s1); i++){
        str += s1[i];
    }
    return str;
}


//deleting from a string from a fixed index 
string DELETE(string s1, int position, int length){
    string str;
    for(int i=0; i<(position-1); i++){
        str += s1[i];
    }

    for(int i=(position+length-1); i<LENGTH(s1); i++){
        str += s1[i];
    }
    return str;
}


//finding index of the first occurence of a string
int INDEX(string T, string P){
    //first pattern matching algorithm
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
    return INDEX; //index starting from 1
}


//replace 1st occurence of pattern1 with pattern2
string REPLACE(string s1, string pt1, string pt2){
    int matchedIndex = INDEX(s1, pt1)-1; //adjust index based on 0
    string str;

    for(int i=0; i<matchedIndex; i++){
        str += s1[i];
    }

    str += pt2;

    for(int j= matchedIndex + pt1.length(); j<s1.length(); j++){
        str += s1[j];
    }
    return str; 
}


int main(){
    string str1 = "ABCDEFG";
    string str2 = "MN";
    string pt1 = "CD";

    cout<<"str1: " << str1 << endl << "str2: " << str2 << endl << "Pattern: " << pt1 << endl;

    cout << "Length of the string str1: " << LENGTH(str1) <<endl; 

    cout << "Substring: " ;
    SUBSTRING(str1, 2, 5);

    cout << "Concatenation of str1 and str2: " << CONCATENATE(str1, str2) << endl;

    cout << "After inserting str2 into str1: " << INSERT(str1, 3, str2) << endl;

    cout << "After deleting: " << DELETE(str1, 4, 2) << endl;

    cout << "INDEX of the 1st occurence of pt1: " << INDEX(str1, pt1) << endl;

    cout << "Replace the 1st occurence of pt1 with str2: " << REPLACE(str1, pt1, str2) << endl;
}