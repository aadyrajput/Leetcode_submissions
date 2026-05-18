class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n=arr.size();
        map<int,vector<int>> m;
        for(int i=0;i<n; i++){
            m[arr[i]].push_back(i);
        }
        vector<int> vis(n,0);
        vis[0]=1;
        queue<pair<int,int>> q;
        q.push({0,0});
        while(!q.empty()){
            int dis=q.front().first;
            int node=q.front().second;
            q.pop();
            if(node==n-1)return dis;
            if(node-1>=0 && vis[node-1]==0){
                vis[node-1]=1;
                q.push({dis+1,node-1});
            }
            if(node+1<n && vis[node+1]==0){
                vis[node+1]=1;
                q.push({dis+1,node+1});
            }
            for(auto it:m[arr[node]]){
                if(vis[it]==0){
                    vis[it]=1;
                    q.push({dis+1,it});
                }
                m[arr[node]].clear();
            }
        }
    return -1;
    }
};