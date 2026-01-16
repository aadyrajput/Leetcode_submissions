class Solution {
public:
    bool fun(int i,vector<vector<int>>&graph,vector<bool>&vis,vector<int>&col){
        vis[i]=true;
        col[i]=0;
        queue<int> q;
        q.push(i);
        while(!q.empty()){
            int x=q.front();
            q.pop();
            for(auto it:graph[x]){
                if(vis[it]){
                    if(col[it]==col[x])return true;
                }
                else{
                    vis[it]=true; col[it]=1-col[x];
                    q.push(it);
                }
            }
        }
        return false;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<bool> vis(n,false);
        vector<int> col(n,-1);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                if(fun(i,graph,vis,col))return false;
            }
        }
        return true;
    }
};