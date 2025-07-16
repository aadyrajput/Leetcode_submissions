class Solution {
public:
    int maxProduct(vector<int>& nums) {
         int ans=INT_MIN;
        int x=1;
        for(int i=0;i<nums.size(); i++){
            x=x*nums[i];
            ans=max(ans,x);
            if(x==0) x=1;
        }
         x=1;
        for(int i=nums.size()-1;i>=0; i--){
            x=x*nums[i];
            ans=max(ans,x);
            if(x==0) x=1;
        }
        return ans;


    }
};