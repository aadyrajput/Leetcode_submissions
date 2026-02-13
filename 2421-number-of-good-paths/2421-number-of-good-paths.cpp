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
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int n=vals.size();
        int ans=n;
        vector<vector<int>> adj(n);
        for(auto it:edges){
            if(vals[it[0]]<=vals[it[1]])adj[it[1]].push_back(it[0]);
            if(vals[it[1]]<=vals[it[0]])adj[it[0]].push_back(it[1]);
        }

        DisjointSet ds(n);
        map<int,vector<int>> m;
        for(int i=0; i<vals.size(); i++){
            m[vals[i]].push_back(i);
        }
        for(auto it:m){
            int z=it.first;
            vector<int> v=it.second;
            map<int,int> mm;
            for(int i=0;i<v.size(); i++){
                for(auto it:adj[v[i]]){
                    ds.unionBySize(it,v[i]);
                }
            }
            for(int i=0;i<v.size(); i++){
                mm[ds.findPar(v[i])]++;
            }
            for(auto it:mm){
                ans+=((it.second)*1ll*(it.second-1))/2;
            }
        }

    return ans;
    }
};