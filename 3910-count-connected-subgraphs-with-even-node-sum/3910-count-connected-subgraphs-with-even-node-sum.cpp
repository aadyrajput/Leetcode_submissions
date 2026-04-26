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
    int evenSumSubgraphs(vector<int>& nums, vector<vector<int>>& edges) {
        int n=nums.size();
        int subsets=1<<n;
        int ans=0;
        for(int i=0;i<subsets;i++){
            int sum=0;
            set<int> st;
            for(int j=0;j<n;j++){
                if(i&(1<<j)){
                    sum+=nums[j];
                    st.insert(j);
                }
            }
            if(sum%2!=0)continue;
            
            DisjointSet ds(n);
            for(auto it:edges){
                if(st.find(it[0])!=st.end() && st.find(it[1])!=st.end()){
                    ds.unionBySize(it[0],it[1]);
                }
            }
            set<int> parent;
            for(auto it:st){
                parent.insert(ds.findPar(it));
            }
            if(parent.size()==1)ans++;
        }
    return ans;
    }
};