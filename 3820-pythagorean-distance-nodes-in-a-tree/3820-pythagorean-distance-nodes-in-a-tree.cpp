class Solution {
public:
   void fun(int f,vector<vector<int>>&adj, vector<int> &dis,int n){
        dis[f]=0;
        queue<int> q;
        vector<bool> vis(n,false);
        vis[f]=true;
        q.push(f);
        while(!q.empty()){
            int x=q.front();
            q.pop();
            for(auto it:adj[x]){
                if(vis[it])continue;
                    dis[it]=dis[x]+1; vis[it]=true;
                    q.push(it);
            }
        }
   }

    int specialNodes(int n, vector<vector<int>>& edges, int x, int y, int z) {
        vector<vector<int>> adj(n);
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int> dis1(n,1e9), dis2(n,1e9),dis3(n,1e9);
        fun(x,adj,dis1,n);
        fun(y,adj,dis2,n);
        fun(z,adj,dis3,n);
        int ans=0;
        for(int i=0;i<n; i++){
            vector<int> temp={dis1[i],dis2[i],dis3[i]};
            sort(temp.begin(),temp.end());
            long long a=temp[0]*1ll*temp[0];
            long long b=temp[1]*1ll*temp[1];
            long long c=temp[2]*1ll*temp[2];
            if(a+b==c)ans++;
        }
    return ans;


    }
};