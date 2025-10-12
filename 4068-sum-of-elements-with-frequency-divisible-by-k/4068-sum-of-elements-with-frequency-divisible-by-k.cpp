class Solution {
public:
    int sumDivisibleByK(vector<int>& nums, int k) {
        map<int,int> m;
        for(auto it:nums)m[it]++;
        int sum=0;
        for(auto it:m)if(it.second%k==0)sum+=(it.second*1ll*it.first);
        return sum;

    }
};