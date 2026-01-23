class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<>> pq;
        vector<vector<int>> dist(n,vector<int>(n,1e9));
        dist[0][0]=grid[0][0];
        pq.push({dist[0][0],{0,0}});
        int delrow[4]={-1,0,1,0};
        int delcol[4]={0,-1,0,1};
        while(!pq.empty()){
            int d=pq.top().first;
            int x=pq.top().second.first;
            int y=pq.top().second.second;
            pq.pop();
            for(int k=0;k<4;k++){
                int nrow=x+delrow[k];
                int ncol=y+delcol[k];
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<n){
                    int z=max(d,grid[nrow][ncol]);
                    if(z<dist[nrow][ncol]){
                        dist[nrow][ncol]=z;
                        pq.push({dist[nrow][ncol],{nrow,ncol}});
                    }       
                }
            }
        }
    return dist[n-1][n-1];
    }
};