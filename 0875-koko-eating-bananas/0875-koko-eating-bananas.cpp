class Solution {
public:
    bool fun(int mid,vector<int>&piles,int h){
        int ct=0;
        for(auto it:piles){
            ct+=(it/mid);
            if(it%mid!=0)ct++;
            if(ct>h)return false;
        }
    return true;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n=piles.size();
        int maxa=0;
        for(auto it:piles)maxa=max(maxa,it);
        int lo=1, hi=maxa;
        int ans=0;

        while(lo<=hi){
            int mid=(lo+hi)/2;
            if(fun(mid,piles,h)){
                ans=mid; hi=mid-1;
            }
            else{
                lo=mid+1;
            }   
        }
        return ans;

    }
};