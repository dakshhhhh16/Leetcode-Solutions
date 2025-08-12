#include<iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) { //By adding an & operator we are passing the value by reference
    int ans = 0;
    for (int val : nums) {
        ans = ans ^ val ;
    }
    return ans ;
    }
}; //changing