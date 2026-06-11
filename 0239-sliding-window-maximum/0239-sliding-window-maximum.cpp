class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n=nums.size();
        multiset<int> m;
        for(int i=0;i<k;i++){
            m.insert(nums[i]);
        }
        int maxa=*(--m.end());
        vector<int> ans;
        ans.push_back(maxa);
        for(int i=k; i<n;i++){
            m.erase(m.find(nums[i-k]));
            m.insert(nums[i]);
            ans.push_back(*(--m.end()));
        }
    return ans;
    }
};