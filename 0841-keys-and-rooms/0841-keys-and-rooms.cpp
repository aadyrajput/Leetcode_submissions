class Solution {
void dfs(int x,vector<int>&vis,vector<vector<int>> &room){
    vis[x]=1;
    for(auto it:room[x]){
        if(vis[it]==1)continue;
        dfs(it,vis,room);
    }
}
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n=rooms.size();
        int ct=0;
        vector<int> vis(n,0);
        dfs(0,vis,rooms);
        for(int i=0;i<n; i++){
            if(vis[i]==1)ct++;
        }
        if(ct==n)return true;
        return false;
    }
};