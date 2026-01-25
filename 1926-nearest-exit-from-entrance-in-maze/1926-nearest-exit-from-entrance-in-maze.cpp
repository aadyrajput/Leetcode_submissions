class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int delrow[4]={-1,0,1,0};
        int delcol[4]={0,-1,0,1};
        int m=maze.size();
        int n=maze[0].size();
        vector<vector<int>> dist(m,vector<int>(n,1e9));
        dist[entrance[0]][entrance[1]]=0;
        vector<vector<bool>> vis(m,vector<bool>(n,false));
        vis[entrance[0]][entrance[1]]=true;
        queue<pair<int,pair<int,int>>> q;
        q.push({0,{entrance[0],entrance[1]}});
        int ct=0;
        while(!q.empty()){
            int x=q.front().second.first;
            int y=q.front().second.second;
            int dis=q.front().first;
            ct++;
            q.pop();
            if(ct!=1 && (x==0 || x==m-1 || y==0 || y==n-1)) return dis;
            for(int i=0;i<4;i++){
                int nrow=x+delrow[i];
                int ncol=y+delcol[i];
                if(nrow>=0 && ncol>=0 && nrow<m && ncol<n && maze[nrow][ncol]=='.'
                        && !vis[nrow][ncol]){
                    vis[nrow][ncol]=true;
                    dist[nrow][ncol]=dis+1;
                    q.push({dist[nrow][ncol],{nrow,ncol}});
                }
            }
        }
        return -1;
    }
};