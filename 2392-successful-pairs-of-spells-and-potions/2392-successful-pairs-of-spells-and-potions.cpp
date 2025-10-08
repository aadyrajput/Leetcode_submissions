class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(),potions.end());
        int m=spells.size(); int n=potions.size();
        vector<int> res(m,0);

        for(int i=0;i<m; i++){
            int lo=0; int hi=n-1;
            int x=spells[i]; 
            int ans=0;
            while(lo<=hi){
                int mid= lo+ (hi-lo)/2;
                long long z=potions[mid]*1ll*x;
                if(z>=success){
                    ans=n-mid; hi=mid-1;
                }
                else{
                    lo=mid+1;
                }
            }
            res[i]=ans;
        }

        return res;
    }
};