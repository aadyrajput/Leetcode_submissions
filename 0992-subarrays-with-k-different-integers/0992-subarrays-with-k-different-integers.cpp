class Solution {
public:
    int fun(vector<int>&nums,int k){
        if(k==0)return 0;
        int ans=0;
        map<int,int> m;
        int ptr=0;
        for(int i=0;i<nums.size(); i++){
            m[nums[i]]++;
            while(m.size()>k){
                m[nums[ptr]]--;
                if(m[nums[ptr]]==0)m.erase(nums[ptr]);
                ptr++;
            }
            ans+=(i-ptr+1);
        }
        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return fun(nums,k)-fun(nums,k-1);
    }
};