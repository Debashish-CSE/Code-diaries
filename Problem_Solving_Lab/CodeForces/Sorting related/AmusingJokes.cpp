//Link: https://codeforces.com/problemset/problem/141/A

#include<iostream>
#include<map>
#include<string>
using namespace std;

int main(){
    string str1;
    string str2;
    string strComb;
    cin >> str1;
    cin >> str2;
    cin >> strComb;

    map<char, int> countMap;
    map<char, int> countMap2;

    for(int i = 0; i < str1.size(); i++){
        if(countMap.find(str1[i])== countMap.end()){
            countMap[str1[i]] = 1;
        }
        else{
            countMap[str1[i]]++;
        }
    }

    for(int i = 0; i < str2.size(); i++){
        if(countMap.find(str2[i])== countMap.end()){
            countMap[str2[i]] = 1;
        }
        else{
            countMap[str2[i]]++;
        }
    }

    for(char c: strComb) countMap2[c]++;

    if(countMap == countMap2){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }

    return 0;
}

/*
#include <bits/stdc++.h>
using namespace std;

int main() {
    string name1, name2, shuffled;
    cin >> name1 >> name2 >> shuffled;

    // Concatenate name1 and name2
    string combined = name1 + name2;

    // Sort both strings
    sort(combined.begin(), combined.end());
    sort(shuffled.begin(), shuffled.end());

    // Compare sorted strings
    if (combined == shuffled) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }

    return 0;
}

*/