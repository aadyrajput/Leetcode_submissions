class Solution {
public:
     bool fun(int mid,vector<int>&v,int m,int k){
        int ct=0; int ans=0;
        for(auto it:v){
            if(it<=mid)ct++;
            else ct=0;

            if(ct==k){ans++; ct=0;}
            if(ans==m)return true;
        }
    return false;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
         int n=bloomDay.size();
         long long z=m*1ll*k;
         if(z>n)return -1;

        int maxa=0;
        for(auto it:bloomDay)maxa=max(maxa,it);
        int lo=1, hi=maxa;
        int ans=0;

        while(lo<=hi){
            int mid=(lo+hi)/2;
            if(fun(mid,bloomDay,m,k)){
                ans=mid; hi=mid-1;
            }
            else{
                lo=mid+1;
            }   
        }
        return ans;
    }
};