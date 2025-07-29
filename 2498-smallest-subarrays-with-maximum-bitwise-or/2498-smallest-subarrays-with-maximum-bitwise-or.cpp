class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        vector<int> ans;
        int maxOr=0;
        vector<int> bits(32,-1);
        for(int i=nums.size()-1; i>=0; i--){
                maxOr|=nums[i];
                int curr=nums[i];
                for(int j=0; j<32; j++){
                    if(curr & (1<<j)){
                     bits[j]=i;
                    }
                }
                int maxa=*max_element(bits.begin(),bits.end());
                if(maxa==-1) ans.push_back(1);
                else ans.push_back(maxa-i+1);
                }
            reverse(ans.begin(),ans.end());
        return ans;
    }
};