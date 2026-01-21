class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        vector<int> ans;
        for(auto it:nums){
            int res=-1;
            int d=1;
            while((d&it)!=0){
                res=it-d;
                d= d<<1;
            }
            ans.push_back(res);
        }
    return ans;
    }
};