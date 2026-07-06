class Solution {
public:
      bool fun(int mid,vector<int>&v,int days){
        int ct=0; int sum=0;
        for(auto it:v){
             sum+=it;
             if(sum<mid)continue;
             if(sum==mid){ct++; sum=0;}
             else {ct++; sum=it;}    
        }
        if(sum!=0)ct++;
        if(ct<=days)return true;
        return false;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int n=weights.size();
        int sum=0; int maxa=0;
        for(auto it:weights){sum+=it; maxa=max(maxa,it);}
        int lo=maxa, hi=sum;
        int ans=0;

        while(lo<=hi){
            int mid=(lo+hi)/2;
            if(fun(mid,weights,days)){
                ans=mid; hi=mid-1;
            }
            else{
                lo=mid+1;
            }   
        }
        return ans;

    }
};