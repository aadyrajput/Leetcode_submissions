class Solution {
public:
    int maxDigitRange(vector<int>& nums) {
        map<int,int> m;
        for(auto it:nums){
            int mina=9,maxa=0;
            int z=it;
            while(z){
                mina=min(mina,z%10);
                maxa=max(maxa,z%10);
                z/=10;
            }
            m[maxa-mina]+=it;
        }
        int ans=0;
        for(auto it:m)ans=it.second;
        return ans;
    }
};