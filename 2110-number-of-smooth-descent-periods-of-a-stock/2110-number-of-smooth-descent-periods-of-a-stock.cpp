class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        int n=prices.size();
        long long ans=n;
        int ct=1;
        for(int i=1;i<n;i++){
            int z=prices[i-1]-prices[i];
            if(z==1)ct++;
            else{
                if(ct==1)continue;
                long long z=(ct*1ll*(ct-1))/2;
                ans+=z;
                ct=1;
            }
        }
        if(ct!=1)ans+=((ct*1ll*(ct-1))/2);
        return ans;

    }
};