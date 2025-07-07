class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        priority_queue<int,vector<int>,greater<>> pq;
        sort(events.begin(),events.end());
        int maxa=-1; int n=events.size();
        for(auto it:events)maxa=max(maxa,it[1]);
        int ans=0; int j=0; 
        for(int i=0; i<=maxa; i++){
            while(j<n && events[j][0]<=i ){
                pq.push(events[j][1]); j++;
            }
            while(!pq.empty() && pq.top()<i){
                pq.pop();
            }
            if(!pq.empty()){
                pq.pop(); ans++;
            }

        }
        return ans;
    }
};