class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<pair<int,int>> adj[105];
        for(auto it:times){
            adj[it[0]].push_back({it[1],it[2]});
        }
        vector<int> dist(n+1,1e9); dist[0]=0;
        dist[k]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>> pq;
        pq.push({0,k});
        while(!pq.empty()){
            int d=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            for(auto it:adj[node]){
                int nxt=it.first; int time=it.second;
                if( time+d<dist[nxt]){
                    dist[nxt]=d+time;
                    pq.push({dist[nxt],nxt});
                }
            }
        }
    int ans=-1;
    for(auto it:dist){
        ans=max(ans,it);
    }
    if(ans==1e9)return -1;
    return ans;
    

    }
};