class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        multiset<int> m;  int n=nums.size();
        for(int i=0;i<k; i++){
            m.insert(nums[i]);
        }
        vector<int> ans;
        auto it=m.end(); it--;
        ans.push_back(*it);
        int p1=0;
        for(int i=k; i<n; i++){
            m.erase(m.find(nums[p1]));
            m.insert(nums[i]);
            auto itt=m.end(); itt--;
            ans.push_back(*itt);
            p1++;
        }
    return ans;
    }
};