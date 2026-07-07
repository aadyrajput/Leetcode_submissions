class Solution {
public:
    long long fun(int z,vector<int>&v,vector<int>&cost){
        long long sum=0;
        for(int i=0;i<v.size();i++){
            sum+=(abs(v[i]-z)*1ll*cost[i]);
        }
        return sum;
    }

    long long minCost(vector<int>& nums, vector<int>& cost) {
        long long ans=0;
        int mina=INT_MAX, maxa=INT_MIN;
        for(auto it:nums){
            mina=min(mina,it);
            maxa=max(maxa,it);
        }
        int lo=mina, hi=maxa;
        while(lo<=hi){
            int mid=(lo+hi)/2;

            long long cost1=fun(mid,nums,cost);
            long long cost2=fun(mid+1,nums,cost);

            if(cost1<cost2){
                hi=mid-1; ans=cost1;
            }
            else{
                lo=mid+1; ans=cost2;
            }
    }
    return ans;
    }
};