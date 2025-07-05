class Solution {
private:
bool check(int mid,int m,int k, vector<int>bloomDay){
    int ct=0; int ans=0;
    for(int i=0;i<bloomDay.size(); i++){
        if(bloomDay[i]<=mid) ct++;
        else ct=0;

        if(ct==k){ans++; ct=0;}
        if(ans==m) return true;
    }
    return false;
}

public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        long long z=m*1ll*k; int n=bloomDay.size();
        if(z>n)return -1;
        int maxa=-1;
        for(auto it:bloomDay)maxa=max(maxa,it);
        if(z==n) return maxa;
        int lo=1; int hi=maxa;
        while(lo<=hi){
            int mid= lo+(hi-lo)/2;
            if(check(mid,m,k,bloomDay)) hi=mid-1;
            else lo=mid+1;
        }
    return lo;

    }
};