class Solution {
public:
    bool check(vector<int>& nums) {
        int ct=0; int n=nums.size();
        for(int i=0; i<n-1; i++){
            if(nums[i]>nums[i+1]) ct++;
        }
        if(nums[n-1]>nums[0]) ct++;
        if(ct==0 || ct==1) return true;
        return false;

    }
};