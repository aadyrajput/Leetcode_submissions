class Solution {
public:
    bool fun(long long mid,vector<int>&v,int t){
        long long ct=0;
        for(auto it:v){
            long long z=it;
            ct+=(mid/z);
            if(ct>=t)return true;
        }
        return false;
    }

    long long minimumTime(vector<int>& time, int totalTrips) {
        int n=time.size();

        long long lo=1,hi=1e14;
        long long ans=0;
        while(lo<=hi){
            long long mid=(lo+hi)/2;
            if(fun(mid,time,totalTrips)){
                ans=mid; hi=mid-1;
            }
            else lo=mid+1;
        }
    return ans;
    }
};