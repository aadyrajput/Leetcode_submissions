class Solution {
public:
    int minimumDistance(vector<int>& nums) {
        map<int,vector<int>> m;
        int n=nums.size();
        for(int i=0;i<n; i++){
            m[nums[i]].push_back(i);
        }
        int ans=INT_MAX;
        for(auto it:m){
            vector<int> v=it.second;
            int sz=v.size();
            if(sz<3)continue;
            for(int i=0; i<=v.size()-3; i++){
                int zz=abs(v[i]-v[i+1])+abs(v[i+1]-v[i+2])+abs(v[i+2]-v[i]);
                ans=min(ans,zz);
            }
        }
        if(ans==INT_MAX)return -1;
        return ans;


    }
};