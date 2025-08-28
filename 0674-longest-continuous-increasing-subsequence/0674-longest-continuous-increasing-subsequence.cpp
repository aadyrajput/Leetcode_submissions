class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int ct=0; 
        int ans=0;
         int prev=-1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>prev){
              ct++;
              prev=nums[i];
            ans=max(ans,ct);
            }
            else{ct=1; prev=nums[i];}
        }
        ans=max(ans,ct);
        return ans;
    }
};