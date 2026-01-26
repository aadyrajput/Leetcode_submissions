class Solution {
public:
    void fun(int i,vector<vector<int>> &subtree,string &labels,vector<int>&vis,vector<vector<int>>&adj){
        subtree[i][labels[i]-'a']++;
        vis[i]=1;
        for(auto it:adj[i]){
            if(vis[it]==1)continue;
            fun(it,subtree,labels,vis,adj);
            for(int j=0;j<26;j++)subtree[i][j]+=subtree[it][j];
        }
    }
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<vector<int>> adj(n);
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<vector<int>> subtree(n,vector<int>(26,0));
        vector<int> vis(n,0);
        fun(0,subtree,labels,vis,adj);
        vector<int> ans(n,0);
        for(int i=0;i<n; i++){
            ans[i]=subtree[i][labels[i]-'a'];
        }
        return ans;

    }
};