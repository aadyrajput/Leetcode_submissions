class Solution {
private:
bool binarySearch(int tar,vector<int> &v){
    int lo=0; int hi=v.size()-1;
    while(lo<=hi){
        int mid= lo+(hi-lo)/2;
        if(v[mid]==tar) return true;
        if(v[mid]<tar) lo=mid+1;
        else hi=mid-1;
    }
    return false;
}

public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m=matrix.size(); int n=matrix[0].size();
        for(int i=0; i<m; i++){
            if(matrix[i][0]<=target && target<=matrix[i][n-1]){
                return binarySearch(target,matrix[i]);
            }
        }
        return false;
    }
};