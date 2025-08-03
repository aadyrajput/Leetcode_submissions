class Solution {
public:
    int maxBalancedShipments(vector<int>& weight) {
        int ans=0;
        int n=weight.size();
        int maxa=weight[0];
        for(int i=1; i<n; i++){
            if(weight[i]<maxa){
                ans++; maxa=INT_MIN;
            }
            else{
                maxa=max(maxa,weight[i]);
            }
        }
        return ans;
    }
};