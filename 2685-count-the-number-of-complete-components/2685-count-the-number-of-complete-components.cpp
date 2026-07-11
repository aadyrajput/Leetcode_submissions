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
    void unionS(int u,int v){
      int up=findPar(u), vp=findPar(v);
      if(up==vp)return;
      if(size[up]>size[vp]){
        par[vp]=up;
        size[up]+=size[vp];
      }
      else{
        par[up]=vp;
        size[vp]+=size[up];
      }
    }
};

class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
     DisjointSet ds(n);
     vector<int> freq(n,0);
    map<int,int> m;

    for(auto it:edges){
        int a=it[0], b=it[1];
        freq[a]++; freq[b]++;
        ds.unionS(a,b);
    }
    int ans=0;

    for(int i=0;i<n;i++){
        if(freq[i]==ds.size[ds.findPar(i)]-1) m[ds.findPar(i)]++;
    }

    for(auto it:m){
        if(it.second==ds.size[it.first])ans++;
    }

    return ans;
    }
};