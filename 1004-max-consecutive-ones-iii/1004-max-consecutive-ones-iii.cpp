class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int ct=0;
        int ans=0;
        int ptr=0;
        for(int i=0;i<nums.size(); i++){
            if(nums[i]==0)ct++;
            while(ct>k){
                if(nums[ptr]==0) ct--;
                ptr++;
            }
            ans=max(ans,i-ptr+1);
        }
        return ans;
    }
};