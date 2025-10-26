class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
    vector<long long> v;
    for(auto it:nums)v.push_back(it*1ll*it);
    sort(v.begin(),v.end(),greater<long long>());
    int ct=nums.size();
    int zz=(ct+1)/2;
    long long sum=0;
    for(int i=0;i<ct; i++){
        if(i<zz)sum+=v[i];
        else sum-=v[i];
    }
    return sum;
    }
};