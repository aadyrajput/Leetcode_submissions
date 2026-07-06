class Solution {
public:
    bool fun(int mid,vector<int>&v,int th){
        int ct=0;
        for(auto it:v){
            ct+=(it/mid);
            if(it%mid!=0)ct++;
            if(ct>th)return false;
        }
    return true;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n=nums.size();
        int maxa=0;
        for(auto it:nums)maxa=max(maxa,it);
        int lo=1, hi=maxa;
        int ans=0;

        while(lo<=hi){
            int mid=(lo+hi)/2;
            if(fun(mid,nums,threshold)){
                ans=mid; hi=mid-1;
            }
            else{
                lo=mid+1;
            }   
        }
        return ans;

    }
};