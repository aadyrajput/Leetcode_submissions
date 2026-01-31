class DisjointSet{
  public:
  vector<int> par,size;
  DisjointSet(int n){
    par.resize(n+1);
    size.resize(n+1,1);
    for(int i=0; i<=n; i++){
      par[i]=i;
    }
  }
  int findPar(int node){
    if(node==par[node]) return node;
    return par[node]=findPar(par[node]);
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
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
         DisjointSet ds1(n),ds2(n);
         int ct=0;
         for(auto it:edges){
            if(it[0]==3){
                if(ds1.findPar(it[1])!=ds1.findPar(it[2])) {
                    ds1.unionBySize(it[1],it[2]);
                    ds2.unionBySize(it[1],it[2]);
                }
                else ct++;  
            }
        }
        for(auto it:edges){
            if(it[0]==1){
                if(ds1.findPar(it[1])==ds1.findPar(it[2])) ct++;
                else ds1.unionBySize(it[1],it[2]);
            }
             if(it[0]==2){
                if(ds2.findPar(it[1])==ds2.findPar(it[2])) ct++;
                else ds2.unionBySize(it[1],it[2]);
             }
        }
        int z1=0; int z2=0;
        for(int i=1;i<=n;i++){
            if(ds1.findPar(i)==i)z1++;
            if(ds2.findPar(i)==i)z2++;
        }
        if(z1==1 && z2==1)return ct;
        return -1;
        


    }
};