class Solution {
public:
static const int N=1e5+2;
vector<int> adj[N];

int dfs(int node,int par,vector<bool>&hasApple){
    int ans=0;
    for(auto it:adj[node]){
        if(it==par)continue;
       int z= dfs(it,node,hasApple);
       if(z>0 || hasApple[it]){
        ans+=(z+2);
       }
    }
    return ans;
}

    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
             adj[it[1]].push_back(it[0]);
        }
    return dfs(0,-1,hasApple);
    }
};