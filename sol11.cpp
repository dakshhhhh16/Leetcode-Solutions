#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxWater = 0;
        int lp = 0, rp= height.size()-1;

        while (lp < rp) {
            int w = rp -lp;
            int ht = min(height[lp], height[rp]);
            int currWater = w* ht;
            maxWater = max(maxWater, currWater);

            height[lp] < height[rp] ? lp++ : rp--; //ternary operator used to to select the pointer which gives an impact to the height
        }
        return maxWater;        
    }
};
//11
//jhaskdjkjadh
//kjasdhkjash
//kjasdhkjash
//kjasdhkjash       
    //kljasdl
    