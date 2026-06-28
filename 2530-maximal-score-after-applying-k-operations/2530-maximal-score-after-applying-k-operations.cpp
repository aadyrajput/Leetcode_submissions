class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        priority_queue<int> pq;
        for(auto it:nums)pq.push(it);
        long long ans=0;
    while(k-- && !pq.empty()){
        long long z=pq.top(); pq.pop();
        ans+=z;
        int zz=z/3;
        if(z%3!=0)zz++;
        pq.push(zz);
    }

    return ans;
    }
};