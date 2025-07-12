class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n=nums.size();
        k=k%n;
        vector<int> v;
        int x=n-k;
        for(int i=x; i<n; i++) v.push_back(nums[i]);
        for(int i=0; i<x; i++)v.push_back(nums[i]);
    nums=v;
    }
};