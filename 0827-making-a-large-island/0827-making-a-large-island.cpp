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
    int largestIsland(vector<vector<int>>& grid) {
       int n=grid.size();
       DisjointSet ds(n*n);
       int delrow[4]={-1,0,1,0};
       int delcol[4]={0,-1,0,1};
       for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]==0)continue;
            for(int k=0;k<4; k++){
                int nrow=i+delrow[k];
                int ncol=j+delcol[k];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<n && grid[nrow][ncol]==1){
                    int z1=n*i+j; int z2=n*nrow+ncol;
                    ds.unionBySize(z1,z2);
                }
            }
        }
    }
    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n; j++){
            if(grid[i][j]==1)continue;
            set<int> st;
            for(int k=0;k<4;k++){
                int nrow=i+delrow[k];
                int ncol=j+delcol[k];
                if(nrow>=0 && ncol<n && ncol>=0 && nrow<n && grid[nrow][ncol]==1){
                    st.insert(ds.findPar(n*nrow+ncol));
                }
            }
           int z=0;
           for(auto it:st){
            z+=ds.size[it];
           }
            ans=max(ans,z+1);
        }
    }

    for(int i=0;i<n*n;i++){
        ans=max(ans,ds.size[ds.par[i]]);
    }

    return ans;







    }
};