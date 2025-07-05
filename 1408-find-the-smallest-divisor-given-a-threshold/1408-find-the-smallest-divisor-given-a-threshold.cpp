class Solution {
    private:
    bool check(int mid,vector<int>& nums, int threshold){
        int ans=0;
        for(int i=0;i<nums.size(); i++){
            int x= ceil((double)nums[i]/(double)mid);
            ans+=x;
        if(ans>threshold)return false;
        }
        return true;
    }
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
            int n=nums.size();
            sort(nums.begin(),nums.end());
            if(n==threshold) return nums[n-1];

            int lo=1; int hi=nums[n-1];
            while(lo<=hi){
                int mid= lo+(hi-lo)/2;
                if(check(mid,nums,threshold)) hi=mid-1;
                else lo=mid+1;
            }
            return lo;
    }
};