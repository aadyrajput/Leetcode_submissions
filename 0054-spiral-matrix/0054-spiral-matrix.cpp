class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        int p1=0; int p2=m-1; int p3=0; int p4=n-1;
        vector<int> ans;

        while(p1<=p2 && p3<=p4){
            for(int i=p3; i<=p4; i++){
                ans.push_back(matrix[p1][i]);
            }
            p1++;
            for(int i=p1; i<=p2; i++){
                ans.push_back(matrix[i][p4]);
            }
            p4--;

            if(p1<=p2){
                for(int i=p4; i>=p3; i--){
                    ans.push_back(matrix[p2][i]);
                }
                p2--;
            }
            if(p3<=p4){
                for(int i=p2; i>=p1; i--){
                       ans.push_back(matrix[i][p3]);
                }
                p3++;
            }

            }
        return ans;
    }
};