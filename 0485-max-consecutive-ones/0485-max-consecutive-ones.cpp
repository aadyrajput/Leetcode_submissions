class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans=0; int n=nums.size(); int ct=1; int ctt=0;
        for(int i=0;i<n;i++)if(nums[i]==1) ctt++;
        if(ctt==0) return 0;
        for(int i=0;i<n-1; i++){
            if(nums[i]==1 && nums[i+1]==1){ct++;}
            else {ans=max(ans,ct); ct=1; }   
        }
        ans=max(ans,ct);

        return ans;
    }
};