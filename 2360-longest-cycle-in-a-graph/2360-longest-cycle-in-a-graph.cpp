class Solution {
public:
vector<vector<int>> adj;
vector<int> v;
vector<bool> vis,pathvis;
int ans=0;
int ct=1;

void cycleExist(int x){
    vis[x]=true;
    pathvis[x]=true;
    v[x]=ct; ct++;
    for(auto it:adj[x]){
        if(vis[it]){
            if(pathvis[it]){
                ans=max(ans,abs(v[it]-v[x])+1);
            }
        }
        else{
            cycleExist(it);
        }
    }
    pathvis[x]=false;
}
    int longestCycle(vector<int>& edges) {
         int n=edges.size();
         adj.resize(n+1); vis.resize(n+1); pathvis.resize(n+1); v.resize(n+1);
        for(int i=0;i<edges.size(); i++){
            if(edges[i]==-1)continue;
            adj[i].push_back(edges[i]);
        }

        for(int i=0;i<n;i++){
            if(vis[i])continue;
            cycleExist(i);
        }
        if(ans==0)return -1;
        return ans;

    }
};