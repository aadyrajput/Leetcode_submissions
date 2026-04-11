class Solution {
public:
    int minimumDistance(vector<int>& nums) {
          map<int,vector<int>> m;
        for(int i=0;i<nums.size(); i++){
            m[nums[i]].push_back(i);
        }
        int ans=INT_MAX;
        for(auto it:m){
            vector<int> v=it.second;
            int sz=v.size();
            if(sz<=2)continue;
            for(int i=0; i<=sz-3; i++){
                ans=min(ans,abs(v[i]-v[i+1])+abs(v[i+1]-v[i+2])+abs(v[i+2]-v[i]));
            }
        }


        if(ans==INT_MAX)return -1;
        return ans;
    }
};