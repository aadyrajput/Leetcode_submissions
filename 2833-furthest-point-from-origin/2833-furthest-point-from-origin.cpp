class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int ct=0;
        int ans=0;
        int res=0;
        for(auto it:moves){
            if(it=='L')res++;
            else if(it=='R')res--;
            else ct++;
        }
        ans=max(ans,abs(res)+ct);
        return ans;
    }
};