class Solution {
private:
bool isCycle(int x,vector<bool> &vis,vector<bool>&pathvis,vector<vector<int>> &adj){
    vis[x]=true;
    pathvis[x]=true;
    for(auto it:adj[x]){
        if(vis[it]){
            if(pathvis[it])return true;
        }
        else{
            if(isCycle(it,vis,pathvis,adj))return true;
        }
    }
    pathvis[x]=false;
    return false;
}
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n=colors.size();
        vector<bool>vis(n,false),pathvis(n,false);
        vector<vector<int>> adj(n);
        vector<int> indegree(n,0);
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            indegree[it[1]]++;
        }
        for(int i=0;i<n;i++){
            if(!vis[i]){
                if(isCycle(i,vis,pathvis,adj)) return -1;
            }
        }

        vector<vector<int>> v(n,vector<int>(26,0));

        queue<int> q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0)q.push(i);
        }
        int ans=0;
        while(!q.empty()){
            int x=q.front();
            v[x][colors[x]-'a']++;
            ans=max(ans,v[x][colors[x]-'a']);
            q.pop();
            for(auto it:adj[x]){
                indegree[it]--;
                for(int j=0;j<26;j++){
                    v[it][j]=max(v[it][j],v[x][j]);
                }
                if(indegree[it]==0)q.push(it);
            }
        }
        return ans;

        


    }
};