class Solution {
public:
    vector<int> limitOccurrences(vector<int>& nums, int k) {
        map<int,int> m;
        int n=nums.size();
        vector<int>ans;
        for(int i=0;i<n;i++){
             m[nums[i]]++;
            if(m.find(nums[i])==m.end()){
                ans.push_back(nums[i]);
                continue;
            }
            if(m[nums[i]]<=k)ans.push_back(nums[i]);
        }

        return ans;
    }
};