//Link: https://codeforces.com/problemset/problem/1760/B
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    while(n--){
        int len;
        cin >> len;
        string word;
        cin >> word;

        char temp = word[0];
        for(int i = 1; i < word.size(); i++){
            
            if(temp < word[i]){
                temp = word[i];
            }
        }
        cout << temp - 'a' + 1 << endl;
    }
    return 0;
}