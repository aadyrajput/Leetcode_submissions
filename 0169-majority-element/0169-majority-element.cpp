class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int,int> m;
        for(auto it:nums)m[it]++;
        int ans=0; int res=0;
        for(auto it:m){
            if(it.second>ans){
                ans=it.second; res=it.first;
            }
        }
    return res;
    }
};