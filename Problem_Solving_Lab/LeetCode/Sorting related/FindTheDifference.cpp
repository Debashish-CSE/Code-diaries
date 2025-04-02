//Link: https://leetcode.com/problems/find-the-difference/description/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    char findTheDifference(string s, string t) {
        map<char, int> ms;
        map<char, int> mt;
        char x = '/0';
        for(int i = 0; i < s.size(); i++){
            if(ms.find(s[i]) == ms.end()){
                ms[s[i]] = 1;
            }
            else{
                ms[s[i]]++;
            }
        }

        for(int i = 0; i < t.size(); i++){
            if(mt.find(t[i]) == mt.end()){
                mt[t[i]] = 1;
            }
            else{
                mt[t[i]]++;
            }
        }

        for(auto a: mt){
            if(ms.find(a.first) == ms.end()){
                x = a.first;
            }
            else if(a.second > ms[a.first]){
                x = a.first;
            }
        }
        return x;
    }
};

int main() {
    Solution solution;
    string s = "abcd";
    string t = "abcde";

    cout << "The added character is: " << solution.findTheDifference(s, t) << endl;

    return 0;
}
