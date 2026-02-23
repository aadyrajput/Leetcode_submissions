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
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
        DisjointSet ds(n);
        for(auto it:edges){
            ds.unionBySize(it[0],it[1]);
        }
        map<int,vector<int>> m;
        for(auto it:edges){
            m[ds.findPar(it[0])].push_back(it[2]);
        }
        map<int,int> m2;
        for(auto it:m){
            vector<int> v=it.second;
            if(v.size()==1)m2[it.first]=v[0];
            else{
              int andd=v[0];
              for(int i=1;i<v.size();i++){
                andd=andd&v[i];
              }
            m2[it.first]=andd;
            }
        }

        int q=query.size();
        vector<int> ans;
        for(auto it:query){
            if(ds.findPar(it[0])!=ds.findPar(it[1]))ans.push_back(-1); 
            else ans.push_back(m2[ds.findPar(it[0])]);
        }
        return ans;
    }
};