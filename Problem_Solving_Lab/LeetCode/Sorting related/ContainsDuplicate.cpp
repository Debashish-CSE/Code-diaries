//Link: https://leetcode.com/problems/contains-duplicate/description/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for(int i = 1; i < nums.size(); i++){
            if(nums[i-1] == nums[i]){
                return true;
            }
        }
        return false;
    }
};

int main(){
    Solution solution;
    vector<int> nums = {1,2,3, 1};
    cout << solution.containsDuplicate(nums) << endl;
}