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
    int numSimilarGroups(vector<string>& strs) {
        int n=strs.size();
        DisjointSet ds(n);
        for(int i=0;i<strs.size();i++){
            for(int j=i+1;j<strs.size();j++){
                string a=strs[i];
                string b=strs[j];
                int ct=0; bool flag=false;
                for(int i=0;i<a.size();i++){
                    if(a[i]!=b[i])ct++;
                    if(ct>2){flag=true; break;}
                }
                if(flag) continue;
                ds.unionBySize(i,j);
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            if(ds.par[i]==i)ans++;
        }
        return ans;

    }
};