class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> m;
        for(auto it:nums)m[it]++;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> pq;
        for(auto it:m){
            pq.push({it.second,it.first});
        }
        while(pq.size()>k){
            pq.pop();
        }
        vector<int> ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second); pq.pop();
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
    }
};