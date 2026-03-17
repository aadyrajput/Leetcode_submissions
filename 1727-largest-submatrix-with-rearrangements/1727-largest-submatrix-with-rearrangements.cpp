class Solution {
public:
    int largestSubmatrix(vector<vector<int>>& matrix) {
        int ans=0;
        int m=matrix.size();
        int n=matrix[0].size();
        for(int i=1;i<m; i++){
            for(int j=0;j<n; j++){
                if(matrix[i][j]==0)continue;
                matrix[i][j]+=matrix[i-1][j];
            }
        }

        for(int i=0;i<m; i++){
            sort(matrix[i].begin(),matrix[i].end(),greater<int>());
            for(int j=0;j<n; j++){
                int z=matrix[i][j]*1ll*(j+1);
                ans=max(ans,z);
            }
        }
        return ans;
        

    }
};