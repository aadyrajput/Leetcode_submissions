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
    int fun(vector<pair<int,pair<int,int>>>&v,int n,int summ,int forceu,int forcev){
         DisjointSet ds(n);
         int ct=0;
         if(forceu!=-1){
            ds.unionBySize(forceu,forcev);ct++;
         }
        for(auto it:v){
            int wt=it.first;
            int u=it.second.first, v=it.second.second;
            if(ds.findPar(u)!=ds.findPar(v)){
                summ+=wt; ds.unionBySize(u,v);
                ct++;
            }
        }
        for (int i = 0; i < n; i++) {
        ds.par[i] = i; 
        ds.size[i] = 1; 
        }
        if(ct!=n-1)return 1e9; 
        return summ;
    }

    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        int mst_sum=0; 
        vector<pair<int,pair<int,int>>> v;
        for(auto it:edges){
            v.push_back({it[2],{it[0],it[1]}});
        }
        sort(v.begin(),v.end());
       int summm=0;
       int minsum=fun(v,n,summm,-1,-1);

        vector<int> critical,psuedo;
        for(int i=0;i<edges.size(); i++){
            vector<pair<int,pair<int,int>>> v;
            for(int j=0;j<edges.size(); j++){
                if(j==i)continue;
                v.push_back({edges[j][2],{edges[j][0],edges[j][1]}});
            }
            sort(v.begin(),v.end());

            int summ=0;
            int z=fun(v,n,summ,-1,-1);
            if(z==1e9 || z>minsum){critical.push_back(i); continue;}
            summ=edges[i][2];
            int zz=fun(v,n,summ,edges[i][0],edges[i][1]);
            if(zz==minsum)psuedo.push_back(i);
        }

    return {critical,psuedo};
    }
};