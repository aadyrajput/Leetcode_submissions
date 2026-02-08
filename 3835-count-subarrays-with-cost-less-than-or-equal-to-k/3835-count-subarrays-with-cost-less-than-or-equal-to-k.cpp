class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
      int n=nums.size();
      long long ans=0;
     map<long long,long long> m;
     int p1=0,p2=0;
     while(p1<n && p2<n){
        long long x=nums[p2];
        m[x]++;
        long long mina=m.begin()->first;
        long long maxa=m.rbegin()->first;
        long long z=(maxa-mina)*1ll*(p2-p1+1);
        while(z>k){
            if(m[nums[p1]]==1)m.erase(nums[p1]);
            else m[nums[p1]]--;
            p1++;
            if(m.size()==0)break;
            mina=m.begin()->first;
           maxa=m.rbegin()->first;
           z=(maxa-mina)*1ll*(p2-p1+1);
        }

            ans+=(p2-p1+1);
            p2++;
     }

        return ans;
    }
};