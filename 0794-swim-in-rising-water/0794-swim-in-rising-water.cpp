class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
    int n=grid.size();
    vector<vector<int>> dist(n,vector<int>(n,1e8));    
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;
    dist[0][0]=grid[0][0];
    pq.push({dist[0][0],{0,0}});
    while(!pq.empty()){
        int d=pq.top().first;
        int x=pq.top().second.first;
        int y=pq.top().second.second;
        pq.pop();
        int delrow[4]={0,1,0,-1};
        int delcol[4]={1,0,-1,0};
        for(int i=0;i<4; i++){
            int nrow=x+delrow[i];
            int ncol=y+delcol[i];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<n){
                int xxx=max(d,grid[nrow][ncol]);
                if(dist[nrow][ncol]>xxx){
                    dist[nrow][ncol]=xxx;
                    pq.push({dist[nrow][ncol],{nrow,ncol}});
                }
            }
        }
    }
    return dist[n-1][n-1];
    }
};