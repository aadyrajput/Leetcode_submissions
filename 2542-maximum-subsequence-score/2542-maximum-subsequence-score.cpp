class Solution {
public:
    // nums2 ko descending order me arrange karlo, nums1 ko isse ke order rearragne karlo, ab hame pta hai ith nums2 ki value min hai, to us index ke pahle ki values on nums1 ka sum karo aur nums2[i] se product karo, min heap ka size k rakho 
    
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