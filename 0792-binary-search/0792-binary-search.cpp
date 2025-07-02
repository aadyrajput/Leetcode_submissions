class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int lo=0; int hi=n-1;
        while(abs(hi-lo)>1){
            int mid=(lo+hi)/2;
            if(nums[mid]<=target) lo=mid;
            else hi=mid;
        }
        if(nums[lo]==target)return lo;
        else if(nums[hi]==target)return hi;
        else return -1;
    }
};