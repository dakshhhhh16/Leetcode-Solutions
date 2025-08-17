#include <iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0, bestBuy = prices[0] ; //Assuming price of first day to be the best day to buy stocks

        for (int i=1 ;i<prices.size() ; i++) {
            if (prices[i] > bestBuy) {
                maxProfit = max(maxProfit, prices[i] - bestBuy) ;
            }
            bestBuy = min(bestBuy, prices [i]);
        }
        return maxProfit;
    }
};