class Solution {
private:
static bool comp(pair<int,int>&a,pair<int,int>&b){
if(a.first==b.first)return a.second>b.second;
return a.first>b.first;
}
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        vector<int> ans;
        int n=nums.size();
        map<int,int> m;
        for(int i=0;i<k; i++){
            m[nums[i]]++;
        }
        for(int i=-1; i<n-k; i++){
            if(i>=0){
                m[nums[i]]--;
                m[nums[k+i]]++;
            }
             vector<pair<int,int>> v;
             for(auto it:m)v.push_back({it.second,it.first});   
            sort(v.begin(),v.end(),comp);
            int sum=0; 
            int szz=v.size();
            int zz=min(szz,x);
            for(int i=0; i<zz; i++){
                sum+=(v[i].first*1ll*v[i].second);
            }
            ans.push_back(sum);
        }
    return ans;
    }
};