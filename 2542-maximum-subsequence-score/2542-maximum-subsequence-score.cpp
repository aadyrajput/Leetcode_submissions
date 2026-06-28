class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int,int>> v;
        int n=nums1.size();
        for(int i=0;i<n;i++)v.push_back({nums2[i],nums1[i]});
        sort(v.begin(),v.end(),greater<>());
        
        priority_queue<int,vector<int>,greater<int>> pq;
        long long sum=0;
        long long ans=0;

        for(int i=0;i<n;i++){
            if(i<=k-1){
                pq.push(v[i].second);
                sum+=v[i].second;
              if(i==k-1)ans=max(ans,sum*v[i].first);
              continue;
            }
            sum+=v[i].second;
            sum-=pq.top(); pq.pop();
            pq.push(v[i].second);
            ans=max(ans,sum*v[i].first);
        }
    return ans;
    }
};