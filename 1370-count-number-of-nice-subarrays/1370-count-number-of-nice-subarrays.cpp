class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> v(n,0);
        for(int i=0;i<n; i++){
            if(nums[i]%2!=0) v[i]=1;
        }
        for(int i=1; i<n; i++)v[i]+=v[i-1];
         int ans=0;
        map<int,int>m;
        for(int i=0;i<n; i++){
            int x=v[i];
            if(x==k) ans++;
            if(m.find(x-k)!=m.end())ans+=m[x-k];
            m[x]++;
        }
        return ans;
    }
};