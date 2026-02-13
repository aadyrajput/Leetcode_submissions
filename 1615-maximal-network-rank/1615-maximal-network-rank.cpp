class DisjointSet{
public:
vector<int> par,size;
DisjointSet(int n){
    par.resize(n+1);
    size.resize(n+1,1);
    for(int i=0;i<=n;i++)par[i]=i;
}
int findPar(int u){
    if(u==par[u])return u;
    return par[u]=findPar(par[u]);
}
void unionBySize(int u, int v){
    int up=findPar(u);
    int vp=findPar(v);
    if(up==vp)return;
    if(size[up]<size[vp]){
        size[vp]+=size[up];
        par[up]=vp;
    }
    else{
        size[up]+=size[vp];
        par[vp]=up;
    }
}
};

class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<vector<int>> adj(n);
        for(int i=0; i<roads.size(); i++){
            adj[roads[i][0]].push_back(roads[i][1]);
            adj[roads[i][1]].push_back(roads[i][0]); 
        }
        
        int ans=0;
        for(int i=0;i<n; i++){
            for(int j=i+1; j<n; j++){
               set<pair<int,int>> st;
               for(auto it:adj[i])st.insert({min(it,i),max(it,i)});
               for(auto it:adj[j])st.insert({min(it,j),max(it,j)});
               int z=st.size();
            ans=max(ans,z);
            }
        }
        return ans;

    }
};