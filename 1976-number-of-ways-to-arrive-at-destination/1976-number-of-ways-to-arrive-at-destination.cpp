class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        const int M=1e9+7;
           vector<pair<long long,long long>> adj[205];
        for(auto it:roads){
            adj[it[0]].push_back({it[1],it[2]});
             adj[it[1]].push_back({it[0],it[2]});
        }
        vector<long long> dist(n,1e18); 
        vector<long long> ways(n,0);
        ways[0]=1;
        dist[0]=0;
    priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<>> pq;
        pq.push({0,0});
        while(!pq.empty()){
            long long d=pq.top().first;
            long long node=pq.top().second;
            pq.pop();
            if(d>dist[node])continue;
            for(auto it:adj[node]){
                long long nxt=it.first; long long time=it.second;
                if( time+d<dist[nxt]){
                    dist[nxt]=d+time;
                    pq.push({dist[nxt],nxt});
                    ways[nxt]=ways[node];
                }
                else if(time+d==dist[nxt]){
                    ways[nxt]=(ways[nxt]+ways[node])%M;
                }
            }
        }
    return ways[n-1];

    }
};