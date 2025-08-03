class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int ind=-1;
        int n=nums.size();
        for(int i=0;i<n-1;i++){
            if(nums[i]==nums[i+1])return false;
            if(nums[i]>nums[i+1]){ind=i;break;}
        }
        if(ind==-1 || ind==0)return false;
        int ind2=-1;
        for(int i=ind; i<n-1; i++){
            if(nums[i]==nums[i+1]) return false;
             if(nums[i]<nums[i+1]){ind2=i;break;}
        }
        if(ind2==-1)return false;
        for(int i=ind2; i<n-1; i++){
             if(nums[i]>=nums[i+1]) return false;
            }
        return true;


    }
};