class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int dr[4]={-1,0,1,0};
        int dc[4]={0,-1,0,1};

        int m=grid.size(), n=grid[0].size();
        vector<vector<int>> v(m+1,vector<int>(n+1,1e9));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<>> pq;
        pq.push({grid[0][0],{0,0}});
        v[0][0]=grid[0][0];

        while(!pq.empty()){
            int dis=pq.top().first;
            int x=pq.top().second.first;
            int y=pq.top().second.second;
            pq.pop();
            for(int k=0;k<4;k++){
                int nx=x+dr[k];
                int ny=y+dc[k];
                if(nx>=0 && nx<m && ny>=0 && ny<n && v[nx][ny]>grid[nx][ny]+dis){
                    v[nx][ny]=grid[nx][ny]+dis;
                    pq.push({v[nx][ny],{nx,ny}});
                }
            }
        }

        if(v[m-1][n-1]<=health-1)return true;
        return false;
    }
};