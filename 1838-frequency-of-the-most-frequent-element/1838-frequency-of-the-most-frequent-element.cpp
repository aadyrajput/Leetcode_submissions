class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int n=nums.size();
        int ptr=0;
        int ans=0;
        long long totsum=0;
        sort(nums.begin(),nums.end());
        
        for(int i=0;i<n;i++){
            while((i-ptr)*1ll*nums[i]-totsum>k){
                totsum-=nums[ptr];
                ptr++;
            }
            ans=max(ans,i-ptr+1);
            totsum+=nums[i];
        }
        return ans;
    }
};