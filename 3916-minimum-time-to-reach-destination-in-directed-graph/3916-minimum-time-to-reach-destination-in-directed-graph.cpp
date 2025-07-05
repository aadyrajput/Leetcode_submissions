class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges) {
        if(n==1){return 0;}
        vector<vector<vector<int>>> adj(n);
        for(auto it: edges) adj[it[0]].push_back({it[1],it[2],it[3]});
        vector<int> dist(n,1e9);
        queue<pair<int,int>> q;
        q.push({0,0}); 
        dist[0]=0;
        while(!q.empty()){
            int u=q.front().first;
            int t=q.front().second;
            q.pop();
            for(auto it:adj[u]){
                int v=it[0]; int st=it[1]; int end=it[2];
                if(dist[u]>=st && dist[u]<=end && dist[v]>dist[u]+1){
                    dist[v]=dist[u]+1;
                    q.push({v,dist[v]});
                }
                else if(dist[u]<st && dist[v]>st+1){
                    dist[v]=st+1;
                    q.push({v,dist[v]});
                }
            }
        }
    if(dist[n-1]==1e9)return -1;
    else return dist[n-1];
    }
};