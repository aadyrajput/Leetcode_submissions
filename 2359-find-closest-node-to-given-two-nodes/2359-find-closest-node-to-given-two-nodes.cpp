class Solution {
public:
    void fun(int node,vector<int>&dist,vector<vector<int>>&adj){
        int n=dist.size();
        dist[node]=0;
        vector<bool> vis(n,false);
        vis[node]=true;
        queue<int> q; q.push(node);
        while(!q.empty()){
            int z=q.front();
            q.pop();
            for(auto it:adj[z]){
                if(vis[it])continue;
                vis[it]=true; dist[it]=dist[z]+1;
                q.push(it);
            }
        }
    }
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n=edges.size();
        vector<vector<int>> adj(n);
        for(int i=0;i<edges.size();i++){
            if(edges[i]==-1)continue;
            adj[i].push_back(edges[i]);
        }

        vector<int> dist1(n,1e9),dist2(n,1e9);
        fun(node1,dist1,adj);
        fun(node2,dist2,adj);
        int ans=INT_MAX;
        int s_ind=0;
        for(int i=0;i<n;i++){
            if(dist1[i]==1e9 || dist2[i]==1e9)continue;
            int z=max(dist1[i],dist2[i]);
            if(z<ans){
                ans=z; s_ind=i;
            }
            else if(z==ans){
                s_ind=min(s_ind,i);
            }
        }

        if(ans==INT_MAX)return -1;
        return s_ind;

    }
};