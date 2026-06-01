class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int sum=0;
        for(auto it:cost)sum+=it;
        int n=cost.size();
        sort(cost.begin(),cost.end());
        for(int i=n-3; i>=0; i=i-3){
            sum-=cost[i];
        }
    return sum;
    }
};