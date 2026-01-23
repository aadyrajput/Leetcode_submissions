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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n=accounts.size();
        unordered_map<string,int> m;
        DisjointSet ds(n);
        for(int i=0;i<n; i++){
            for(int j=1; j<accounts[i].size();j++){
                if(m.find(accounts[i][j])==m.end()){
                    m[accounts[i][j]]=i;
                }
                else ds.unionBySize(i,m[accounts[i][j]]);
            }
        }
        vector<string> v[1000];
        for(auto it:m){
            string x=it.first;
            int node=ds.findPar(it.second);
            v[node].push_back(x);
        }
        vector<vector<string>> ans;
        for(int i=0;i<n; i++){
            if(v[i].size()==0)continue;
            sort(v[i].begin(),v[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for(auto it:v[i])temp.push_back(it);
            ans.push_back(temp);
        }

        return ans;
    }
};