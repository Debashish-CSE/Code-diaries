#include <bits/stdc++.h>

using namespace std;

int main(){
    vector<int> nums1 = {4,9,5}, nums2 = {9,4,9,8,4},v1,v2, output;
    set <int> s1,s2;
    for(auto i:nums1) s1.insert(i);
    for(auto j:nums2) s2.insert(j);

    
    for(auto i: s1) v1.push_back(i);
    for(auto j: s2) v2.push_back(j);
    //for(auto i:v2) cout <<i;
    //sort(totalnum.begin(), totalnum.end());
    /*vector<int> totalnum1 = countSort(totalnum);
    for(int i=0; i<totalnum1.size(); i++){
        if(totalnum1[i] == totalnum1[i-1]){
            output.push_back(totalnum1[i]);
        }
    }*/

    int i=0,j=0;
    while (i<v1.size() && j<v2.size()){
        if(v1[i] == v2[j]){
            output.push_back(v1[i]);
            i++;
            j++;
        }
        else if(v1[i] < v2[j]) i++;
        else if(v1[i] > v2[j]) j++;
    }
    
    /*for(int i=0; i<v1.size(); i++){
        for(int j=0; j<v2.size(); j++){
            if(v1[i] == v2[j]){
                output.push_back(v1[i]);
            }
        }
    }*/
    
    for(auto i:output){
        cout << i << " ";
    }
    cout <<endl;


    return 0;
}