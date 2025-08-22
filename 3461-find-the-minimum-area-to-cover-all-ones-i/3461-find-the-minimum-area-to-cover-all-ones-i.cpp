class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int rmin=INT_MAX; int rmax=INT_MIN;
        int cmin=INT_MAX; int cmax=INT_MIN;

        for(int i=0;i<grid.size(); i++){
            for(int j=0;j<grid[0].size(); j++){
                if(grid[i][j]==1){
                rmin=min(rmin,i); rmax=max(rmax,i);
                cmin=min(cmin,j); cmax=max(cmax,j);
            }
        }
        }
        if(rmin==INT_MAX){
            return 0;
        }
        int ans1=(rmax-rmin+1);
        int ans2=(cmax-cmin+1);
        return ans1*ans2;
    }
};