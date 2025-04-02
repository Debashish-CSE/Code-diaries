//Link: https://leetcode.com/problems/how-many-numbers-are-smaller-than-the-current-number/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

std::vector<int> smallerNumbersThanCurrent(std::vector<int>& nums) {
    std::vector<int> sortedNums = nums; // Copy original array
    std::sort(sortedNums.begin(), sortedNums.end()); // Sort the copy
    
    std::unordered_map<int, int> countMap;
    
    // Store the first occurrence index of each number in sorted array
    for (int i = 0; i < sortedNums.size(); i++) {
        if (countMap.find(sortedNums[i]) == countMap.end()) {
            countMap[sortedNums[i]] = i;
        }
    }
    
    // Build result using the hash map
    std::vector<int> result;
    for (int num : nums) {
        result.push_back(countMap[num]);
    }
    
    return result;
}

int main() {
    std::vector<int> nums = {8, 1, 2, 2, 3};
    std::vector<int> result = smallerNumbersThanCurrent(nums);

    // Print the output
    for (int num : result) {
        std::cout << num << " ";
    }
    return 0;
}
