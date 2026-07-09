class DisjointSet{
    public:
    vector<int> size,par;
    DisjointSet(int n){
        size.resize(n+1,1);
        par.resize(n+1);
        for(int i=0;i<=n;i++){
            par[i]=i;
        }
    }
    int findPar(int u){
    if(u==par[u])return u;
    return par[u]=findPar(par[u]);
}
    void unionBySize(int u,int v){
        int up=findPar(u);
        int vp=findPar(v);
        if(up==vp)return;
        if(size[up]<size[vp]){
            par[up]=vp;
            size[vp]+=size[up];
        }
        else{
            par[vp]=up;
            size[up]+=size[vp];
        }
    }
};

class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        DisjointSet ds(n);
        for(int i=0;i<n-1;i++){
            if(abs(nums[i]-nums[i+1])<=maxDiff){
                ds.unionBySize(i,i+1);
            }
        }

        vector<bool> ans;
        for(int i=0;i<queries.size(); i++){
            int x=queries[i][0], y=queries[i][1];
            if(x==y)ans.push_back(true);
            else if(ds.findPar(x)==ds.findPar(y))ans.push_back(true);
            else ans.push_back(false);
        }
    return ans;
    }
};