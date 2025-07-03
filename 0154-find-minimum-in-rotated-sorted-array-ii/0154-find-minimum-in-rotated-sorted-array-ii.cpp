class Solution {
public:
    int findMin(vector<int>& nums) {
          int ans=INT_MAX;
        int n=nums.size();
        int lo=0; int hi=n-1;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;

            if(nums[lo]==nums[mid] && nums[mid]==nums[hi]){
               ans=min(ans,nums[mid]); lo++; hi--; continue;
            }

            if(nums[lo]<=nums[mid]){
                ans=min(ans,nums[lo]);
                lo=mid+1;
            }
            else{
                ans=min(ans,nums[mid]);
                hi=mid-1;
            }
        }

        return ans;
    }
};