class Solution {

public:
    int maxProfit(vector<int>& prices) {
        int mina=prices[0];
        int maxProfit=0;
        for(int i=0; i<prices.size(); i++){
             mina=min(mina,prices[i]);
            maxProfit=max(maxProfit,prices[i]-mina);
           
        }
        return maxProfit;
    }
};