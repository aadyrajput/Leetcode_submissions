class Solution {
public:
    vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
        int ans1=0; int ans2=0;
        for(int i=0;i<mat.size(); i++){
            int ct=0;
            for(int j=0; j<mat[0].size(); j++){
                if(mat[i][j]==1) ct++;
            }
            if(ct>ans1){
                ans1=ct; ans2=i;
            }
        }

        vector<int> ans={ans2,ans1};
        return ans;
    }
};