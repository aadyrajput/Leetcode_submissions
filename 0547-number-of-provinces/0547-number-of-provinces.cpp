class Solution {
public:
vector<int> adj[205];
void fun(int i,vector<int> &vis){
    vis[i]=1;
    for(auto it:adj[i]){
        if(vis[it])continue;
        fun(it,vis);
    }
}

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<int> vis(n,0);
        int ans=0;
        for(int i=0;i<n; i++){
            for(int j=0;j<n;j++){
                if(i!=j && isConnected[i][j]==1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
              }
           }
        for(int i=0;i<n; i++){
            if(!vis[i]){
                fun(i,vis);
                ans++;
            }
        }
    return ans;
    }
};