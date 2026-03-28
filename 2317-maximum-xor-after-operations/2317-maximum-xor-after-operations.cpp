class Solution {
public:
    int maximumXOR(vector<int>& nums) {
        int ans=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            int x=nums[i];
            for(int j=0 ;j<=26; j++){
                if(x&(1<<j)) ans=(ans|(1<<j));
            }
        }
    return ans;
    }
};