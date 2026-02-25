class Solution {
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<int> dist(n,1e9);
        dist[0]=0;
        vector<vector<int>> adj(n);
        for(int i=0;i<n-1;i++){
            adj[i].push_back(i+1);
        }
        for(int i=1;i<n;i++){
            dist[i]=i;
        }
        vector<int> ans;
        for(int i=0;i<queries.size();i++){
            int a=queries[i][0], b=queries[i][1];
            adj[a].push_back(b);
            queue<int> q;
            if(dist[a]+1<dist[b]){
            dist[b]=1+dist[a];
            q.push(b);
            while(!q.empty()){
                int z=q.front();
                q.pop();
                for(auto it:adj[z]){
                    if(dist[z]+1<dist[it]){
                        q.push(it);
                    dist[it]=1+dist[z];
                    }
                }
            }
        }
        ans.push_back(dist[n-1]);
        }
    return ans;
    }
};