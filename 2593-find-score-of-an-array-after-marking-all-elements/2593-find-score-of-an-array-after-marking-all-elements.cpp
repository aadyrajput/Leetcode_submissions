class Solution {
public:
    long long findScore(vector<int>& nums) {
        int n=nums.size();
        vector<bool> v(n,false);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>pq;
        for(int i=0;i<n;i++)pq.push({nums[i],i});

        long long sum=0;
        while(!pq.empty()){
            int z=pq.top().first, zind=pq.top().second;
            pq.pop();
            if(v[zind])continue;
            sum+=z; v[zind]=true;
            if(zind-1>=0)v[zind-1]=true;
            if(zind+1<n)v[zind+1]=true;
        }
    return sum;
    }
};