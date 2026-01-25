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
    int removeStones(vector<vector<int>>& stones) {
        int x=0,y=0;
        for(auto it:stones){
            x=max(x,it[0]);
            y=max(y,it[1]);
        }
        int n=stones.size();
        DisjointSet ds(x+y+1);
        unordered_map<int,int> m;
        for(auto it:stones){    
          ds.unionBySize(it[0],it[1]+x+1);  
          m[it[0]]=1; m[it[1]+x+1]=1;
        }
        int ans=0;
        for(auto it:m){
            if(ds.findPar(it.first)==it.first)ans++;
        }
return n-ans;

    }
};