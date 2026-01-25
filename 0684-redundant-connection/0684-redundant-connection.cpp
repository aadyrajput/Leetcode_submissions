class DisjointSet{
  public:
  vector<int> rank,par,size;
  DisjointSet(int n){
    rank.resize(n+1,0);
    par.resize(n+1);
    size.resize(n+1);
    for(int i=0; i<=n; i++){
      par[i]=i;
      size[i]=1;
    }
  }
  int findPar(int node){
    if(node==par[node]) return node;
    return par[node]=findPar(par[node]);
  }
  int unionByRank(int u,int v){
    int ultpar_u=findPar(u);
    int ultpar_v=findPar(v);
    if(ultpar_u==ultpar_v) return 1;
    if(rank[ultpar_u]<rank[ultpar_v]) par[ultpar_u]=ultpar_v;
    else if(rank[ultpar_u]>rank[ultpar_v]) par[ultpar_v]=ultpar_u;
    else {par[ultpar_v]=ultpar_u; rank[ultpar_u]++;}
    return 0;
  }
   void unionBySize(int u,int v){
    int ultpar_u=findPar(u);
    int ultpar_v=findPar(v);
    if(ultpar_u==ultpar_v) return;
    if(size[ultpar_u]<size[ultpar_v]) {
      par[ultpar_u]=ultpar_v;
      size[ultpar_v]+=size[ultpar_u];
    }
    else{
      par[ultpar_v]=ultpar_u;
      size[ultpar_u]+=size[ultpar_v];
    }
  }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        DisjointSet ds(1001);
        vector<int> ans={};
        for(auto it:edges){
            int a=it[0]; int b=it[1];
            if(ds.findPar(a)!=ds.findPar(b))ds.unionBySize(a,b);
            else{
                ans={a,b}; break;
            }
        }
        return ans;

    }
};