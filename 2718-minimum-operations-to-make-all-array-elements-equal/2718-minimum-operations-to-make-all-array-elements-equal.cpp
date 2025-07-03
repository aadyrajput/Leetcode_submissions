class Solution {
public:
    vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<long long> pre(n,0);vector<long long> suff(n,0);
        pre[0]=nums[0]; suff[n-1]=nums[n-1];
        for(int i=1;i<n;i++)pre[i]=pre[i-1]+nums[i];
        for(int i=n-2; i>=0; i--)suff[i]=suff[i+1]+nums[i];
        vector<long long> ans;
        for(int i=0; i<queries.size(); i++){
            int x=queries[i];
            int ind=lower_bound(nums.begin(),nums.end(),x)-nums.begin();
            if(ind==n){
                long long res=(x*1ll*n)-pre[n-1];
                ans.push_back(res); continue;
              }
            if(ind==0){
                long long res=suff[0]-(x*1l*n);
                ans.push_back(res); continue;
            }
            long long res=suff[ind]-pre[ind-1]+x*1ll*(ind*2-n);
            ans.push_back(res);
        }
        return ans;
    }
};