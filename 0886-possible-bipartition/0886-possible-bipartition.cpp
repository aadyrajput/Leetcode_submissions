class Solution {
    vector<int>adj[2005];
    bool fun(int x,vector<int>& col,vector<bool>&vis){
        vis[x]=true;
        col[x]=0;
        queue<int> q;
        q.push(x);
        while(!q.empty()){
            int xx=q.front();
            q.pop();
            for(auto it:adj[xx]){
                if(vis[it]){
                    if(col[it]==col[xx])return true;
                }
                else{
                    q.push(it); vis[it]=true;
                    col[it]=1-col[xx];
                }
            }
        }
    return false;
    }

public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        for(auto it:dislikes){
            adj[it[0]].push_back(it[1]);
             adj[it[1]].push_back(it[0]);
        }
        vector<int> col(n+1,-1);
        vector<bool> vis(n+1,false);
        for(int i=1; i<=n; i++){
            if(!vis[i]){
                if(fun(i,col,vis)) return false;
            }
        }
        return true;

    }
};