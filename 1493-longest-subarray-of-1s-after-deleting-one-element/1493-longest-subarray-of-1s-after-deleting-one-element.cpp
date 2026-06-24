class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int ans=0;
        int ct=0;
        int ptr=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0)ct++;
            while(ct>1){
                if(nums[ptr]==0)ct--;
                ptr++;
            }
            ans=max(ans,i-ptr);
        }
        return ans;
    }
};