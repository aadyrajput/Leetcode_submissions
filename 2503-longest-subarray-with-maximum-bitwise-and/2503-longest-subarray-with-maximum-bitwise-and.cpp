class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxa=*max_element(nums.begin(),nums.end());
        int ct=0; int ans=0;
        for(int i=0;i<nums.size(); i++){
            if(nums[i]==maxa){
                ct++;
                ans=max(ans,ct);
            }
            else{
                ct=0;
            }
        }
        return ans;

    }
};