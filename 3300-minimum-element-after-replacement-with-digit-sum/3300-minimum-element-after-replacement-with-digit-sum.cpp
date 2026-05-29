class Solution {
public:
    int sum(int z){
        int ans=0;
        while(z){
            ans+=(z%10);
            z/=10;
        }
        return ans;
    }
    int minElement(vector<int>& nums) {
     int mina=INT_MAX;
     for(auto it:nums){
        int z=sum(it);
        mina=min(mina,z);
     }
    return mina;
    }
};