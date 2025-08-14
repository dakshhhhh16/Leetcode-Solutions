#include <iostream>
#include <vector>
#include <climits>  // for INT_MIN
#include <algorithm> // for std::max

using namespace std;
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currSum=0 , maxSum= INT_MIN ;
        for (int val : nums) {
            currSum= currSum + val;
            maxSum = max(currSum,maxSum);
            if (currSum < 0 ){
                currSum = 0;
            }
        }
    return maxSum;
        
    }
};