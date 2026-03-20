class Solution {
public:
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> ans(m-k+1,vector<int>(n-k+1,0));

        for(int i=0;i<m-k+1; i++){
            for(int j=0;j<n-k+1; j++){
                set<int> st;
                for(int x=i; x<i+k; x++){
                    for(int y=j; y<j+k; y++){
                        st.insert(grid[x][y]);
                    }
                }
                if(st.size()==1){ans[i][j]=0; continue;}
                int diff=INT_MAX;
                vector<int> v;
                for(auto it:st)v.push_back(it);
                for(int ii=0;ii<v.size()-1; ii++){
                    diff=min(diff, abs(v[ii+1]-v[ii]));
                }
            ans[i][j]=diff;
            }
        }
    return ans;
    }
};