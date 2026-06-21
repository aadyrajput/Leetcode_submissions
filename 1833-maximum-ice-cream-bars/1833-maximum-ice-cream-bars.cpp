class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int ct=0;
        sort(costs.begin(),costs.end());
        for(auto it:costs){
            if(it<=coins){
                ct++; coins-=it;
            }
            else break;
        }
        return ct;   
    }
};