class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> dist(m,vector<int>(n,1e9));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<>>pq;
        pq.push({grid[0][0],{0,0}});
        dist[0][0]=grid[0][0];

        int delrow[4]={-1,0,1,0};
        int delcol[4]={0,-1,0,1};
        while(!pq.empty()){
            int d=pq.top().first;
            int x=pq.top().second.first;
            int y=pq.top().second.second;
            pq.pop();
            for(int i=0;i<4;i++){
                int nrow=x+delrow[i];
                int ncol=y+delcol[i];
                if(nrow>=0 && ncol>=0 && nrow<m && ncol<n){
                     int newdist=grid[nrow][ncol]+d;
                     if(newdist<dist[nrow][ncol]){
                        dist[nrow][ncol]=newdist;
                        pq.push({newdist,{nrow,ncol}});
                     }
                }
            }
        }
    return dist[m-1][n-1];

    }
};