class Solution {
public:
    int findGCD(vector<int>& nums) {
        int maxa=-1, mina=1e4;
        for(auto it:nums){
            mina=min(mina,it);
            maxa=max(maxa,it);
        }
        return __gcd(mina,maxa);
    }
};