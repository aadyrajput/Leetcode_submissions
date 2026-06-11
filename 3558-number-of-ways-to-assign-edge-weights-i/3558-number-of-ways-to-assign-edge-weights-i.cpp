class Solution {
public:
    const int M=1e9+7;
    long long bin_pow(long long a,long long b){
        long long ans=1;
        while(b){
            if(b%2==1) ans=(ans*1ll*a)%M;
            b=b>>1;
            a=(a*1ll*a)%M;
        }
        return ans;
    }

    vector<int> h;
    vector<vector<int>> adj;
    vector<bool> vis;
    int maxa=0;

    void dfs(int x,int par){
        vis[x]=true;
        for(auto it:adj[x]){
            if(vis[it])continue;
            dfs(it,x);
            h[x]=max(h[x],1+h[it]);
            maxa=max(maxa,h[x]);
        }
    }

    int assignEdgeWeights(vector<vector<int>>& edges) {
        int z=edges.size();
        int n=z+1;
        h.resize(n+1,0);
        vis.resize(n+1,false);
         adj.resize(n+1);
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vis[1]=true;
        dfs(1,-1);
      //  return maxa;
        if(maxa==1)return 1;
    return bin_pow(2,maxa-1);
    }
};