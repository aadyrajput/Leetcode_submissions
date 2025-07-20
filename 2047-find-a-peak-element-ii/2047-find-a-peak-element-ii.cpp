class Solution {
private:
int maxInCol(int mid,vector<vector<int>>mat){
    int m=mat.size(); int n=mat[0].size();
    int maxa=-1; int ind=-1;
    for(int i=0; i<m; i++){
        if(mat[i][mid]>maxa){
            maxa=mat[i][mid]; ind=i;
        }
    }
    return ind;
}
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
     int m=mat.size();  int n=mat[0].size();
     if(m==1 && n==1)return {0,0};
     int lo=0; int hi=n-1;
     while(lo<=hi){
        int mid=(lo+hi)/2;
        int row=maxInCol(mid,mat);
        int left=-1; int right=-1;
        if(mid>=1) left=mat[row][mid-1];
        if(mid<=n-2) right=mat[row][mid+1];
        if(mat[row][mid]>left && mat[row][mid]>right){
            return {row,mid};
        }
        else if(mat[row][mid]<left){
            hi=mid-1;
        }
        else lo=mid+1;
     }
    return {-1,-1};

    }
};