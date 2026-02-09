class Solution {
public:
static const int N=3e4+2;
 vector<int> adj[N];
 vector<int> subsize,subsum;

void dfs(int node,int par){
    subsize[node]=1;
    subsum[node]=0;
    for(auto it:adj[node]){
        if(it==par)continue;
        dfs(it,node);
        subsize[node]+=subsize[it];
        subsum[node]+=subsum[it]+subsize[it];
    }
}
void dfs2(int n,int node,int par){
    for(auto it:adj[node]){
        if(it==par)continue;
        subsum[it]=subsum[node]-subsize[it]+(n-subsize[it]);
        dfs2(n,it,node);
    }
}

    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        subsize.resize(n);
        subsum.resize(n);
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        dfs(0,-1);
        dfs2(n,0,-1);
    return subsum;

    }
};