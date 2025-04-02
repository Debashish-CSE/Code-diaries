#include <iostream>
#include <vector>
using namespace std;

void generateSubsets(vector<int>& nums, vector<vector<int>>& result, vector<int>& currentSubset, int start) {
    // Base case: Add the current subset to the result
    result.push_back(currentSubset);
    
    // Recurse through the remaining elements starting from 'start'
    for (int i = start; i < nums.size(); ++i) {
        // Include nums[i] in the current subset
        currentSubset.push_back(nums[i]);
        
        // Recurse with the next index
        generateSubsets(nums, result, currentSubset, i + 1);
          
        // Backtrack: remove nums[i] from the current subset
        currentSubset.pop_back();
    }
}

vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> result;
    vector<int> currentSubset;
    
    // Start recursion from index 0
    generateSubsets(nums, result, currentSubset, 0);
    
    return result;
}

int main() {
    // Input array
    vector<int> nums = {1, 2, 3};
    
    // Get all subsets
    vector<vector<int>> result = subsets(nums);
    
    // Print all subsets
    for (const auto& subset : result) {
        cout << "[ ";
        for (int num : subset) {
            cout << num << " ";
        }
        cout << "] ";
    }
    
    cout << endl;
    return 0;
}


/*
Explanation:
generateSubsets function:

This is the recursive function that generates all subsets.

It takes the following parameters:

nums: the input array of integers.
result: a 2D vector that stores all the subsets.
currentSubset: a vector that holds the current subset being constructed.
start: the index from where the function should start considering the next elements of nums.
In each recursive call:

The currentSubset is added to the result vector.
The function then iterates through the remaining elements of nums starting from the index start. For each element:
It includes the element in the currentSubset and recursively explores the next subset.
After the recursion, it "backtracks" by removing the last added element from currentSubset.
subsets function:

Initializes the result vector to store all subsets and an empty currentSubset vector.
Calls the generateSubsets function starting from index 0.
main function:

Initializes a sample input array nums.
Calls the subsets function to get all subsets.
Iterates over the result and prints each subset.
*/