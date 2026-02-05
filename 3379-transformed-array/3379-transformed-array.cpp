class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n,0);
        for(int i=0;i<n;i++){
            if(nums[i]==0)ans[i]=nums[i];
            else if(nums[i]>0)ans[i]=nums[(i+nums[i])%n];
            else {
                int z=i+nums[i];
                if(z>=0)ans[i]=nums[z];
                else{
                    z=abs(z);
                    if(z%n==0)ans[i]=nums[0];
                    else ans[i]=nums[n-z%n];
                }
            }
        }
        return ans;
    }
};