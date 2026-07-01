class Solution {
public:
    vector<int> dr={-1,0,1,0};
    vector<int> dc={0,-1,0,1};

    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n=grid.size();
        if(grid[0][0]==1 || grid[n-1][n-1]==1)return 0;

        vector<vector<int>> v(n,vector<int>(n,INT_MAX));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<>> pq1;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    v[i][j]=0; pq1.push({0,{i,j}});
                }
            }
        }

    while(!pq1.empty()){
        int d=pq1.top().first;
        int i=pq1.top().second.first;
        int j=pq1.top().second.second;
        pq1.pop();
        for(int k=0;k<4;k++){
            int ni=i+dr[k];
            int nj=j+dc[k];
            if(ni>=0 && ni<n && nj>=0 && nj<n && v[ni][nj]>1+d){
                v[ni][nj]=1+d;
                pq1.push({v[ni][nj],{ni,nj}});
            }
        }
    }

    priority_queue<vector<int>> pq;
vector<vector<int>> vis(n, vector<int>(n, 0));

pq.push({v[0][0], 0, 0});
vis[0][0] = 1;

while (!pq.empty()) {
    auto cur = pq.top();
    pq.pop();

    int safe = cur[0];
    int i = cur[1];
    int j = cur[2];

    if (i == n - 1 && j == n - 1)
        return safe;

    for (int k = 0; k < 4; k++) {
        int ni = i + dr[k];
        int nj = j + dc[k];

        if (ni >= 0 && ni < n && nj >= 0 && nj < n && !vis[ni][nj]) {
            vis[ni][nj] = 1;
            pq.push({min(safe, v[ni][nj]), ni, nj});
        }
    }
}

return 0;

    }
};