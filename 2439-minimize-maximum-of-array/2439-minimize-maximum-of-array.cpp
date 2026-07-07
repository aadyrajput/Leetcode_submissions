class Solution {
public:
    int fun(int mid,vector<int>&nums){
        long long ct=0; int n=nums.size();
        for(int i=n-1;i>=0; i--){
            if(nums[i]>mid)ct+=(nums[i]-mid);
            else{
                if(mid-nums[i]>ct){ct=0;}
                else{ct-=(mid-nums[i]);}
            }
        }
    if(ct>0)return false;
    return true;
    }
    int minimizeArrayValue(vector<int>& nums) {
        int n=nums.size();
        int maxa=-1;
        for(auto it:nums){
            maxa=max(maxa,it);
        }
        int lo=1, hi=maxa;
        int ans=0;

    while(lo<=hi){
        int mid=(lo+hi)/2;
        if(fun(mid,nums)){
            ans=mid; hi=mid-1;
        }
        else{
            lo=mid+1;
        }
    }

    return ans;
    }
};