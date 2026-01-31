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
    long long countPairs(int n, vector<vector<int>>& edges) {
        DisjointSet ds(n);
        for(auto it:edges){
            ds.unionBySize(it[0],it[1]);
        }
        long long ans=0;
        vector<long long> v;
        map<int,int> m;
        for(int i=0;i<n;i++){
            if(ds.findPar(i)==i)m[ds.size[i]]++;
        }
        int z=0;
        for(auto it:m)z+=it.second;
        
        for(auto it:m){
            int a=it.first;
            int b=it.second;
            long long z=(b*1ll*(b-1))/2;
            long long zz= a*1ll*a;
            z=(z*1ll*zz);
            ans+=z;
            v.push_back(a*1ll*b);
        }
        
        for(int i=0;i<v.size(); i++){
            for(int j=i+1;j<v.size(); j++){
                long long zz=v[i]*1ll*v[j];
                ans+=zz;
            }
        }
        return ans;


    }
};