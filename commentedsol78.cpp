#include <iostream>   // for input-output (not really needed on LeetCode, but fine here)
#include <vector>     // to use vector data structure
using namespace std;  // so we don’t need to write std::vector, std::cout, etc.

class Solution {
public:
    // Recursive helper function to generate all subsets
    // nums = original input array
    // ans = current subset being built
    // i = current index in nums
    // allSubsets = final collection of all subsets
    void getallSubsets(vector<int> &nums, vector<int> &ans, int i, vector<vector<int>> &allSubsets){
        
        // Base case: if we have processed all elements
        if(i == nums.size()) {
            allSubsets.push_back(ans);   // store the current subset
            return ;                     // return back to explore other possibilities
        }

        // ---------------------------------
        // Choice 1: INCLUDE nums[i] in the subset
        ans.push_back(nums[i]);                // add nums[i] into current subset
        getallSubsets(nums, ans, i+1, allSubsets);  // move to the next index

        ans.pop_back();  // backtrack: remove last element so we can explore "exclude" case

        // ---------------------------------
        // Choice 2: EXCLUDE nums[i] from the subset
        getallSubsets(nums, ans, i+1, allSubsets);  // skip nums[i] and move to next index
    }

    // Main function to be called (like from LeetCode)
    vector<vector<int>> subsets(vector<int> &nums) {
        vector<vector<int>> allSubsets; // stores all subsets
        vector<int> ans;                // temporary vector to build one subset

        // Start recursion from index 0
        getallSubsets(nums, ans, 0, allSubsets);

        // Return all generated subsets
        return allSubsets;
    }
};
