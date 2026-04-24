class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
      int n=nums.size();
      vector<long long> ans(n,0);
     map<int,vector<int>> m;
     for(int i=0;i<n;i++){
        m[nums[i]].push_back(i);
     }

     for(auto it:m){
        vector<int> v=it.second;
        long long totsum=0;
        for(auto itt:v)totsum+=itt;

        long long lsum=0, rsum=0;
        for(int i=0;i<v.size();i++){
            rsum=totsum-lsum-v[i];
            long long z=0;
            z+=((v[i]*1ll*i)-lsum);
            z+=(rsum-(v[i]*1ll*(v.size()-1-i)));
            ans[v[i]]=z;
            lsum+=v[i];
        }
     }

      return ans;
    }
};