#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    // Recursive helper function to generate all subsets
    void getAllSubsets(vector<int>& nums, vector<int>& ans, int i, vector<vector<int>> &allSubsets) {
        // Base case: if we've considered all elements
        if (i == nums.size()) {
            allSubsets.push_back(ans);  // store the current subset
            return;
        }

        // ---------- Include nums[i] ----------
        ans.push_back(nums[i]);  // include current element
        getAllSubsets(nums, ans, i + 1, allSubsets);  // move to next element

        ans.pop_back();  // backtrack: remove last element added

        // ---------- Exclude nums[i] ----------
        // Skip duplicates by moving `idx` to the next distinct number
        int idx = i + 1;
        while (idx < nums.size() && nums[idx] == nums[idx - 1]) idx++;

        // recursive call excluding nums[i]
        getAllSubsets(nums, ans, idx, allSubsets);
    }

    // Main function to return all subsets (without duplicates)
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        // Sort input so that duplicates are adjacent
        sort(nums.begin(), nums.end());

        vector<vector<int>> allSubsets;  // stores all subsets
        vector<int> ans;                 // temporary subset

        // Generate subsets starting from index 0
        getAllSubsets(nums, ans, 0, allSubsets);

        return allSubsets;  // return result
    }
};
