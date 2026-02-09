class Solution {
public:
    bool isInside(long long x1,long long y1,long long r,long long x2,long long y2){
        long long z=((x2-x1)*1ll*(x2-x1))+((y2-y1)*1ll*(y2-y1))-(r*r);
        if(z<=0)return true;
        return false;
    }
    int fun(int i,vector<vector<int>>&adj,int n){
        vector<bool> vis(n,false);
        vis[i]=true;
        queue<int> q;
        int ct=1;
        q.push(i);
        while(!q.empty()){
            int curr=q.front();
            q.pop();
            for(auto it:adj[curr]){
                if(vis[it])continue;
                vis[it]=true; ct++;
                q.push(it);
            }
        }

        return ct;
    }

    int maximumDetonation(vector<vector<int>>& bombs) {
        int n=bombs.size();
        vector<vector<int>> adj(n);
        for(int i=0;i<n;i++){
            int x=bombs[i][0];
            int y=bombs[i][1];
            int r=bombs[i][2];
            for(int j=0;j<n;j++){
                if(j==i)continue;
                int x2=bombs[j][0];
                int y2=bombs[j][1];
                if(isInside(x,y,r,x2,y2)) adj[i].push_back(j);
            }
        }
        int ans=1;
        for(int i=0;i<n;i++){
            ans=max(ans, fun(i,adj,n));
        }
    return ans;
        
    }
};