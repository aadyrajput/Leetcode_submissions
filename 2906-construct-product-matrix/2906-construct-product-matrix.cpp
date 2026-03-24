class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        int M=12345;

     vector<vector<int>> ans(m,vector<int>(n,0));
     long long pre=1, suff=1;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                ans[i][j]=pre;
                pre=(pre*1ll*grid[i][j])%M;
            }
        }

        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                ans[i][j]=(ans[i][j]*1ll*suff)%M;
                suff=(suff*1ll*grid[i][j])%M;
            }
        }
        return ans;



    }
};