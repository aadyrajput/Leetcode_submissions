class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int n=nums.size();
        vector<int> ans;
        int xorr=0;  int k=maximumBit;
        for(auto it:nums)xorr=xorr^it;

        int z=0;
        for(int i=0;i<k;i++){
            if((xorr&(1<<i))==0)z=z|(1<<i);
        }
        ans.push_back(z);

        for(int i=n-1;i>=1;i--){
            xorr=xorr^nums[i];
            int z=0;
            for(int j=0;j<k;j++){
                if((xorr&(1<<j))==0)z=z|(1<<j);
            }
        ans.push_back(z);
        }
    
        return ans;
    }
};