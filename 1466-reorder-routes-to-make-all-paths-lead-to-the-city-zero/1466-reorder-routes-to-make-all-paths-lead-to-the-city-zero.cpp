class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        const int N=5e4+2;
        vector<pair<int,int>> adj[N];
        for(int i=0;i<n-1;i++){
            int x=connections[i][0], y=connections[i][1];
            adj[x].push_back({y,1});
            adj[y].push_back({x,0});
        }
         int ans=0;
        queue<int> q;
        q.push(0);
        vector<bool> vis(n,false);
        vis[0]=true;
        while(!q.empty()){
            int x=q.front();
            q.pop();
            for(auto it:adj[x]){
                if(vis[it.first])continue;
                ans+=it.second;
                vis[it.first]=true;
                q.push(it.first);
            }
        }
        return ans;


    }
};