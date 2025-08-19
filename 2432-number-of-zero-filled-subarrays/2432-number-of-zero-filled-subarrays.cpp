class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans=0;
        int ct=0;
        for(int i=0;i<nums.size(); i++){
            if(nums[i]==0)ct++;
            else{
                long long x= (ct*1ll*(ct+1))/2;
                ans+=x;
                ct=0;
            }
        }
        if(ct!=0)ans+=(ct*1ll*(ct+1))/2;
        return ans;
    }
};