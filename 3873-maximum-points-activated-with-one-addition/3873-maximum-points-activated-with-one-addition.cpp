class DisjointSet {
    public:
    vector<int> par,size;
    DisjointSet(int n){
        par.resize(n+1);
        size.resize(n+1,1);
        for(int i=0;i<=n; i++){
            par[i]=i;
        }
    }
    int findPar(int x){
        if(x==par[x])return x;
        return par[x]=findPar(par[x]);
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
    int maxActivated(vector<vector<int>>& points) {
        int n=points.size();
        DisjointSet ds(n);
        unordered_map<int,int> mpx,mpy;

        for(int i=0;i<n;i++){
            int x=points[i][0];
            int y=points[i][1];
            if(mpx.count(x)) ds.unionBySize(i,mpx[x]);
            else mpx[x]=i;
            if(mpy.count(y)) ds.unionBySize(i,mpy[y]);
            else mpy[y]=i;
        }

        vector<int> v;
        for(int i=0;i<n; i++){
            if(ds.findPar(i)==i)v.push_back(ds.size[i]);
        }
        sort(v.begin(),v.end(),greater<int>());
        if(v.size()==1)return v[0]+1;
        return v[0]+v[1]+1;


    }
};