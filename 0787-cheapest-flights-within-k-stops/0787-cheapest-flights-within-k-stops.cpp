class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>> adj[105];
        for(auto it:flights){
            adj[it[0]].push_back({it[1],it[2]});
        }
        vector<int> dist(n,1e9);
        dist[src]=0;
         priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<>> pq;
        pq.push({0,{0,src}});
        while(!pq.empty()){
            int stops=pq.top().first;
            int d=pq.top().second.first;
            int node=pq.top().second.second;
            pq.pop();
            for(auto it:adj[node]){
                int nxt=it.first; int wt=it.second;
                if(stops<=k && d+wt<dist[nxt]){
                    dist[nxt]=d+wt;
                    pq.push({stops+1,{dist[nxt],nxt}});
                }
            }
        }

    
    if(dist[dst]==1e9)return -1;
    return dist[dst];
    }
};