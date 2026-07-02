class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans(n,0);
        for(int i=0;i<n;i++){
            if(nums[i]%2==0){
                ans[i]=-1; continue;
            }
            for(int j=0;j<nums[i];j++){
                if((j|(j+1))==nums[i]){ans[i]=j; break;}
            }
        }

        return ans;
    }
};