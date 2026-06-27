class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> pq;
        for(auto it:piles)pq.push(it);

        while(k-- && !pq.empty()){
            int z=pq.top();
            pq.pop();
            pq.push((z+1)/2);
        }
        int ans=0;
        while(!pq.empty()){
            ans+=pq.top(); pq.pop();
        }
        return ans;
    }
};