class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int maxProfit = 0, buyPrice = prices[0];
        
        for(int i=0; i<n; i++){
            if(prices[i] < buyPrice){ 
                buyPrice = prices[i];
                }
            else{
                int currentProfit = prices[i] - buyPrice;
                maxProfit = max(currentProfit, maxProfit);
            }
        }
        return maxProfit;
    }
};
