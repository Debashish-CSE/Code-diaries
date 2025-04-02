#include <bits/stdc++.h>
#include <stack>

using namespace std;

string str2 = "";
string rep_x(string str, char x , char y, int start){
    if(start == str.length()) return str2;

    if(str[start] != x){
        str2 += str[start];
    } 
    else {
        str2 += y;
    }

    rep_x(str, x, y, start+1); 
    return str2;   
}


int main(){
    string str = "abacd";
    char x = 'a', y = 'x';
    cout << str <<endl;

    
    cout << endl << "After replacing x with y: " << rep_x(str, x, y, 0);

}