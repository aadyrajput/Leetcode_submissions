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
 static bool comp(vector<int>&a,vector<int>&b){
    return a[2]<b[2];
 }
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        int z=queries.size();
        vector<bool> ans(z);
        DisjointSet ds(n);
        sort(edgeList.begin(),edgeList.end(),comp);
        for(int i=0;i<queries.size();i++){
            queries[i].push_back(i);
        }
        sort(queries.begin(),queries.end(),comp);
        int ptr=0;

        for(auto it:queries){
            int a=it[0], b=it[1], limit=it[2], idx=it[3];
            while(ptr<edgeList.size() && edgeList[ptr][2]<limit){
                 ds.unionBySize(edgeList[ptr][0],edgeList[ptr][1]);
                 ptr++;
            }
            if(ds.findPar(a)==ds.findPar(b))ans[idx]=true;
            else ans[idx]=false;
        }
        return ans;
    }
};