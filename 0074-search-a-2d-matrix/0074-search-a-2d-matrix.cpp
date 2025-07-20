class Solution {

public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size(); int n=matrix[0].size();
      int lo=0; int hi=m*n-1;
      while(lo<=hi){
            int mid= lo+(hi-lo)/2;
            int i=(mid/n);
            int j=mid%n;
            if(matrix[i][j]==target)return true;
            if(target>matrix[i][j]) lo=mid+1;
            else hi=mid-1;
      }
        return false;
    }
};